/**
 * @file sDebug.hpp
 * @author silvio3105 (www.github.com/silvio3105)
 * @brief Simple Debug library header file.
 * 
 * @copyright Copyright (c) 2025, silvio3105
 * 
 */

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

#ifndef _SDEBUG_HPP_
#define _SDEBUG_HPP_

// ----- INCLUDE FILES
#include 			<stdint.h>
#include 			<string.h>


// ----- DEFINES
#ifdef sDEBUG_VERBOSE
#define sDEBUG_VERBOSE_OUTPUTF	sDebug::__outputf
#else
#define sDEBUG_VERBOSE_OUTPUTF	sDebug::__dummy
#endif // sDEBUG_VERBOSE

#ifdef sDEBUG_INFO
#define sDEBUG_INFO_OUTPUTF	sDebug::__outputf
#else
#define sDEBUG_INFO_OUTPUTF	sDebug::__dummy
#endif // sDEBUG_INFO

#ifdef sDEBUG_ERROR
#define sDEBUG_ERROR_OUTPUTF	sDebug::__outputf
#else
#define sDEBUG_ERROR_OUTPUTF	sDebug::__dummy
#endif // sDEBUG_ERROR


// ----- NAMESPACES
namespace sDebug
{
	// VARIABLES
	/**
	 * @brief Library version string.
	 * 
	 * \ingroup sDebug
	 */
	static constexpr char version[] = "v1.0rc2";


	// FUNCTION DECLARATIONS
	void __outputf(const char* string, ...);
	void out(const char* string, const uint16_t len);


	// FUNCTION DEFINITIONS
	/**
	 * @brief Output constant debug string.
	 * 
	 * @param string Pointer to constant string.
	 * @param len Length of \c string
	 * 
	 * @return No return value. 
	 * 
	 * \ingroup sDebug
	 */	
	inline void __output(const char* string, const uint16_t len)
	{
		#ifdef sDEBUG
		out(string, len);
		#endif // sDEBUG
	}

	/**
	 * @brief Output constant string of unknown length.
	 * 
	 * @param string Pointer to constant string.
	 * 
	 * @return No return value.
	 * 
	 * \ingroup sDebug
	 */
	inline void __output(const char* string)
	{
		#ifdef sDEBUG
		__output(string, strlen(string));
		#endif // sDEBUG
	}

	/**
	 * @brief Dummy function used when debug level is disabled.
	 * 
	 * @return No return value.
	 * 
	 * \ingroup sDebug
	 */	
	static inline constexpr void __dummy(...)
	{

	}

	/**
	 * @brief Output verbose prints.
	 * 
	 * @param string Pointer to constant string.
	 * @param len Length of \c string
	 * 
	 * @return No return value. 
	 * 
	 * \ingroup sDebug
	 * @{
	 */	
	inline void verbose(const char* string, const uint16_t len)
	{
		#ifdef sDEBUG_VERBOSE
		__output(string, len);
		#endif // sDEBUG_VERBOSE
	}

	inline void verbose(const char* string)
	{
		#ifdef sDEBUG_VERBOSE
		__output(string, strlen(string));
		#endif // sDEBUG_VERBOSE
	}

	/** @} */
	
	/**
	 * @brief Output info prints.
	 * 
	 * @param string Pointer to constant string.
	 * @param len Length of \c string
	 * 
	 * @return No return value. 
	 * 
	 * \ingroup sDebug
	 * @{
	 */	
	inline void info(const char* string, const uint16_t len)
	{
		#ifdef sDEBUG_INFO
		__output(string, len);
		#endif // sDEBUG_INFO
	}

	inline void info(const char* string)
	{
		#ifdef sDEBUG_INFO
		__output(string, strlen(string));
		#endif // sDEBUG_INFO
	}

	/** @} */

	/**
	 * @brief Output error prints.
	 * 
	 * @param string Pointer to constant string.
	 * @param len Length of \c string
	 * 
	 * @return No return value.
	 *  
	 * \ingroup sDebug
	 * @{
	 */	
	inline void error(const char* string, const uint16_t len)
	{
		#ifdef sDEBUG_ERROR
		__output(string, len);
		#endif // sDEBUG_ERROR
	}

	inline void error(const char* string)
	{
		#ifdef sDEBUG_ERROR
		__output(string, strlen(string));
		#endif // sDEBUG_ERROR
	}
	
	/** @} */
};


// ----- SNIPPETS
/**
 * @brief Enable verbose debug level.
 *  
 * @param _module Module name. Eg., \c ILPS22QS.
 * 
 * \ingroup sDebug
 */
#define sDEBUG_ENABLE_VERBOSE(_module) \
	static const auto& _module ## _PRINTN = static_cast<void(*)(const char*, const uint16_t)>(sDebug::verbose); \
	static const auto& _module ## _PRINT = static_cast<void(*)(const char*)>(sDebug::verbose); \
	static constexpr auto& _module ## _PRINTF = sDEBUG_VERBOSE_OUTPUTF;

/**
 * @brief Enable info debug level.
 *  
 * @param _module Module name. Eg., \c ILPS22QS.
 * 
 * \ingroup sDebug
 */
#define sDEBUG_ENABLE_INFO(_module) \
	static const auto& _module ## _PRINTN_INFO = static_cast<void(*)(const char*, const uint16_t)>(sDebug::info); \
	static const auto& _module ## _PRINT_INFO = static_cast<void(*)(const char*)>(sDebug::info); \
	static constexpr auto& _module ## _PRINTF_INFO = sDEBUG_INFO_OUTPUTF;	

/**
 * @brief Enable error debug level.
 *  
 * @param _module Module name. Eg., \c ILPS22QS.
 * 
 * \ingroup sDebug
 */
#define sDEBUG_ENABLE_ERROR(_module) \
	static const auto& _module ## _PRINTN_ERROR = static_cast<void(*)(const char*, const uint16_t)>(sDebug::error); \
	static const auto& _module ## _PRINT_ERROR = static_cast<void(*)(const char*)>(sDebug::error); \
	static constexpr auto& _module ## _PRINTF_ERROR = sDEBUG_ERROR_OUTPUTF;
	
/**
 * @brief Disable verbose debug level.
 *  
 * @param _module Module name. Eg., \c ILPS22QS.
 * 
 * \ingroup sDebug
 */
#define sDEBUG_DISABLE_VERBOSE(_module) \
	static constexpr auto& _module ## _PRINTN = sDebug::__dummy; \
	static constexpr auto& _module ## _PRINT = sDebug::__dummy; \
	static constexpr auto& _module ## _PRINTF = sDebug::__dummy;	

/**
 * @brief Disable info debug level.
 *  
 * @param _module Module name. Eg., \c ILPS22QS.
 * 
 * \ingroup sDebug
 */
#define sDEBUG_DISABLE_INFO(_module) \
	static constexpr auto& _module ## _PRINTN_INFO = sDebug::__dummy; \
	static constexpr auto& _module ## _PRINT_INFO = sDebug::__dummy; \
	static constexpr auto& _module ## _PRINTF_INFO = sDebug::__dummy;	
	
/**
 * @brief Disable error debug level.
 *  
 * @param _module Module name. Eg., \c ILPS22QS.
 * 
 * \ingroup sDebug
 */
#define sDEBUG_DISABLE_ERROR(_module) \
	static constexpr auto& _module ## _PRINTN_ERROR = sDebug::__dummy; \
	static constexpr auto& _module ## _PRINT_ERROR = sDebug::__dummy; \
	static constexpr auto& _module ## _PRINTF_ERROR = sDebug::__dummy;	



#endif // _SDEBUG_HPP_


// END WITH NEW LINE
