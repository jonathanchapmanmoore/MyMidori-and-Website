/* ****************************************************************************
 *
 * Copyright (c) Microsoft Corporation. 
 *
 * This source code is subject to terms and conditions of the Apache License, Version 2.0. A 
 * copy of the license can be found in the License.html file at the root of this distribution. If 
 * you cannot locate the  Apache License, Version 2.0, please send an email to 
 * dlr@microsoft.com. By using this source code in any fashion, you are agreeing to be bound 
 * by the terms of the Apache License, Version 2.0.
 *
 * You must not remove this notice, or any other, from this software.
 *
 *
 * ***************************************************************************/

#if !SILVERLIGHT // ComObject

#if !CLR2
using System.Linq.Expressions;
#else
using Microsoft.Scripting.Ast;
#endif

using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace Microsoft.Scripting.ComInterop {

    /// <summary>
    /// VariantBuilder handles packaging of arguments into a Variant for a call to IDispatch.Invoke
    /// </summary>
    internal class VariantBuilder {

        private MemberExpression _variant;
        private readonly ArgBuilder _argBuilder;
        private readonly VarEnum _targetComType;
        internal ParameterExpression TempVariable { get; private set; }

        internal VariantBuilder(VarEnum targetComType, ArgBuilder builder) {
            _targetComType = targetComType;
            _argBuilder = builder;
        }

        internal bool IsByRef {
            get { return (_targetComType & VarEnum.VT_BYREF) != 0; }
        }

        internal Expression InitializeArgumentVariant(MemberExpression variant, Expression parameter) {
            //NOTE: we must remember our variant
            //the reason is that argument order does not map exactly to the order of variants for invoke
            //and when we are doing clean-up we must be sure we are cleaning the variant we have initialized.

            _variant = variant;

            if (IsByRef) {
                // temp = argument
                // paramVariants._elementN.SetAsByrefT(ref temp)
                Debug.Assert(TempVariable == null);
                var argExpr = _argBuilder.MarshalToRef(parameter);
                
                TempVariable = Expression.Variable(argExpr.Type, null);
                return Expression.Block(
                    Expression.Assign(TempVariable, argExpr),
                    Expression.Call(
                        variant,
                        Variant.GetByrefSetter(_targetComType & ~VarEnum.VT_BYREF),
                        TempVariable
                    )
                );
            }

            Expression argument = _argBuilder.Marshal(parameter);

            // we are forced to special case ConvertibleArgBuilder since it does not have 
            // a corresponding _targetComType.
            if (_argBuilder is ConvertibleArgBuilder) {
                return Expression.Call(
                    variant,
                    typeof(Variant).GetMethod("SetAsIConvertible"),
                    argument
                );
            }

            if (Variant.IsPrimitiveType(_targetComType) ||
               (_targetComType == VarEnum.VT_DISPATCH) ||
               (_targetComType == VarEnum.VT_UNKNOWN) ||
               (_targetComType == VarEnum.VT_VARIANT) ||
               (_targetComType == VarEnum.VT_RECORD) ||
               (_targetComType == VarEnum.VT_ARRAY)){
                // paramVariants._elementN.AsT = (cast)argN
                return Expression.Assign(
                    Expression.Property(
                        variant,
                        Variant.GetAccessor(_targetComType)
                    ),
                    argument
                );
            }

            switch (_targetComType) {
                case VarEnum.VT_EMPTY:
                    return null;

                case VarEnum.VT_NULL:
                    // paramVariants._elementN.SetAsNull();
                    return Expression.Call(variant, typeof(Variant).GetMethod("SetAsNull"));

                default:
                    Debug.Assert(false, "Unexpected VarEnum");
                    return null;
            }
        }

        private static Expression Release(Expression pUnk) {
            return Expression.Call(typeof(UnsafeMethods).GetMethod("IUnknownReleaseNotZero"), pUnk);
        }

        internal Expression Clear() {
            if (IsByRef) {
                if (_argBuilder is StringArgBuilder) {
                    Debug.Assert(TempVariable != null);
                    return Expression.Call(typeof(Marshal).GetMethod("FreeBSTR"), TempVariable);
                } else if (_argBuilder is DispatchArgBuilder) {
                    Debug.Assert(TempVariable != null);
                    return Release(TempVariable);
                } else if (_argBuilder is UnknownArgBuilder) {
                    Debug.Assert(TempVariable != null);
                    return Release(TempVariable);
                } else if (_argBuilder is VariantArgBuilder) {
                    Debug.Assert(TempVariable != null);
                    return Expression.Call(TempVariable, typeof(Variant).GetMethod("Clear"));
                }
                return null;
            }


            switch (_targetComType) {
                case VarEnum.VT_EMPTY:
                case VarEnum.VT_NULL:
                    return null;

                case VarEnum.VT_BSTR:
                case VarEnum.VT_UNKNOWN:
                case VarEnum.VT_DISPATCH:
                case VarEnum.VT_ARRAY:
                case VarEnum.VT_RECORD:
                case VarEnum.VT_VARIANT:
                    // paramVariants._elementN.Clear()
                    return Expression.Call(_variant, typeof(Variant).GetMethod("Clear"));

                default:
                    Debug.Assert(Variant.IsPrimitiveType(_targetComType), "Unexpected VarEnum");
                    return null;
            }
        }

        internal Expression UpdateFromReturn(Expression parameter) {
            if (TempVariable == null) {
                return null;
            }
            return Expression.Assign(
                parameter,
                Helpers.Convert(
                    _argBuilder.UnmarshalFromRef(TempVariable),
                    parameter.Type
                )
            );
        }
    }
}

#endif
