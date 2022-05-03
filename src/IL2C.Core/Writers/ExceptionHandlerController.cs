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
            public readonly int NestedIndex;

            private int catchHandlerIndex = -1;
            private bool inBlock = false;

            public ExceptionHandlerState(ExceptionHandler handler, int handlerIndex, int nestedIndex)
            {
                this.Handler = handler;
                this.HandlerIndex = handlerIndex;
                this.NestedIndex = nestedIndex;
            }

            public bool Update(
                ICodeInformation code,
                Action<ExceptionHandler, int, int> tryEnd,
                Action<ExceptionHandler, int, int, ExceptionCatchHandler, int> catchStart,
                Action<ExceptionHandler, int, int, ExceptionCatchHandler, int> catchEnd)
            {
                while (true)
                {
                    if (catchHandlerIndex == -1)
                    {
                        if (this.Handler.TryEnd == code.Offset)
                        {
                            tryEnd(this.Handler, this.HandlerIndex, this.NestedIndex);
                            catchHandlerIndex = 0;
                            continue;
                        }

                        return false;
                    }

                    if (catchHandlerIndex < this.Handler.CatchHandlers.Length)
                    {
                        var catchHandler = this.Handler.CatchHandlers[catchHandlerIndex];
                        if (!inBlock)
                        {
                            if (catchHandler.CatchStart == code.Offset)
                            {
                                catchStart(this.Handler, this.HandlerIndex, this.NestedIndex, catchHandler, catchHandlerIndex);
                                inBlock = true;
                            }

                            return false;
                        }
                        else
                        {
                            if (catchHandler.CatchEnd == code.Offset)
                            {
                                catchEnd(this.Handler, this.HandlerIndex, this.NestedIndex, catchHandler, catchHandlerIndex);
                                inBlock = false;
                                catchHandlerIndex++;
                                continue;
                            }

                            return false;
                        }
                    }

                    // Require emit end-try.
                    return true;
                }
            }

            public bool TryFinish(
                Action<ExceptionHandler, int, int, ExceptionCatchHandler, int> catchEnd)
            {
                if ((catchHandlerIndex >= (this.Handler.CatchHandlers.Length - 1)) && inBlock)
                {
                    var catchHandler = this.Handler.CatchHandlers[catchHandlerIndex];
                    catchEnd(this.Handler, this.HandlerIndex, this.NestedIndex, catchHandler, catchHandlerIndex);
                    inBlock = false;
                    catchHandlerIndex++;

                    // Require emit end-try.
                    return true;
                }

                return false;
            }
        }

        private readonly Queue<(ExceptionHandler handler, int handlerIndex)> queue;
        private readonly Stack<ExceptionHandlerState> stack = new Stack<ExceptionHandlerState>();

        private readonly Action<ExceptionHandler, int, int> tryStart;
        private readonly Action<ExceptionHandler, int, int> tryEnd;
        private readonly Action<ExceptionHandler, int, int, ExceptionCatchHandler, int> catchStart;
        private readonly Action<ExceptionHandler, int, int, ExceptionCatchHandler, int> catchEnd;
        private readonly Action<ExceptionHandler, int, int, ExceptionHandler, int, int> finished;

        public ExceptionHandlerController(
            ExceptionHandler[] handlers,
            Action<ExceptionHandler, int, int> tryStart,
            Action<ExceptionHandler, int, int> tryEnd,
            Action<ExceptionHandler, int, int, ExceptionCatchHandler, int> catchStart,
            Action<ExceptionHandler, int, int, ExceptionCatchHandler, int> catchEnd,
            Action<ExceptionHandler, int, int, ExceptionHandler, int, int> finished)
        {
            queue = new Queue<(ExceptionHandler handler, int handlerIndex)>(
                handlers.Select((handler, handlerIndex) => (handler, handlerIndex)));

            this.tryStart = tryStart;
            this.tryEnd = tryEnd;
            this.catchStart = catchStart;
            this.catchEnd = catchEnd;
            this.finished = finished;
        }

        public bool IsFinished =>
            (queue.Count == 0) && (stack.Count == 0);

        public void Update(ICodeInformation code)
        {
            while (true)
            {
                if (queue.Count >= 1)
                {
                    var entry = queue.Peek();
                    if (entry.handler.TryStart == code.Offset)
                    {
                        var nestedIndex = stack.Count;
                        tryStart(entry.handler, entry.handlerIndex, nestedIndex);
                        queue.Dequeue();
                        stack.Push(new ExceptionHandlerState(entry.handler, entry.handlerIndex, nestedIndex));
                        continue;
                    }
                }

                if (stack.Count >= 1)
                {
                    var state = stack.Peek();
                    if (state.Update(code, tryEnd, catchStart, catchEnd))
                    {
                        stack.Pop();
                        var parent = (stack.Count >= 1) ? stack.Peek() : null;
                        finished(state.Handler, state.HandlerIndex, state.NestedIndex, parent?.Handler, parent?.HandlerIndex??-1, parent?.NestedIndex??-1);
                        continue;
                    }
                }

                break;
            }
        }

        public bool TryFinish()
        {
            if ((queue.Count == 0) && (stack.Count == 1))
            {
                var state = stack.Peek();
                if (state.TryFinish(catchEnd))
                {
                    stack.Pop();
                    var parent = (stack.Count >= 1) ? stack.Peek() : null;
                    finished(state.Handler, state.HandlerIndex, state.NestedIndex, parent?.Handler, parent?.HandlerIndex ?? -1, parent?.NestedIndex ?? -1);
                    return true;
                }
            }

            return false;
        }
    }
}
