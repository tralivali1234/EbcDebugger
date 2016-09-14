/*++

Copyright (c) 2007, Intel Corporation                                                         
All rights reserved. This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.             

Module Name:

  EdbSupport.h
  
Abstract:


--*/

#ifndef _EFI_EDB_SUPPORT_H_
#define _EFI_EDB_SUPPORT_H_

#include "Tiano.h"

#define EFI_DEBUG_PROMPT_STRING      L"EDB > "
#define EFI_DEBUG_PROMPT_COLUMN      5
#define EFI_DEBUG_INPUS_BUFFER_SIZE  64

#define EFI_DEBUGGER_LINE_NUMBER_IN_PAGE  0x10

#define EFI_DEBUG_MAX_PRINT_BUFFER   (80 * 4)

UINTN
Xtoi (
  CHAR16  *str
  );

UINT64
LXtoi (
  CHAR16  *str
  );

UINTN
Atoi (
  CHAR16  *str
  );

UINTN
AsciiXtoi (
  CHAR8  *str
  );

UINTN
AsciiAtoi (
  CHAR8  *str
  );

INTN
EfiStriCmp (
  IN CHAR16   *String,
  IN CHAR16   *String2
  );

INTN
EfiAsciiStriCmp (
  IN CHAR8   *String,
  IN CHAR8   *String2
  );

INTN
EfiStrCmpUnicodeAndAscii (
  IN CHAR16   *String,
  IN CHAR8    *String2
  );

INTN
EfiStriCmpUnicodeAndAscii (
  IN CHAR16   *String,
  IN CHAR8    *String2
  );

INTN
AsciiStrnCmp (
  IN      CHAR8               *FirstString,
  IN      CHAR8               *SecondString,
  IN      UINTN               Length
  );

BOOLEAN
StrEndWith (
  IN CHAR16                       *Str,
  IN CHAR16                       *SubStr
  );

CHAR16 *
StrDuplicate (
  IN CHAR16   *Src
  );

CHAR16 *
StrGetNewTokenLine (
  IN CHAR16                       *String,
  IN CHAR16                       *CharSet
  );

CHAR16 *
StrGetNextTokenLine (
  IN CHAR16                       *CharSet
  );

CHAR16 *
StrGetNewTokenField (
  IN CHAR16                       *String,
  IN CHAR16                       *CharSet
  );

CHAR16 *
StrGetNextTokenField (
  IN CHAR16                       *CharSet
  );

VOID
PatchForStrTokenAfter (
  IN CHAR16    *Buffer,
  IN CHAR16    Patch
  );

VOID
PatchForStrTokenBefore (
  IN CHAR16    *Buffer,
  IN CHAR16    Patch
  );

CHAR8 *
AsciiStrGetNewTokenLine (
  IN CHAR8                       *String,
  IN CHAR8                       *CharSet
  );

CHAR8 *
AsciiStrGetNextTokenLine (
  IN CHAR8                       *CharSet
  );

CHAR8 *
AsciiStrGetNewTokenField (
  IN CHAR8                       *String,
  IN CHAR8                       *CharSet
  );

CHAR8 *
AsciiStrGetNextTokenField (
  IN CHAR8                       *CharSet
  );

VOID
PatchForAsciiStrTokenAfter (
  IN CHAR8    *Buffer,
  IN CHAR8    Patch
  );

VOID
PatchForAsciiStrTokenBefore (
  IN CHAR8    *Buffer,
  IN CHAR8    Patch
  );

//
// Shell Library
//
VOID
Input (
  IN CHAR16    *Prompt OPTIONAL,
  OUT CHAR16   *InStr,
  IN UINTN     StrLen
  );

BOOLEAN
SetPageBreak (
  VOID
  );

UINTN
EDBPrint (
  IN CONST CHAR16  *Format,
  ...
  );

UINTN
EDBSPrint (
  OUT CHAR16        *Buffer,
  IN  INTN          BufferSize,
  IN  CONST CHAR16  *Format,
  ...
  );

UINTN
EDBSPrintWithOffset (
  OUT CHAR16        *Buffer,
  IN  INTN          BufferSize,
  IN  UINTN         Offset,
  IN  CONST CHAR16  *Format,
  ...
  );

EFI_STATUS
ReadFileToBuffer (
  IN  EFI_DEBUGGER_PRIVATE_DATA   *DebuggerPrivate,
  IN  CHAR16                      *FileName,
  OUT UINTN                       *BufferSize,
  OUT VOID                        **Buffer,
  IN  BOOLEAN                     ScanFs
  );

CHAR16 *
GetFileNameUnderDir (
  IN  EFI_DEBUGGER_PRIVATE_DATA   *DebuggerPrivate,
  IN  CHAR16                      *DirName,
  IN  CHAR16                      *FileName,
  IN OUT UINTN                    *Index
  );

#endif
