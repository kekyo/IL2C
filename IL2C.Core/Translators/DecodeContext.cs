using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil;
using Mono.Cecil.Cil;

namespace IL2C.Translators
{
    internal sealed class DecodeContext
    {
        #region Private types
        private sealed class StackInformationHolder
        {
            private readonly List<SymbolInformation> typedStackInformation;
            private readonly int stackPointer;
            private int selectedStackInformation = -1;

            private StackInformationHolder(
                int stackPointer, List<SymbolInformation> typedStackInformation)
            {
                this.stackPointer = stackPointer;
                this.typedStackInformation = typedStackInformation;
            }

            public StackInformationHolder(int stackPointer)
                : this(stackPointer, new List<SymbolInformation>())
            {
            }

            public string GetOrAdd(TypeReference targetType)
            {
                var index = typedStackInformation
                    .FindIndex(si => si.TargetType == targetType);
                if (index >= 0)
                {
                    selectedStackInformation = index;
                    return typedStackInformation[index].SymbolName;
                }

                var symbolName = string.Format(
                    "__stack{0}_{1}",
                    stackPointer,
                    typedStackInformation.Count);

                var stackInformation = new SymbolInformation(symbolName, targetType);
                selectedStackInformation = typedStackInformation.Count;
                typedStackInformation.Add(stackInformation);

                return symbolName;
            }

            public SymbolInformation GetCurrent()
            {
                Debug.Assert(selectedStackInformation >= 0);
                Debug.Assert(typedStackInformation.Any());

                return typedStackInformation[selectedStackInformation];
            }

            public IEnumerable<SymbolInformation> ExtractStacks()
            {
                return typedStackInformation;
            }
        }

        private struct StackSnapshot
        {
            public readonly int Key;
            public readonly SymbolInformation[] StackInformations;

            public StackSnapshot(
                int key,
                int stackInformationsPosition,
                IEnumerable<StackInformationHolder> stackInformationHolders)
            {
                this.Key = key;
                this.StackInformations = stackInformationHolders
                    .Take(stackInformationsPosition)
                    .Select(stackInformationList => stackInformationList.GetCurrent())
                    .ToArray();
            }
        }
        #endregion

        #region Fields
        public readonly ModuleDefinition Module;
        public readonly string MethodName;
        public readonly TypeReference ReturnType;
        public readonly Parameter[] Parameters;
        public readonly VariableDefinition[] Locals;
        public readonly IPrepareContext PrepareContext;

        private readonly SortedDictionary<int, Instruction> instructions;
        private int nextOffset = -1;

        private int decodingPathNumber = 0;
        private readonly Dictionary<int, StackSnapshot> stackSnapshortsAtOffset =
            new Dictionary<int, StackSnapshot>();

        private readonly List<StackInformationHolder> stackList =
            new List<StackInformationHolder>();
        private int stackPointer = -1;
        private readonly Dictionary<int, string> labelNames = 
            new Dictionary<int, string>();
        private readonly Queue<StackSnapshot> pathRemains =
            new Queue<StackSnapshot>();
        #endregion

        public DecodeContext(
            ModuleDefinition module,
            string methodName,
            TypeReference returnType,
            Parameter[] parameters,
            VariableDefinition[] locals,
            Instruction[] instructions,
            IPrepareContext prepareContext)
        {
            Debug.Assert(instructions.Length >= 1);

            this.Module = module;
            this.MethodName = methodName;
            this.ReturnType = returnType;
            this.Parameters = parameters;
            this.Locals = locals;

            this.PrepareContext = prepareContext;

            this.instructions = new SortedDictionary<int, Instruction>();
            instructions.ForEach(instruction => this.instructions.Add(instruction.Offset, instruction));

            // First valid process is TryDequeueNextPath.
            this.pathRemains.Enqueue(new StackSnapshot(0, 0, new List<StackInformationHolder>()));
        }

        #region Instruction
        public bool MoveNext()
        {
            // Finish if current position already decoded.
            if (stackSnapshortsAtOffset.TryGetValue(nextOffset, out var stackSnapshot))
            {
                this.Current = null;
                return false;
            }

            stackSnapshot = new StackSnapshot(decodingPathNumber, stackPointer, stackList);
            stackSnapshortsAtOffset.Add(nextOffset, stackSnapshot);

            if (instructions.TryGetValue(nextOffset, out var instruction) == false)
            {
                throw new InvalidProgramSequenceException(
                    "End of method body reached: MethodName={0}",
                    this.MethodName);
            }
            this.Current = instruction;

            nextOffset = instruction.Offset + instruction.GetSize();

            return true;
        }

