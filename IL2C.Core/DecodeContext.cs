using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Diagnostics;
using System.Linq;
using System.Reflection;

namespace IL2C
{
    internal struct StackInformation
    {
        public readonly string SymbolName;
        public readonly Type TargetType;

        public StackInformation(string symbolName, Type targetType)
        {
            this.SymbolName = symbolName;
            this.TargetType = targetType;
        }

        public bool Equals(StackInformation rhs)
        {
            return this.SymbolName.Equals(rhs.SymbolName) && this.TargetType.Equals(rhs.TargetType);
        }

        public override bool Equals(object rhs)
        {
            if (rhs is StackInformation)
            {
                return this.Equals((StackInformation)rhs);
            }
            else
            {
                return false;
            }
        }
    }

    internal sealed class DecodeContext
    {
        #region Private types
        private sealed class StackInformations
        {
            private readonly List<StackInformation> stackInformations;
            private readonly int position;
            private int stackInformationPosition = -1;

            private StackInformations(int position, List<StackInformation> stackInformations)
            {
                this.position = position;
                this.stackInformations = stackInformations;
            }

            public StackInformations(int stackPosition)
                : this(stackPosition, new List<StackInformation>())
            {
            }

            public string GetOrAdd(Type targetType)
            {
                var index = stackInformations.FindIndex(si => si.TargetType == targetType);
                if (index >= 0)
                {
                    stackInformationPosition = index;
                    return stackInformations[index].SymbolName;
                }

                var symbolName = string.Format(
                    "__stack{0}_{1}",
                    position,
                    Utilities.GetCLanguageTypeName(targetType));

                var stackInformation = new StackInformation(symbolName, targetType);
                stackInformationPosition = stackInformations.Count;
                stackInformations.Add(stackInformation);

                return symbolName;
            }

            public StackInformation GetCurrent()
            {
                Debug.Assert(stackInformationPosition >= 0);
                Debug.Assert(stackInformations.Any());

                return stackInformations[stackInformationPosition];
            }

            public IEnumerable<StackInformation> ExtractStacks()
            {
                return stackInformations;
            }
        }

        private struct BranchTargetInformation
        {
            public readonly int TargetIndex;
            public readonly StackInformation[] StackInformationsSnapshot;

            public BranchTargetInformation(
                int index,
                int stackInformationsPosition,
                List<StackInformations> stackInformationsList)
            {
                this.TargetIndex = index;
                this.StackInformationsSnapshot = stackInformationsList
                    .Take(stackInformationsPosition)
                    .Select(stackInformationList => stackInformationList.GetCurrent())
                    .ToArray();
            }
        }
        #endregion

        #region Fields
        public readonly string MethodName;
        public readonly ParameterInfo[] Parameters;
        public readonly IList<LocalVariableInfo> Locals;

        private readonly byte[] ilBytes;
        private int targetIndex = -1;

        private int pathNumber = 0;
        private readonly int[] decodedPathNumbers;

        private readonly List<StackInformations> stackInformationsList = new List<StackInformations>();
        private int stackInformationsPosition = -1;
        private readonly Queue<BranchTargetInformation> pathRemains = new Queue<BranchTargetInformation>();
        #endregion

        public DecodeContext(
            string methodName,
            ParameterInfo[] parameters,
            IList<LocalVariableInfo> locals,
            byte[] ilBytes)
        {
            if (ilBytes.Length == 0)
            {
                throw new InvalidProgramSequenceException(
                    "Method body is empty: MethodName={0}",
                    methodName);
            }

            this.MethodName = methodName;
            this.Parameters = parameters;
            this.Locals = locals;

            this.ilBytes = ilBytes;
            this.decodedPathNumbers = new int[ilBytes.Length];

            // First valid process is TryDequeueNextPath.
            this.pathRemains.Enqueue(new BranchTargetInformation(0, 0, new List<StackInformations>()));
        }

        #region Decode
        public bool TryDecode(out ILConverter ilc)
        {
            Debug.Assert(pathNumber >= 1);
            Debug.Assert(stackInformationsList != null);
            Debug.Assert(stackInformationsPosition >= 0);

            // Finish if current position already decoded.
            if (decodedPathNumbers[targetIndex] >= 1)
            {
                ilc = null;
                return false;
            }

            decodedPathNumbers[targetIndex] = pathNumber;

            // Decode next bytes.
            var byte0 = ilBytes[targetIndex];
            if (Utilities.TryGetILConverter(byte0, out ilc))
            {
                targetIndex++;
                return true;
            }

            if (targetIndex >= ilBytes.Length)
            {
                throw new InvalidProgramSequenceException(
                    "End of method body reached: MethodName={0}",
                    this.MethodName);
            }

            targetIndex++;

            var byte1 = ilBytes[targetIndex];
            var word = (ushort)(byte0 << 8 | byte1);
            if (Utilities.TryGetILConverter(word, out ilc))
            {
                targetIndex++;
                return true;
            }

            throw new InvalidProgramSequenceException(
                "Invalid opcode: MethodName={0}, OpCode={1:X2}, CurrentIndex={2}",
                this.MethodName,
                byte0,
                targetIndex);
        }
        #endregion

