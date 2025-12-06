/*
	Copyright (c) 2025, silvio3105 (www.github.com/silvio3105)

	Access and use of this Project and its contents are granted free of charge to any Person.
	The Person is allowed to copy, modify and use The Project and its contents only for non-commercial use.
	Commercial use of this Project and its contents is prohibited.
	Modifying this License and/or sublicensing is prohibited.

	THE PROJECT AND ITS CONTENT ARE PROVIDED "AS IS" WITH ALL FAULTS AND WITHOUT EXPRESSED OR IMPLIED WARRANTY.
	THE AUTHOR KEEPS ALL RIGHTS TO CHANGE OR REMOVE THE CONTENTS OF THIS PROJECT WITHOUT PREVIOUS NOTICE.
	THE AUTHOR IS NOT RESPONSIBLE FOR DAMAGE OF ANY KIND OR LIABILITY CAUSED BY USING THE CONTENTS OF THIS PROJECT.

	This License shall be included in all functional textual files.
*/

// ----- INCLUDE FILES
#include			"sDebug.hpp"
#include			"SEGGER_RTT.h"

#include			<stdint.h>
#include 			<stdio.h>
#include			<string.h>


// Create debug function alises
#if DEBUG_MODULE

#ifdef sDEBUG_MODULE_VERBOSE
sDEBUG_ENABLE_VERBOSE(MODULE);
#else // sDEBUG_MODULE_VERBOSE
sDEBUG_DISABLE_VERBOSE(MODULE);
#endif // sDEBUG_MODULE_VERBOSE

#ifdef sDEBUG_MODULE_INFO
sDEBUG_ENABLE_INFO(MODULE);
#else // sDEBUG_MODULE_INFO
sDEBUG_DISABLE_INFO(MODULE);
#endif // sDEBUG_MODULE_INFO

#ifdef sDEBUG_MODULE_ERROR
sDEBUG_ENABLE_ERROR(MODULE);
#else // sDEBUG_MODULE_ERROR
sDEBUG_DISABLE_ERROR(MODULE);
#endif // sDEBUG_MODULE_ERROR

#else // DEBUG_MODULE

// Disable all debug levels for "MODULE"
sDEBUG_DISABLE_VERBOSE(MODULE);
sDEBUG_DISABLE_INFO(MODULE);
sDEBUG_DISABLE_ERROR(MODULE);

#endif // DEBUG_MODULE


// ----- FUNCTION DEFINITIONS
int main(void)
{
	// Verbose debug
	MODULE_PRINT("Verbose 1\n");
	MODULE_PRINTN("Verbose 2\n", 10);
	MODULE_PRINTF("Verbose %u\n", 3);

	// Info debug
	MODULE_PRINT_INFO("Info 1\n");
	MODULE_PRINTN_INFO("Info 2\n", 7);
	MODULE_PRINTF_INFO("Info %u\n", 3);
	
	// Error debug
	MODULE_PRINT_ERROR("Error 1\n");
	MODULE_PRINTN_ERROR("Error 2\n", 8);
	MODULE_PRINTF_ERROR("Error %u\n", 3);

	while (1)
	{
		
	}
}

void sDebug::out(const char* string, const uint16_t len)
{
	// Debug output handler. Output debug strings to RTT, UART or something else. Redefine this function only once.
	SEGGER_RTT_Write(0, string, len);
}


// END WITH NEW LINE
