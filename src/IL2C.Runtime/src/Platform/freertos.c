#include <il2c_private.h>

//////////////////////////////////////////////////
// FreeRTOS scheduler

#if defined(IL2C_USE_FREERTOS) && defined(portNUM_PROCESSORS)

intptr_t il2c_create_thread__(IL2C_THREAD_ENTRY_POINT_TYPE entryPoint, IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE parameter)
{
    il2c_assert(entryPoint != 0);

    TaskHandle_t handle;

#if defined(tskNO_AFFINITY)
    // ESP32 related: https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/system/freertos.html
    BaseType_t result = xTaskCreatePinnedToCore(
        entryPoint,
        "IL2C.Thread",
        8192,
        parameter,
        1,
        &handle,
        tskNO_AFFINITY);
#else
    BaseType_t result = xTaskCreate(
        entryPoint,
        "IL2C.Thread",
        8192,
        parameter,
        1,
        &handle);
#endif
    il2c_assert(result == pdPASS);

    return (intptr_t)handle;
}

void il2c_join_thread__(intptr_t handle)
{
    il2c_assert(handle != 0);

    // TODO:
}

#endif
