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

#if !CLR2
using System.Linq.Expressions;
#else
using Microsoft.Scripting.Ast;
#endif

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Dynamic;

using Microsoft.Scripting;
using Microsoft.Scripting.Actions;
using Microsoft.Scripting.Actions.Calls;
using Microsoft.Scripting.Runtime;
using Microsoft.Scripting.Utils;

using IronPython.Runtime.Operations;

using AstUtils = Microsoft.Scripting.Ast.Utils;

namespace IronPython.Runtime.Binding {
    /// <summary>
    /// Fallback action for performing an invoke from Python.  We translate the
    /// CallSignature which supports splatting position and keyword args into
    /// their expanded form.
    /// </summary>
    class CompatibilityInvokeBinder : InvokeBinder, IPythonSite {
        private readonly PythonContext/*!*/ _context;

        public CompatibilityInvokeBinder(PythonContext/*!*/ context, CallInfo /*!*/ callInfo)
            : base(callInfo) {
            _context = context;
        }

        public override DynamicMetaObject/*!*/ FallbackInvoke(DynamicMetaObject target, DynamicMetaObject/*!*/[]/*!*/ args, DynamicMetaObject errorSuggestion) {
            if (target.Value is IDynamicMetaObjectProvider && errorSuggestion == null) {
                // try creating an instance...
                return target.BindCreateInstance(
                    _context.Create(this, CallInfo),
                    args
                );
            }

#if !SILVERLIGHT
            DynamicMetaObject com;
            if (Microsoft.Scripting.ComInterop.ComBinder.TryBindInvoke(this, target, BindingHelpers.GetComArguments(args), out com)) {
                return com;
            }
#endif

            return InvokeFallback(target, args, BindingHelpers.CallInfoToSignature(CallInfo), errorSuggestion);
        }

        internal DynamicMetaObject/*!*/ InvokeFallback(DynamicMetaObject/*!*/ target, DynamicMetaObject/*!*/[]/*!*/ args, CallSignature sig, DynamicMetaObject errorSuggestion) {
            return
                PythonProtocol.Call(this, target, args) ??
                Context.Binder.Create(sig, target, args, AstUtils.Constant(_context.SharedContext)) ??
                Context.Binder.Call(sig, errorSuggestion, new PythonOverloadResolverFactory(Context.Binder, AstUtils.Constant(_context.SharedContext)), target, args);
        }

        public override int GetHashCode() {
            return base.GetHashCode() ^ _context.Binder.GetHashCode();
        }

        public override bool Equals(object obj) {
            CompatibilityInvokeBinder ob = obj as CompatibilityInvokeBinder;
            if (ob == null) {
                return false;
            }

            return ob._context.Binder == _context.Binder && base.Equals(obj);
        }

        #region IPythonSite Members

        public PythonContext/*!*/ Context {
            get { return _context; }
        }

        #endregion
    }
}
