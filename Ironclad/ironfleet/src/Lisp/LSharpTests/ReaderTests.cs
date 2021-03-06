#region Copyright (c) 2008, Rob Blackwell.  All rights reserved.
// Software License Agreement (BSD License)

// Copyright (c) 2008, Rob Blackwell.  All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:

//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.

//   * Redistributions in binary form must reproduce the above
//     copyright notice, this list of conditions and the following
//     disclaimer in the documentation and/or other materials
//     provided with the distribution.

// THIS SOFTWARE IS PROVIDED BY THE AUTHOR 'AS IS' AND ANY EXPRESSED
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#endregion

using System.IO;
using LSharp;
using NUnit.Framework;

namespace LSharpTests
{
    [TestFixture]
    public class ReaderTests
    {
        [Test]
        public void Integer()
        {
            Reader reader = new Reader();
            object actual = Reader.Read(new StringReader("1"));
            Assert.AreEqual(1, actual);

        }

        [Test]
        public void Double()
        {
            Reader reader = new Reader();
            object actual = Reader.Read(new StringReader("1.1"));
            Assert.AreEqual(1.1, actual);

        }

        [Test]
        public void String()
        {
            Reader reader = new Reader();
            object actual = Reader.Read(new StringReader("\"Hello\""));
            Assert.AreEqual("Hello", actual);

        }

        [Test]
        public void Array()
        {
            Reader reader = new Reader();
            object actual = Reader.Read(new StringReader("[1 2 3]"));
            Assert.IsInstanceOfType(typeof(object[]), actual);

        }
    }
}