        #region Fetch
        public byte FetchByte()
        {
            Debug.Assert(pathNumber >= 1);
            Debug.Assert(stackInformationsList != null);
            Debug.Assert(stackInformationsPosition >= 0);

            if (targetIndex >= ilBytes.Length)
            {
                throw new InvalidProgramSequenceException(
                    "End of method body reached: MethodName={0}",
                    this.MethodName);
            }

            return ilBytes[targetIndex++];
        }

        public ushort FetchUInt16()
        {
            Debug.Assert(pathNumber >= 1);
            Debug.Assert(stackInformationsList != null);
            Debug.Assert(stackInformationsPosition >= 0);

            var byte0 = this.FetchByte();
            var byte1 = this.FetchByte();
            return (ushort)((((ushort)byte1) << 8) | byte0);
        }

        public uint FetchUInt32()
        {
            Debug.Assert(pathNumber >= 1);
            Debug.Assert(stackInformationsList != null);
            Debug.Assert(stackInformationsPosition >= 0);

            var ushort0 = this.FetchUInt16();
            var ushort1 = this.FetchUInt16();
            return (uint)((((uint)ushort1) << 16) | ushort0);
        }

        public int FetchInt32()
        {
            return (int)this.FetchUInt32();
        }

        public ulong FetchUInt64()
        {
            Debug.Assert(pathNumber >= 1);
            Debug.Assert(stackInformationsList != null);
            Debug.Assert(stackInformationsPosition >= 0);

            var uint0 = this.FetchUInt32();
            var uint1 = this.FetchUInt32();
            return (ulong)((((ulong)uint1) << 32) | uint0);
        }

        public long FetchInt64()
        {
            return (long)this.FetchUInt64();
        }
        #endregion

        #region TargetIndex
        public int TargetIndex => targetIndex;

        private static string MakeLabel(int targetIndex)
        {
            return string.Format("L_{0:X4}", targetIndex);
        }

        public string MakeLabel()
        {
            return MakeLabel(this.TargetIndex);
        }

        public void TransferIndex(int offset)
        {
            var newIndex = targetIndex + offset;
            this.SetIndex(newIndex);
        }

        public void SetIndex(int newIndex)
        {
            Debug.Assert(pathNumber >= 1);
            Debug.Assert(stackInformationsList != null);
            Debug.Assert(stackInformationsPosition >= 0);

            if ((newIndex >= this.ilBytes.Length) || (newIndex < 0))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid branch target: Method={0}, Target={1}, CurrentIndex={2}",
                    this.MethodName,
                    newIndex,
                    targetIndex);
            }

            targetIndex = newIndex;
        }
        #endregion

        #region Stack
        public string PushStack(Type targetType)
        {
            Debug.Assert(pathNumber >= 1);
            Debug.Assert(stackInformationsList != null);
            Debug.Assert(stackInformationsPosition >= 0);

            StackInformations stackInformations;
            if (stackInformationsPosition >= stackInformationsList.Count)
            {
                stackInformations = new StackInformations(stackInformationsPosition);
                stackInformationsList.Add(stackInformations);
            }
            else
            {
                stackInformations = stackInformationsList[stackInformationsPosition];
            }

            stackInformationsPosition++;

            return stackInformations.GetOrAdd(targetType);
        }

        public StackInformation PopStack()
        {
            Debug.Assert(pathNumber >= 1);
            Debug.Assert(stackInformationsList != null);
            Debug.Assert(stackInformationsPosition >= 0);

            if (stackInformationsPosition <= 0)
            {
                throw new InvalidProgramSequenceException(
                    "Evaluation stack underflow: Method={0}, CurrentIndex={1}",
                    this.MethodName,
                    targetIndex);
            }

            stackInformationsPosition--;
            return stackInformationsList[stackInformationsPosition].GetCurrent();
        }
        #endregion

        #region Path
        public string EnqueueNewPath(int offset)
        {
            Debug.Assert(pathNumber >= 1);
            Debug.Assert(stackInformationsList != null);
            Debug.Assert(stackInformationsPosition >= 0);

            pathRemains.Enqueue(new BranchTargetInformation(
                offset, stackInformationsPosition, stackInformationsList));

            return MakeLabel(offset);
        }

        public bool TryDequeueNextPath()
        {
            // Finish if remains path is empty.
            while (pathRemains.Count >= 1)
            {
                // Get queued branch target.
                var branchTarget = pathRemains.Dequeue();

                // If current position already decoded:
                if (decodedPathNumbers[branchTarget.TargetIndex] >= 1)
                {
                    // Skip if stack information equals.
                    var currentStacks = stackInformationsList
                        .Take(stackInformationsPosition)
                        .Select(si => si.GetCurrent());
                    var branchTargetStacks = branchTarget.StackInformationsSnapshot;
                    if (currentStacks.SequenceEqual(branchTargetStacks))
                    {
                        continue;
                    }
                }

                // Start next path.
                pathNumber++;
                targetIndex = branchTarget.TargetIndex;

                // Retreive stack informations.
                for (var index = 0;
                    index < branchTarget.StackInformationsSnapshot.Length;
                    index++)
                {
                    stackInformationsList[index].GetOrAdd(
                        branchTarget.StackInformationsSnapshot[index].TargetType);
                }
                stackInformationsPosition = branchTarget.StackInformationsSnapshot.Length;

                return true;
            }

            targetIndex = -1;
            return false;
        }
        #endregion

        public IEnumerable<StackInformation> ExtractStacks()
        {
            return stackInformationsList
                .SelectMany(stackInformations => stackInformations.ExtractStacks());
        }
    }
}
