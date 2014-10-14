#ifndef __WILC_platfrom_H__
#define __WILC_platfrom_H__

/*!  
*  @file	WILC_platform.h
*  @brief	platform specific file, when creating OS wrapper for a 
		new platform start wih this file
*  @author	syounan
*  @sa		WILC_OSWrapper.h top level OS wrapper file
*  @date	10 Aug 2010
*  @version	1.0
*/


/******************************************************************
        Feature support checks
*******************************************************************/
/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_THREAD_FEATURE
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_THREAD_SUSPEND_CONTROL
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_THREAD_STRICT_PRIORITY
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_SEMAPHORE_FEATURE
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_SEMAPHORE_TIMEOUT
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_SLEEP_FEATURE
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_SLEEP_HI_RES
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_TIMER_FEATURE
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_TIMER_PERIODIC
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_MEMORY_FEATURE
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_MEMORY_POOLS
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_MEMORY_DEBUG
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_ASSERTION_SUPPORT
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_STRING_UTILS
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_MSG_QUEUE_FEATURE
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_MSG_QUEUE_IPC_NAME
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_MSG_QUEUE_TIMEOUT
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_FILE_OPERATIONS_FEATURE
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_FILE_OPERATIONS_STRING_API
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_FILE_OPERATIONS_PATH_API
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_TIME_FEATURE
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_TIME_UTC_SINCE_1970
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_TIME_CALENDER
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_EVENT_FEATURE
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_EVENT_TIMEOUT
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_MATH_OPERATIONS_FEATURE
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_EXTENDED_FILE_OPERATIONS
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_EXTENDED_STRING_OPERATIONS
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_EXTENDED_TIME_OPERATIONS
#error This feature is not supported by this OS
#endif

/* remove the following block when implementing its feature */
#ifdef CONFIG_WILC_SOCKET_FEATURE
#error This feature is not supported by this OS
#endif

/******************************************************************
	OS specific includes
*******************************************************************/


/******************************************************************
	OS specific types
*******************************************************************/

/* change into OS specific type */
typedef void* WILC_ThreadHandle;

/* change into OS specific type */
typedef void* WILC_SemaphoreHandle;

/* change into OS specific type */
typedef void* WILC_TimerHandle;

/* change into OS specific type */
typedef void* WILC_MemoryPoolHandle;

/* change into OS specific type */
typedef void* WILC_MsgQueueHandle;

/* change into OS specific type */
typedef void* WILC_FileHandle;

/* change into OS specific type */
typedef void* WILC_EventHandle;

/*******************************************************************
	others
********************************************************************/

/* Generic printf function, map it to the standard printf */
#define WILC_PRINTF(...)
#define __WILC_FILE__
#define __WILC_FUNCTION__
#define __WILC_LINE__
#endif
