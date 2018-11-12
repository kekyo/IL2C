using System;
using System.Collections.Generic;
using System.Linq;

using IL2C.Metadata;

namespace IL2C.Writers
{
    internal sealed class ExceptionHandlerController
    {
        private sealed class ExceptionHandlerState
        {
            public readonly ExceptionHandler Handler;
            public readonly int HandlerIndex;

            private int index = -1;
            private bool inBlock = false;

            public ExceptionHandlerState(ExceptionHandler handler, int handlerIndex)
            {
                this.Handler = handler;
                this.HandlerIndex = handlerIndex;
            }

            public bool Update(
                ICodeInformation code,
                Action<ExceptionHandler, int> tryEnd,
                Action<ExceptionCatchHandler, int> catchStart,
                Action<ExceptionCatchHandler, int> catchEnd)
            {
                while (true)
                {
                    if (index == -1)
                    {
                        if (this.Handler.TryEnd == code.Offset)
                        {
                            tryEnd(this.Handler, this.HandlerIndex);
                            index = 0;
                            continue;
                        }

                        return false;
                    }

                    if (index < this.Handler.CatchHandlers.Length)
                    {
                        var catchHandler = this.Handler.CatchHandlers[index];
                        if (!inBlock)
                        {
                            if (catchHandler.CatchStart == code.Offset)
                            {
                                catchStart(catchHandler, index);
                                inBlock = true;
                            }

                            return false;
                        }
                        else
                        {
                            if (catchHandler.CatchEnd == code.Offset)
                            {
                                catchEnd(catchHandler, index);
                                inBlock = false;
                                index++;
                                continue;
                            }

                            return false;
                        }
                    }

                    // Require emit end-try.
                    return true;
                }
            }
        }

        private readonly Queue<(ExceptionHandler handler, int index)> queue;
        private readonly Stack<ExceptionHandlerState> stack = new Stack<ExceptionHandlerState>();

        private readonly Action<ExceptionHandler, int> tryStart;
        private readonly Action<ExceptionHandler, int> tryEnd;
        private readonly Action<ExceptionCatchHandler, int> catchStart;
        private readonly Action<ExceptionCatchHandler, int> catchEnd;
        private readonly Action<ExceptionHandler, int> finished;

        public ExceptionHandlerController(
            ExceptionHandler[] handlers,
            Action<ExceptionHandler, int> tryStart,
            Action<ExceptionHandler, int> tryEnd,
            Action<ExceptionCatchHandler, int> catchStart,
            Action<ExceptionCatchHandler, int> catchEnd,
            Action<ExceptionHandler, int> finished)
        {
            queue = new Queue<(ExceptionHandler handler, int index)>(
                handlers.Select((handler, index) => (handler, index)));

            this.tryStart = tryStart;
            this.tryEnd = tryEnd;
            this.catchStart = catchStart;
            this.catchEnd = catchEnd;
            this.finished = finished;
        }

        public bool IsFinished => (queue.Count == 0) && (stack.Count == 0);

        public void Update(ICodeInformation code)
        {
            while (true)
            {
                if (queue.Count >= 1)
                {
                    var entry = queue.Peek();
                    if (entry.handler.TryStart == code.Offset)
                    {
                        tryStart(entry.handler, entry.index);
                        queue.Dequeue();
                        stack.Push(new ExceptionHandlerState(entry.handler, entry.index));
                        continue;
                    }
                }

                if (stack.Count >= 1)
                {
                    var state = stack.Peek();
                    if (state.Update(code, tryEnd, catchStart, catchEnd))
                    {
                        finished(state.Handler, state.HandlerIndex);
                        stack.Pop();
                        continue;
                    }
                }

                break;
            }
        }
    }
}
