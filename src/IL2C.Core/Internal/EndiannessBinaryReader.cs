////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System;
using System.IO;
using System.Text;

namespace IL2C.Internal
{
    internal enum EndianSpecific
    {
        Host,
        Little,
        Big
    }

    internal class EndiannessBinaryReader : BinaryReader
    {
        private readonly bool ignore;

        public EndiannessBinaryReader(Stream stream, EndianSpecific endian)
            : this(stream, endian, Encoding.UTF8, false)
        {
        }

        public EndiannessBinaryReader(Stream stream, EndianSpecific endian, Encoding encoding)
            : this(stream, endian, encoding, false)
        {
        }

        public EndiannessBinaryReader(Stream stream, EndianSpecific endian, Encoding encoding, bool leaveOpen)
            : base(stream, encoding, leaveOpen)
        {
            switch (endian)
            {
                case EndianSpecific.Host:
                    ignore = true;
                    break;
                case EndianSpecific.Little:
                    ignore = BitConverter.IsLittleEndian;
                    break;
                case EndianSpecific.Big:
                    ignore = !BitConverter.IsLittleEndian;
                    break;
            }
        }

        public bool IsEOF =>
            this.BaseStream.Position >= this.BaseStream.Length;

        public override short ReadInt16()
        {
            if (ignore)
            {
                return base.ReadInt16();
            }

            var data = base.ReadBytes(sizeof(short));
            Array.Reverse(data);
            return BitConverter.ToInt16(data, 0);
        }

        public override int ReadInt32()
        {
            if (ignore)
            {
                return base.ReadInt32();
            }

            var data = base.ReadBytes(sizeof(int));
            Array.Reverse(data);
            return BitConverter.ToInt32(data, 0);
        }

        public override long ReadInt64()
        {
            if (ignore)
            {
                return base.ReadInt64();
            }

            var data = base.ReadBytes(sizeof(long));
            Array.Reverse(data);
            return BitConverter.ToInt64(data, 0);
        }

        public override ushort ReadUInt16()
        {
            if (ignore)
            {
                return base.ReadUInt16();
            }

            var data = base.ReadBytes(sizeof(ushort));
            Array.Reverse(data);
            return BitConverter.ToUInt16(data, 0);
        }

        public override uint ReadUInt32()
        {
            if (ignore)
            {
                return base.ReadUInt32();
            }

            var data = base.ReadBytes(sizeof(uint));
            Array.Reverse(data);
            return BitConverter.ToUInt32(data, 0);
        }

        public override ulong ReadUInt64()
        {
            if (ignore)
            {
                return base.ReadUInt64();
            }

            var data = base.ReadBytes(sizeof(ulong));
            Array.Reverse(data);
            return BitConverter.ToUInt64(data, 0);
        }

        public override float ReadSingle()
        {
            if (ignore)
            {
                return base.ReadSingle();
            }

            var data = base.ReadBytes(sizeof(float));
            Array.Reverse(data);
            return BitConverter.ToSingle(data, 0);
        }

        public override double ReadDouble()
        {
            if (ignore)
            {
                return base.ReadDouble();
            }

            var data = base.ReadBytes(sizeof(double));
            Array.Reverse(data);
            return BitConverter.ToDouble(data, 0);
        }

        public override decimal ReadDecimal()
        {
            if (ignore)
            {
                return base.ReadDecimal();
            }

            var bits = new int[4];
            bits[0] = this.ReadInt32();
            bits[1] = this.ReadInt32();
            bits[2] = this.ReadInt32();
            bits[3] = this.ReadInt32();
            return new decimal(bits);
        }
    }
}
