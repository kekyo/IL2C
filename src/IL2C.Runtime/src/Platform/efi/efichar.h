////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef _BOOT_EFI_EFICHAR_H_
#define	_BOOT_EFI_EFICHAR_H_

int ucs2_to_utf8(const efi_char *, char **);
int utf8_to_ucs2(const char *, efi_char **, size_t *);

#endif /* _BOOT_EFI_EFICHAR_H_ */
