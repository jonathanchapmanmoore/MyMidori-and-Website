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

using System;
using System.Runtime.CompilerServices;
using System.Runtime.ConstrainedExecution;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;

using IronPython.Runtime;

#if !SILVERLIGHT

namespace IronPython.Modules {
    /// <summary>
    /// A wrapper around allocated memory to ensure it gets released and isn't accessed
    /// when it could be finalized.
    /// </summary>
    internal sealed class MemoryHolder : CriticalFinalizerObject {
        private readonly IntPtr _data;
        private readonly bool _ownsData;
        private readonly MemoryHolder _parent;
        private readonly int _size;
        private PythonDictionary _objects;

        /// <summary>
        /// Creates a new MemoryHolder and allocates a buffer of the specified size.
        /// </summary>
        [ReliabilityContract(Consistency.WillNotCorruptState, Cer.MayFail)]
        public MemoryHolder(int size) {
            RuntimeHelpers.PrepareConstrainedRegions();
            try {
            } finally {
                _size = size;
                _data = NativeFunctions.Calloc(new IntPtr(size));
                if (_data == IntPtr.Zero) {
                    GC.SuppressFinalize(this);
                    throw new OutOfMemoryException();
                }
                _ownsData = true;
            }
        }

        /// <summary>
        /// Creates a new MemoryHolder at the specified address which is not tracked
        /// by us and we will never free.
        /// </summary>
        public MemoryHolder(IntPtr data, int size) {
            GC.SuppressFinalize(this);
            _data = data;
            _size = size;
        }

        /// <summary>
        /// Creates a new MemoryHolder at the specified address which will keep alive the 
        /// parent memory holder.
        /// </summary>
        public MemoryHolder(IntPtr data, int size, MemoryHolder parent) {
            GC.SuppressFinalize(this);
            _data = data;
            _parent = parent;
            _objects = parent._objects;
            _size = size;
        }

        /// <summary>
        /// Gets the address of the held memory.  The caller should ensure the MemoryHolder
        /// is always alive as long as the address will continue to be accessed.
        /// </summary>
        public IntPtr UnsafeAddress {
            get {
                return _data;
            }
        }

        public int Size {
            get {
                return _size;
            }
        }

        /// <summary>
        /// Gets a list of objects which need to be kept alive for this MemoryHolder to be 
        /// remain valid.
        /// </summary>
        public PythonDictionary Objects {
            get {
                return _objects;
            }
            set {
                _objects = value;
            }
        }

        internal PythonDictionary EnsureObjects() {
            if (_objects == null) {
                Interlocked.CompareExchange(ref _objects, new PythonDictionary(), null);
            }

            return _objects;
        }

        /// <summary>
        /// Used to track the lifetime of objects when one memory region depends upon
        /// another memory region.  For example if you have an array of objects that
        /// each have an element which has it's own lifetime the array needs to keep
        /// the individual elements alive.
        /// 
        /// The keys used here match CPython's keys as tested by CPython's test_ctypes. 
        /// Typically they are a string which is the array index, "ffffffff" when
        /// from_buffer is used, or when it's a simple type there's just a string
        /// instead of the full dictionary - we store that under the key "str".
        /// </summary>
        internal void AddObject(object key, object value) {
            EnsureObjects()[key] = value;
        }

        public byte ReadByte(int offset) {
            byte res = Marshal.ReadByte(_data, offset);
            GC.KeepAlive(this);
            return res;
        }

        public short ReadInt16(int offset) {
            short res = Marshal.ReadInt16(_data, offset);
            GC.KeepAlive(this);
            return res;
        }

        public int ReadInt32(int offset) {
            int res = Marshal.ReadInt32(_data, offset);
            GC.KeepAlive(this);
            return res;
        }

        public long ReadInt64(int offset) {
            long res = Marshal.ReadInt64(_data, offset);
            GC.KeepAlive(this);
            return res;
        }

        public IntPtr ReadIntPtr(int offset) {
            IntPtr res = Marshal.ReadIntPtr(_data, offset);
            GC.KeepAlive(this);
            return res;
        }

        public MemoryHolder ReadMemoryHolder(int offset) {
            IntPtr res = Marshal.ReadIntPtr(_data, offset);
            return new MemoryHolder(res, IntPtr.Size, this);
        }

