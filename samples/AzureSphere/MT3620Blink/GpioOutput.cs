namespace MT3620Blink
{
    internal sealed class GpioOutput : Descriptor
    {
        public GpioOutput(int gpioId, GPIO_OutputMode_Type type, bool initialValue)
            : base(Interops.GPIO_OpenAsOutput(
                gpioId,
                type,
                initialValue ? GPIO_Value_Type.GPIO_Value_High : GPIO_Value_Type.GPIO_Value_Low))
        {
        }

        public void SetValue(bool value) =>
            Interops.GPIO_SetValue(
                this.Identity,
                value ? GPIO_Value_Type.GPIO_Value_High : GPIO_Value_Type.GPIO_Value_Low);
    }
}
