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

using System.Dynamic;
using System.Threading;
using Microsoft.Scripting.Runtime;

namespace IronPython.Runtime.Types {

    [PythonType("ellipsis"), Documentation(null)]
    public class Ellipsis : ICodeFormattable {
        private static Ellipsis _instance;
        
        private Ellipsis() { }
        
        internal static Ellipsis Value {
            get {
                if (_instance == null) {
                    Interlocked.CompareExchange(ref _instance, new Ellipsis(), null);
                }
                return _instance;
            }
        }

        #region ICodeFormattable Members

        public string/*!*/ __repr__(CodeContext/*!*/ context) {
            return "Ellipsis";
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1822:MarkMembersAsStatic")]
        public int __hash__() {
            return 0x1e1a6208;
        }

        #endregion
    }

    [PythonType("NotImplementedType"), Documentation(null)]
    public class NotImplementedType : ICodeFormattable {
        private static NotImplementedType _instance;
        
        private NotImplementedType() { }
        
        internal static NotImplementedType Value {
            get {
                if (_instance == null) {
                    Interlocked.CompareExchange(ref _instance, new NotImplementedType(), null);
                }
                return _instance;
            }
        }

        #region ICodeFormattable Members

        public string/*!*/ __repr__(CodeContext/*!*/ context) {
            return "NotImplemented";
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1822:MarkMembersAsStatic")]
        public int __hash__() {
            return 0x1e1a1e98;
        }

        #endregion
    }

    public class NoneTypeOps {
        internal const int NoneHashCode = 0x1e1a2e40;

        public static int __hash__(DynamicNull self) {
            return NoneHashCode;
        }

        public static readonly string __doc__;

        public static string __repr__(DynamicNull self) {
            return "None";
        }
    }
}
