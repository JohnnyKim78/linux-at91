#ifndef __WILC_SOCKET_H__
#define __WILC_SOCKET_H__

/*!  
*  @file		WILC_Socket.h
*  @brief		Socket Connection functionality
*  @author		remil
*  @sa			WILC_OSWrapper.h top level OS wrapper file
*  @date		19 Oct 2010
*  @version		1.0
*/

#ifndef CONFIG_WILC_SOCKET_FEATURE
#error the feature CONFIG_WILC_SOCKET_FEATURE must be supported to include this file
#endif


/*!
*	Maximum length of IP address
*/
#define MAX_IP_LENGTH 16

/*============================================================================*/
/*!
*  @struct 		tpfWILC_TcpReceptionCB
*  @brief		
*  @author		remil
*  @date		19 Oct 2010
*  @version		1.0
*/
/*============================================================================*/
typedef void (*tpfWILC_TcpReceptionCB)(WILC_Uint8* pu8Buffer,
									  WILC_Uint32 u32ReceivedDataLength,
									  void* vpUserData);
/*============================================================================*/
/*!
*  @struct 		tstrTcpConnection
*  @brief		
*  @author		remil
*  @date		19 Oct 2010
*  @version		1.0
*/
/*============================================================================*/
typedef struct _tstrTcpConnection
{
	WILC_Uint32 u32SocketFd;
	WILC_Sint32 s32Port;
	WILC_Char cpIPAddress[MAX_IP_LENGTH];
	tpfWILC_TcpReceptionCB fpTcpReceptionCB;
	WILC_ThreadHandle strThreadHandle;
	tstrWILC_ThreadAttrs strThreadAttrs;
	void* vpUserData;

}tstrTcpConnection;


/*============================================================================*/
/*!
*  @brief		
*  @return		
*  @note		
*  @author		remil
*  @date		19 Oct 2010
*  @version		1.0
*/
/*============================================================================*/
WILC_ErrNo WILC_TcpConnect(tstrTcpConnection* pstrTcpConnection);

/*============================================================================*/
/*!
*  @brief		
*  @return		
*  @note		
*  @author		remil
*  @date		19 Oct 2010
*  @version		1.0
*/
/*============================================================================*/
void WILC_TcpDisconnect(tstrTcpConnection* pstrTcpConnection);

/*============================================================================*/
/*!
*  @brief		
*  @return		
*  @note		
*  @author		remil
*  @date		19 Oct 2010
*  @version		1.0
*/
/*============================================================================*/
WILC_ErrNo WILC_TcpSend(tstrTcpConnection* pstrTcpConnection,
				  WILC_Uint8* u8Buf,
				  WILC_Uint32 u32DataSize);

#endif