        internal string ReadAnsiString(int offset) {
            try {
                return Marshal.PtrToStringAnsi(_data.Add(offset));
            } finally {
                GC.KeepAlive(this);
            }
        }

        internal string ReadUnicodeString(int offset) {
            try {
                return Marshal.PtrToStringUni(_data.Add(offset));
            } finally {
                GC.KeepAlive(this);
            }
        }

        internal string ReadAnsiString(int offset, int length) {
            try {
                return ReadAnsiString(_data, offset, length);
            } finally {
                GC.KeepAlive(this);
            }
        }

        internal static string ReadAnsiString(IntPtr addr, int offset, int length) {
            // instead of Marshal.PtrToStringAnsi we do this because
            // ptrToStringAnsi gives special treatment to values >= 128.
            StringBuilder res = new StringBuilder();
            if (checked(offset + length) < Int32.MaxValue) {
                for (int i = 0; i < length; i++) {
                    res.Append((char)Marshal.ReadByte(addr, offset + i));
                }
            }
            return res.ToString();
        }

        internal static string ReadAnsiString(IntPtr addr, int offset) {
            // instead of Marshal.PtrToStringAnsi we do this because
            // ptrToStringAnsi gives special treatment to values >= 128.
            StringBuilder res = new StringBuilder();
            byte b;
            while((b = Marshal.ReadByte(addr, offset++)) != 0) {
                res.Append((char)b);
            }
            return res.ToString();
        }

        internal string ReadUnicodeString(int offset, int length) {
            try {
                return Marshal.PtrToStringUni(_data.Add(offset), length);
            } finally {
                GC.KeepAlive(this);
            }
        }

        public void WriteByte(int offset, byte value) {
            Marshal.WriteByte(_data, offset, value);
            GC.KeepAlive(this);
        }

        public void WriteInt16(int offset, short value) {
            Marshal.WriteInt16(_data, offset, value);
            GC.KeepAlive(this);
        }

        public void WriteInt32(int offset, int value) {
            Marshal.WriteInt32(_data, offset, value);
            GC.KeepAlive(this);
        }

        public void WriteInt64(int offset, long value) {
            Marshal.WriteInt64(_data, offset, value);
            GC.KeepAlive(this);
        }

        public void WriteIntPtr(int offset, IntPtr value) {
            Marshal.WriteIntPtr(_data, offset, value);
            GC.KeepAlive(this);
        }

        public void WriteIntPtr(int offset, MemoryHolder address) {
            Marshal.WriteIntPtr(_data, offset, address.UnsafeAddress);
            GC.KeepAlive(this);
            GC.KeepAlive(address);
        }


        /// <summary>
        /// Copies the data in data into this MemoryHolder.
        /// </summary>
        public void CopyFrom(IntPtr source, IntPtr size) {
            NativeFunctions.CopyMemory(_data, source, size);
            GC.KeepAlive(this);
        }

        internal void WriteUnicodeString(int offset, string value) {
            // TODO: There's gotta be a better way to do this
            for (int i = 0; i < value.Length; i++) {
                WriteInt16(checked(offset + i * 2), (short)value[i]);
            }
        }

        internal void WriteAnsiString(int offset, string value) {
            // TODO: There's gotta be a better way to do this
            for (int i = 0; i < value.Length; i++) {
                WriteByte(checked(offset + i), (byte)value[i]);
            }
        }

        public MemoryHolder GetSubBlock(int offset) {
            // No GC.KeepAlive here because the new MemoryHolder holds onto the previous one.
            return new MemoryHolder(_data.Add(offset), _size - offset, this);
        }

        /// <summary>
        /// Copies memory from one location to another keeping the associated memory holders alive during the
        /// operation.
        /// </summary>
        public void CopyTo(MemoryHolder/*!*/ destAddress, int writeOffset, int size) {
            NativeFunctions.CopyMemory(destAddress._data.Add(writeOffset), _data, new IntPtr(size));
            GC.KeepAlive(destAddress);
            GC.KeepAlive(this);
        }

        [ReliabilityContract(Consistency.WillNotCorruptState, Cer.Success)]
        ~MemoryHolder() {
            if (_ownsData) {
                Marshal.FreeHGlobal(_data);
            }
        }
    }
}

#endif
