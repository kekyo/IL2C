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

#ifndef _LOADER_EFILIB_H
#define	_LOADER_EFILIB_H

#include <stand.h>

extern EFI_HANDLE		IH;
extern EFI_SYSTEM_TABLE		*ST;
extern EFI_BOOT_SERVICES	*BS;
extern EFI_RUNTIME_SERVICES	*RS;

extern struct devsw efipart_dev;
extern struct devsw efinet_dev;
extern struct netif_driver efinetif;

void *efi_get_table(EFI_GUID *tbl);

int efi_register_handles(struct devsw *, EFI_HANDLE *, EFI_HANDLE *, int);
EFI_HANDLE efi_find_handle(struct devsw *, int);
int efi_handle_lookup(EFI_HANDLE, struct devsw **, int *,  uint64_t *);
int efi_handle_update_dev(EFI_HANDLE, struct devsw *, int, uint64_t);

EFI_DEVICE_PATH *efi_lookup_image_devpath(EFI_HANDLE);
EFI_DEVICE_PATH *efi_lookup_devpath(EFI_HANDLE);
EFI_HANDLE efi_devpath_handle(EFI_DEVICE_PATH *);
EFI_DEVICE_PATH *efi_devpath_last_node(EFI_DEVICE_PATH *);
EFI_DEVICE_PATH *efi_devpath_trim(EFI_DEVICE_PATH *);
CHAR16 *efi_devpath_name(EFI_DEVICE_PATH *);
void efi_free_devpath_name(CHAR16 *);

int efi_status_to_errno(EFI_STATUS);

void efi_time_init(void);
void efi_time_fini(void);

EFI_STATUS main(int argc, CHAR16 *argv[]);
void exit(EFI_STATUS status);
void delay(int usecs);

#endif	/* _LOADER_EFILIB_H */