        public Instruction Current { get; private set; }

        public int CalculateByRelativeOffset(int offsetValue)
        {
            return nextOffset + offsetValue;
        }

        public void SetOffset(int newOffset)
        {
            Debug.Assert(decodingPathNumber >= 1);
            Debug.Assert(stackList != null);
            Debug.Assert(stackPointer >= 0);

            if (instructions.ContainsKey(newOffset) == false)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid branch target: Method={0}, Target={1}, CurrentOffset={2}",
                    this.MethodName,
                    newOffset,
                    this.Current.Offset);
            }

            nextOffset = newOffset;
        }
        #endregion

        #region Stack
        public string PushStack(TypeReference targetType)
        {
            Debug.Assert(decodingPathNumber >= 1);
            Debug.Assert(stackList != null);
            Debug.Assert(stackPointer >= 0);

            Debug.Assert(!targetType.IsUInt32Type());
            Debug.Assert(!targetType.IsUInt64Type());
            Debug.Assert(!targetType.IsUIntPtrType());

            Debug.Assert(!targetType.IsByteType());
            Debug.Assert(!targetType.IsSByteType());
            Debug.Assert(!targetType.IsInt16Type());
            Debug.Assert(!targetType.IsUInt16Type());

            Debug.Assert(!targetType.IsBooleanType());

            StackInformationHolder stackInformationHolder;
            if (stackPointer >= stackList.Count)
            {
                stackInformationHolder = new StackInformationHolder(stackPointer);
                stackList.Add(stackInformationHolder);
            }
            else
            {
                stackInformationHolder = stackList[stackPointer];
            }

            stackPointer++;

            return stackInformationHolder.GetOrAdd(targetType);
        }

        public SymbolInformation PopStack()
        {
            Debug.Assert(decodingPathNumber >= 1);
            Debug.Assert(stackList != null);
            Debug.Assert(stackPointer >= 0);

            if (stackPointer <= 0)
            {
                throw new InvalidProgramSequenceException(
                    "Evaluation stack underflow: Method={0}, CurrentIndex={1}",
                    this.MethodName,
                    nextOffset);
            }

            stackPointer--;
            return stackList[stackPointer].GetCurrent();
        }
        #endregion

        #region Path
        public int UniqueCodeBlockIndex { get; private set; }

        public int DecodingPathNumber => decodingPathNumber;

        public string EnqueueNewPath(int targetOffset)
        {
            Debug.Assert(decodingPathNumber >= 1);
            Debug.Assert(stackList != null);
            Debug.Assert(stackPointer >= 0);

            pathRemains.Enqueue(new StackSnapshot(
                targetOffset, stackPointer, stackList));

            if (labelNames.TryGetValue(
                targetOffset, out var labelName) == false)
            {
                labelName = string.Format("IL_{0:x4}", targetOffset);
                labelNames.Add(targetOffset, labelName);
            }

            return labelName;
        }

        public bool TryDequeueNextPath()
        {
            // Finish if remains path is empty.
            while (pathRemains.Count >= 1)
            {
                // Get queued branch target.
                var beforeBranchStackSnapshot = pathRemains.Dequeue();

                // If current position already decoded:
                if (stackSnapshortsAtOffset.TryGetValue(beforeBranchStackSnapshot.Key, out var stackSnapshot))
                {
                    // Skip if stack information equals.
                    if (stackSnapshot.StackInformations.SequenceEqual(
                        beforeBranchStackSnapshot.StackInformations))
                    {
                        continue;
                    }

                    // Same but has to reinterpret code block:
                    //   It will interpret already through (but bit different) path,
                    //   these code blocks assigned at same IL offset.
                    //   IL2C has to split blocks by this unique code block index.
                    this.UniqueCodeBlockIndex++;
                }

                // Start next path.
                decodingPathNumber++;
                nextOffset = beforeBranchStackSnapshot.Key;

                // Retreive stack informations.
                for (var index = 0;
                    index < beforeBranchStackSnapshot.StackInformations.Length;
                    index++)
                {
                    stackList[index].GetOrAdd(
                        beforeBranchStackSnapshot.StackInformations[index].TargetType);
                }
                stackPointer = beforeBranchStackSnapshot.StackInformations.Length;

                return true;
            }

            nextOffset = -1;
            return false;
        }
        #endregion

        #region Extractors
        public IEnumerable<SymbolInformation> ExtractStacks()
        {
            return stackList
                .SelectMany(stackInformations => stackInformations.ExtractStacks());
        }

        public IReadOnlyDictionary<int, string> ExtractLabelNames()
        {
            return labelNames;
        }
        #endregion
    }
}
