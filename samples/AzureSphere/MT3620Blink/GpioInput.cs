namespace MT3620Blink
{
    internal sealed class GpioInput : Descriptor
    {
        public GpioInput(int gpioId)
            : base(Interops.GPIO_OpenAsInput(gpioId))
        {
        }

        public bool Value =>
            (Interops.GPIO_GetValue(this.Identity, out var value) == 0) ?
                (value == GPIO_Value_Type.GPIO_Value_High) :
                false;
    }
}
