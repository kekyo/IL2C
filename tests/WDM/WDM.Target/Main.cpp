#include <wdm.h>
#include <intrin.h>
#include "Generated/WDM.Code.h"

#pragma warning(disable: 4065)

static const char* pFrom = "Microsoft ";
static const char* pTo = "BABELBABEL";

/////////////////////////////////////////////////////////////

typedef struct WDM_Code_DeviceExtension
{
    // DIRTY HACK: __EXECUTION_FRAME__
    __EXECUTION_FRAME__* pNext;
    uint8_t targetCount;
    WDM_Code_InterceptCDRomDevice** ppInterceptCDRomDevice;

    DEVICE_OBJECT* pLowerDeviceObject;
    WDM_Code_InterceptCDRomDevice* pInterceptCDRomDevice;
} WDM_Code_DeviceExtension;

/////////////////////////////////////////////////////////////

static NTSTATUS WDM_Code_ReadCompleted(DEVICE_OBJECT* pDeviceObject, IRP* pIrp, void* pContext)
{
    ASSERT(pContext == nullptr);

    auto pDeviceExtension =
        static_cast<WDM_Code_DeviceExtension*>(pDeviceObject->DeviceExtension);
    auto pIoStackLocation =
        IoGetCurrentIrpStackLocation(pIrp);
    auto pInterceptCDRomDevice =
        pDeviceExtension->pInterceptCDRomDevice;

    if (pIrp->PendingReturned)
    {
        IoMarkIrpPending(pIrp);
    }

    if (!NT_SUCCESS(pIrp->IoStatus.Status))
    {
        return pIrp->IoStatus.Status;
    }

    intptr_t pBuffer = 0;
    uint32_t offset = 0;
    uint32_t size = pIoStackLocation->Parameters.Read.Length;

    if (pIrp->MdlAddress != nullptr)
    {
        pBuffer = reinterpret_cast<intptr_t>(
            MmGetSystemAddressForMdlSafe(pIrp->MdlAddress, HighPagePriority));
        offset = MmGetMdlByteOffset(pIrp->MdlAddress);
    }
    else if (pIrp->AssociatedIrp.SystemBuffer != nullptr)
    {
        pBuffer = reinterpret_cast<intptr_t>(pIrp->AssociatedIrp.SystemBuffer);
    }

    NTSTATUS status = WDM_Code_InterceptCDRomDevice_ReadCompleted(
        pInterceptCDRomDevice,
        pBuffer,
        offset,
        size);

    return status;
}

static NTSTATUS WDM_Code_Dispatch(DEVICE_OBJECT* pDeviceObject, IRP* pIrp)
{
    auto pDeviceExtension =
        static_cast<WDM_Code_DeviceExtension*>(pDeviceObject->DeviceExtension);
    auto pIoStackLocation =
        IoGetCurrentIrpStackLocation(pIrp);

    switch (pIoStackLocation->MajorFunction)
    {
    case IRP_MJ_READ:
        IoCopyCurrentIrpStackLocationToNext(pIrp);
        IoSetCompletionRoutine(
            pIrp,
            WDM_Code_ReadCompleted,
            nullptr,
            TRUE,
            TRUE,
            TRUE);
        return IoCallDriver(pDeviceExtension->pLowerDeviceObject, pIrp);

    default:
        IoSkipCurrentIrpStackLocation(pIrp);
        return IoCallDriver(pDeviceExtension->pLowerDeviceObject, pIrp);
    }
}

/////////////////////////////////////////////////////////////

#pragma code_seg("PAGE")

static NTSTATUS WDM_Code_AddDevice(
    DRIVER_OBJECT* pDriverObject,
    DEVICE_OBJECT* pPhysicalDeviceObject)
{
    PAGED_CODE();

    DbgPrint("WDM_Code: AddDevice(): PDO: %wZ\r\n",
        &pPhysicalDeviceObject->DriverObject->DriverName);

    DEVICE_OBJECT *pDeviceObject = nullptr;
    auto status = IoCreateDevice(
        pDriverObject,
        sizeof(WDM_Code_DeviceExtension),
        nullptr,
        FILE_DEVICE_UNKNOWN,
        0,
        FALSE,
        &pDeviceObject);
    if (!NT_SUCCESS(status))
    {
        return status;
    }

    auto pDeviceExtension =
        static_cast<WDM_Code_DeviceExtension*>(pDeviceObject->DeviceExtension);
    pDeviceExtension->pInterceptCDRomDevice = nullptr;

    //////////////////////////////////////////
    // DIRTY HACK:
    //   Force manually built global execution frame.
    //   Because suppress collection by GC.
    //   This link totally can't unlink, so HelloDriver leaks periodic by closing device...

    pDeviceExtension->targetCount = 1;
    pDeviceExtension->ppInterceptCDRomDevice =
        &pDeviceExtension->pInterceptCDRomDevice;
    __gc_link_execution_frame__(pDeviceExtension);

    // new InterceptCDRomDevice();
    pDeviceExtension->pInterceptCDRomDevice = static_cast<WDM_Code_InterceptCDRomDevice*>(
        __gc_get_uninitialized_object__(__typeof__(WDM_Code_InterceptCDRomDevice)));
    WDM_Code_InterceptCDRomDevice__ctor(
        pDeviceExtension->pInterceptCDRomDevice,
        reinterpret_cast<intptr_t>(pFrom),
        reinterpret_cast<intptr_t>(pTo), 10);

    //////////////////////////////////////////
    // Initialize device object.

    pDeviceExtension->pLowerDeviceObject =
        IoAttachDeviceToDeviceStack(pDeviceObject, pPhysicalDeviceObject);

    DbgPrint("WDM_Code: AddDevice(): LDO: %wZ\r\n",
        &pDeviceExtension->pLowerDeviceObject->DriverObject->DriverName);

    pDeviceObject->Flags =
        pDeviceExtension->pLowerDeviceObject->Flags;
    pDeviceObject->DeviceType =
        pDeviceExtension->pLowerDeviceObject->DeviceType;
    pDeviceObject->Characteristics =
        pDeviceExtension->pLowerDeviceObject->Characteristics;

    // Done.
    pDeviceObject->Flags &= ~DO_DEVICE_INITIALIZING;

    return STATUS_SUCCESS;
}

static void WDM_Code_Unload(DRIVER_OBJECT* pDriverObject)
{
    PAGED_CODE();

    __gc_shutdown__();
}

extern "C" NTSTATUS DriverEntry(
    DRIVER_OBJECT* pDriverObject,
    UNICODE_STRING* pRegistryPath)
{
    PAGED_CODE();

#ifdef DBG
    __debugbreak();
#endif

    DbgPrint("WDM_Code: DriverEntry(): Path: %wZ\r\n", pRegistryPath);

    __gc_initialize__();

    pDriverObject->DriverExtension->AddDevice = WDM_Code_AddDevice;
    pDriverObject->DriverUnload = WDM_Code_Unload;

    for (auto index = 0; index <= IRP_MJ_MAXIMUM_FUNCTION; index++)
    {
        pDriverObject->MajorFunction[index] =
            reinterpret_cast<PDRIVER_DISPATCH>(WDM_Code_Dispatch);
    }

    return STATUS_SUCCESS;
}
