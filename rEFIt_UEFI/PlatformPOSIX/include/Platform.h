//
//  Platform.h.h
//  cpp_tests
//
//  Created by jief on 23.02.20.
//  Copyright © 2020 Jief_Machak. All rights reserved.
//

#ifndef Platform_h_h
#define Platform_h_h

#ifdef _MSC_VER
#include <Windows.h>
#endif

//#pragma clang diagnostic ignored "-Wc99-extensions"

#ifdef __cplusplus
extern "C" {
#endif

#include <Uefi.h>
#include <Base.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include "../../../../rEFIt_UEFI/Platform/BootLog.h"
//#include "BootLog.h"
#include <Library/DebugLib.h> // this is just to define DEBUG, because Slice wrongly did some #ifdef DEBUG

#ifdef __cplusplus
}
#endif


#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <wchar.h>
#include "posix/posix.h"

#include "../../../../rEFIt_UEFI/include/OneLinerMacros.h"

#ifndef __cplusplus
//typedef uint16_t wchar_t;
typedef uint32_t char32_t;
typedef uint16_t char16_t;
typedef uint8_t bool;
#endif

// Replacement of uintptr_t to avoid warning in printf. It needs macro _UINTPTR_T to avoid to standard definition
typedef unsigned long long  uintptr_t;
#undef PRIuPTR
#define PRIuPTR "llu"
//#define _UINTPTR_T

#include "./posix/abort.h"
#include "../../../rEFIt_UEFI/cpp_foundation/unicode_conversions.h"

#ifdef __cplusplus
#include "../../../rEFIt_UEFI/cpp_foundation/XString.h"
#include "../../../rEFIt_UEFI/cpp_foundation/XObjArray.h"
#include "../../../rEFIt_UEFI/entry_scan/common.h"
#include "../../../rEFIt_UEFI/libeg/BmLib.h"
#endif
#include "../../../rEFIt_UEFI/Platform/Utils.h"

//#include "../../../../../cpp_tests/Include/xcode_utf_fixed.h"


void CpuDeadLoop(void);

void PauseForKey(const wchar_t* msg);

const char* efiStrError(EFI_STATUS Status);


//#define DEBUG_VERBOSE 0
//#define DEBUG( expression )

#define MsgLog ::printf

// to be able to compile AutoGen.c
#ifdef __cplusplus
extern "C" {
#endif

#include "../../Build/Clover/DEBUGMACOS_XCODE8/X64/rEFIt_UEFI/refit/DEBUG/AutoGen.h"
EFI_STATUS
EFIAPI
RefitMain (IN EFI_HANDLE           ImageHandle,
           IN EFI_SYSTEM_TABLE     *SystemTable);

#ifdef __cplusplus
}
#endif


#endif /* Platform_h_h */