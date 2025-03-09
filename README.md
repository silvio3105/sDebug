
# About

Simple Debug library is frameworkless library written in C++. It provides three debug levels - verbose, info and error levels. Each level can be enabled or disabled during compile. User have to redefine output function and provide support for string output(RTT, UART etc...).
The library is encapsulated in `sDebug` namespace. Examples can be found in `Examples` folder.


### Levels

Library supports three debug levels:
- Verbose: Debug level for fine details during application runtime, eg., measured temperature each second.
- Info: Debug level for events, actions and notifications/warnings, eg., if measured temperature is below minimum or above maximum.
- Error: Debug level for errors during application runtime, eg., if temperature sensor init fails.

It is possible to enable each level.



# Usage

Include `sDebug.hpp` in each file where debug is needed. Inside `Main.cpp` redefine function `void sDebug::out(const char* string, const uint16_t len)` and pass `string` and `len` to function for final print(RTT, UART etc...).


### Compile flags

- `DEBUG`: Enable debug prints for whole project. This flag is "main switch" for the library and debug prints.
- `DEBUG_VERBOSE`: Enable verbose debug level for whole project. Does not enable info or error levels.
- `DEBUG_INFO`: Enable info debug level for whole project. Does not enable error level.
- `DEBUG_ERROR`: Enable error debug level for whole project.
- `DEBUG_BUFFER_SIZE={n}`: Set buffer size to `n` bytes for printf function. If not provided, buffer size will be set to 128 bytes.
- `DEBUG_STACK_PRINTF`: Use buffer on stack for printf function.


### Enable/Disable debug

Enable debug levels with snippets:
- `DEBUG_ENABLE_VERBOSE({module})`: Enable verbose debug level for `module`(eg., ILPS22QS).
- `DEBUG_ENABLE_INFO({module})`: Enable info debug level for `module`(eg., ILPS22QS).
- `DEBUG_ENABLE_ERROR({module})`: Enable error debug level for `module`(eg., ILPS22QS).

Those snippets will create static function aliases for each debug level.
Disable debug levels with snippets:
- `DEBUG_DISABLE_VERBOSE({module})`: Disable verbose debug level for `module`(eg., ILPS22QS).
- `DEBUG_DISABLE_INFO({module})`: Disable info debug level for `module`(eg., ILPS22QS).
- `DEBUG_DISABLE_ERROR({module})`: Disable error debug level for `module`(eg., ILPS22QS).

When debug level is disabled prints for disabled level are redirected to dummy function and strings are removed by compiler.


### Print functions

Library provides three functions for each debug level:
- `_PRINT`: For constant strings without string length - `_PRINT("String\n");`
- `_PRINTN`: For constant strings with string length - `_PRINTN("String\n", 7);`
- `_PRINTF`: For formatted strings - `_PRINTF("String %u\n", 10);`

Function format is `{module}_PRINT(N/F){_level}` where `module` is provided with `DEBUG_ENABLE`.
For example, if all levels are enabled for `ILPS22QS` module, then functions will be:
- For verbose level: `ILPS22QS_PRINT`, `ILPS22QS_PRINTN` and `ILPS22QS_PRINTF`.
- For info level: `ILPS22QS_PRINT_INFO`, `ILPS22QS_PRINTN_INFO` and `ILPS22QS_PRINTF_INFO`.
- For error level: `ILPS22QS_PRINT_ERROR`, `ILPS22QS_PRINTN_ERROR` and `ILPS22QS_PRINTF_ERROR`.


### Per module usage

See examples for per module debug.



# LICENSE

Copyright (c) 2025, silvio3105 (www.github.com/silvio3105)

Access and use of this Project and its contents are granted free of charge to any Person.
The Person is allowed to copy, modify and use The Project and its contents only for non-commercial use.
Commercial use of this Project and its contents is prohibited.
Modifying this License and/or sublicensing is prohibited.

THE PROJECT AND ITS CONTENT ARE PROVIDED "AS IS" WITH ALL FAULTS AND WITHOUT EXPRESSED OR IMPLIED WARRANTY.
THE AUTHOR KEEPS ALL RIGHTS TO CHANGE OR REMOVE THE CONTENTS OF THIS PROJECT WITHOUT PREVIOUS NOTICE.
THE AUTHOR IS NOT RESPONSIBLE FOR DAMAGE OF ANY KIND OR LIABILITY CAUSED BY USING THE CONTENTS OF THIS PROJECT.

This License shall be included in all functional textual files.

---

Copyright (c) 2025, silvio3105
