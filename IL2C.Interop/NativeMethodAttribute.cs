/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections;

namespace System.Runtime.InteropServices
{
    [AttributeUsage(AttributeTargets.Method, AllowMultiple=false, Inherited=false)]
    public sealed class NativeMethodAttribute : NativeAttribute
    {
        public NativeMethodAttribute(string includeFileName)
            : base(includeFileName)
        {
        }

        internal NativeMethodAttribute(object arg0, IDictionary props)
            : base(arg0, props)
        {
            this.LibraryFileName = (string)props["LibraryFileName"];
            var charSet = props["CharSet"];
            if (charSet is NativeCharSet) this.CharSet = (NativeCharSet)charSet;
        }

        public string LibraryFileName { get; set; }
        public NativeCharSet CharSet { get; set; }
    }
}
