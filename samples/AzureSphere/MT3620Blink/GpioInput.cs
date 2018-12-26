namespace MT3620Blink
{
    internal sealed class GpioInput : Descriptor
    {
        public GpioInput(int gpioId)
            : base(Interops.GPIO_OpenAsInput(gpioId))
        {
        }

        public bool Value
        {
            get
            {
                Interops.GPIO_GetValue(this.Identity, out var value);
                return value == GPIO_Value_Type.GPIO_Value_High;
            }
        }
    }
}
