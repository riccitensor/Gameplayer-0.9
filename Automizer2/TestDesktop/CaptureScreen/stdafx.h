// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers


#include <WinSock2.h>
#include <Wtsapi32.h>

#include <Windows.h>
#include <Psapi.h>
#include <string>
#include <memory>
#include <vector>

#include <atlimage.h>
#include <GdiPlusHeaders.h>

#include "HandleGuards.h"
