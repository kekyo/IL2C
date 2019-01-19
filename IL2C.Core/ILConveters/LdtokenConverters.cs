using System;

using Mono.Cecil.Cil;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class LdtokenConverters : InlineMemberConverter
    {
        public override OpCode OpCode => OpCodes.Ldtoken;

        public override Func<IExtractContext, string[]> Apply(
            IMemberInformation member, DecodeContext decodeContext)
        {
            // ECMA-335 III.4.17 ldtoken - load the runt ime representat ion of a metadata

            var field = member as IFieldInformation;
            if (field != null)
            {
                if (field.DeclaredValue == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid declared value: Location={0}, FieldType={1}",
                        decodeContext.CurrentCode.RawLocation,
                        field.FriendlyName);
                }

                var resourceData = (byte[])field.DeclaredValue;
                var declaredValueName = decodeContext.PrepareContext.
                    RegisterDeclaredValues(field, resourceData);

                // HACK: Push RuntimeFieldHandle with specific declared values hint.
                //   (Prepare to call the "RuntimeHelpers.InitializeArray") method, see the CallConverter.)
                var symbol = decodeContext.PushStack(
                    decodeContext.PrepareContext.MetadataContext.RuntimeFieldHandle,
                    declaredValueName);

                // Store into RuntimeFieldHandle structure.
                return extractContext => new[] {
                    string.Format(
                        "{0}.size__ = {1}",
                        extractContext.GetSymbolName(symbol),
                        resourceData.Length),
                    string.Format(
                        "{0}.field__ = {1}",
                        extractContext.GetSymbolName(symbol),
                        declaredValueName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown token: Location={0}, TokenType={1}",
                decodeContext.CurrentCode.RawLocation,
                member.FriendlyName);
        }
    }
}
