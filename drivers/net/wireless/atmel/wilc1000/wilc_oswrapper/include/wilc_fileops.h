#ifndef __WILC_FILEOPS_H__
#define __WILC_FILEOPS_H__

/*!  
*  @file	FileOps.h
*  @brief	File Operations OS wrapper functionality
*  @author	syounan
*  @sa		WILC_OSWrapper.h top level OS wrapper file
*  @date	31 Aug 2010
*  @version	1.0
*/

#ifndef CONFIG_WILC_FILE_OPERATIONS_FEATURE
#error the feature CONFIG_WILC_FILE_OPS_FEATURE must be supported to include this file
#endif


typedef enum{
	WILC_FILE_READ_ONLY,
	WILC_FILE_READ_WRITE_EXISTING,
	WILC_FILE_READ_WRITE_NEW
}tenuWILC_AccessMode;

typedef enum{
	WILC_SEEK_FROM_START,
	WILC_SEEK_FROM_END,
	WILC_SEEK_FROM_CURRENT
}tenuWILC_SeekOrigin;

/*!
*  @struct 		tstrWILC_FileOpsAttrs
*  @brief		Message Queue API options
*  @author		syounan
*  @date		30 Aug 2010
*  @version		1.0
*/
typedef struct
{
	/*!< access mode of the file, default is READ_WRITE_EXISTING */
	tenuWILC_AccessMode enuAccess;
	
	/*!< origin for seeking operations, default is WILC_FILE_SEEK_CUR */
	tenuWILC_SeekOrigin enuSeekOrigin;
	
}tstrWILC_FileOpsAttrs;

/*!
*  @brief		Fills the MsgQueueAttrs with default parameters
*  @param[out]	pstrAttrs structure to be filled
*  @sa			WILC_TimerAttrs
*  @author		syounan
*  @date		30 Aug 2010
*  @version		1.0
*/
static void WILC_FileOpsFillDefault(tstrWILC_FileOpsAttrs* pstrAttrs)
{
	pstrAttrs->enuAccess = WILC_FILE_READ_WRITE_EXISTING;
	pstrAttrs->enuSeekOrigin = WILC_SEEK_FROM_CURRENT;
}


/**
*  @brief 		Opens a file
*  @details 	Opens a file, possibly creating a new file if write enabled and
 				pstrAttrs->bCreate is set to true
*  @param[in,out] pHandle Handle to the opened file
*  @param[in] 	pcPath path to the File
*  @param[in] 	pstrAttrs Optional attributes, NULL for defaults. bCreate will 
				create the file if does not exit, enuAccess will control access 
				mode
*  @return 		Error code indicating success/failure
*  @note 		Original Standard Function: 
				FILE *fopen( const char *filename, const char *mode );
*  @author		syounan
*  @date		30 Aug 2010
*  @version		1.0
*/
WILC_ErrNo WILC_fopen(WILC_FileHandle* pHandle, const WILC_Char* pcPath, 
	tstrWILC_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Closes a file.
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	pstrAttrs Optional attributes, NULL for default.
 * @return 		Error code indicating success/failure
 * @note 		Original Standard Function: int fclose( FILE *stream );
*  @author		syounan
*  @date		30 Aug 2010
*  @version		1.0 
 */
WILC_ErrNo WILC_fclose(WILC_FileHandle* pHandle, tstrWILC_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Reads data from a file.
 * @param[in] 	pHandle Handle to the file object
 * @param[out] 	pu8Buffer Storage location for data
 * @param[in] 	u32Size Number of bytes to be read
 * @param[in] 	pstrAttrs Optional attributes, NULL for default. 
 * @return 		Returns the number of bytes actually read, which may be less 
 				than count if an error occurs or if the end of the file is 
				encountered before reaching count.
				Use the WILC_feof function to distinguish a read error from an 
				end-of-file condition.
				If size or count is 0, WILC_fread returns 0 and the buffer 
				contents are unchanged.
 * @note 		Original Standard Function: 
 	size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0 
 */
WILC_Uint32 WILC_fread(WILC_FileHandle* pHandle, WILC_Uint8* pu8Buffer, 
				WILC_Uint32 u32Size, tstrWILC_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Writes data to a FILE.
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	pu8Buffer Storage location for data
 * @param[in] 	u32Size Number of bytes to be write
 * @param[in] 	pstrAttrs Optional attributes, NULL for default. 
 * @return 		Returns the number of full items actually written, which may be
				less than count if an error occurs
				Also, if an error occurs, the file-position indicator cannot be 
				determined.
 * @note 		Original Standard Function: 
 	size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0  
 */
WILC_Uint32 WILC_fwrite(WILC_FileHandle* pHandle, WILC_Uint8* pu8Buffer, 
				WILC_Uint32 u32Size, tstrWILC_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Tests for end-of-file
 * @param[in] 	pHandle Handle to the file object
 * @retval		WILC_FALSE if the current position is not end of file
 * @retval		WILC_TRUE after the first read operation that attempts to read past
				the end of the file.
 * @note 		Original Standard Function: int feof( FILE *stream );
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0
 */
WILC_Bool WILC_feof(WILC_FileHandle* pHandle);

/**
 * @brief 		Moves the file pointer to a specified location.
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	s32Offset Number of bytes to move, origin of seeking depends on
				pstrAttrs->enuSeekOrigin, if pstrAttrs is NULL then origin is the 
				current position at the file
 * @param[in] 	pstrAttrs Optional attributes, NULL for default. 
 				enuSeekOrigin defines the origin of seek operations 
 * @return 		Error code indicating success/failure
 * @note 		Original Standard Function:
				int fseek( FILE *stream, long offset, int origin );
 */
WILC_ErrNo WILC_fseek(WILC_FileHandle* pHandle, WILC_Sint32 s32Offset, 
		tstrWILC_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Gets the current position of a file pointer.
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	pstrAttrs Optional attributes, NULL for default.
 * @return 		Returns the current file position. Or WILC_FAIL on error.
 * @note 		Original Standard Function: long ftell( FILE *stream );
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0 
 */
WILC_Uint32 WILC_ftell(WILC_FileHandle* pHandle, tstrWILC_FileOpsAttrs* pstrAttrs);


/**
 * @brief 		Flushes the file, writing all data that may be in buffers
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	pstrAttrs Optional attributes, NULL for default. 
 * @return 		Error code indicating success/failure
 * @note 		Original Standard Function: int fflush( FILE *stream );
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0 
 */
WILC_ErrNo WILC_fflush(WILC_FileHandle* pHandle, tstrWILC_FileOpsAttrs* pstrAttrs);



/**
 * @brief 		Gets the size of the file.
 * @param[in] 	pHandle Handle to the file object
 * @param[out] 	pu32Size returned size of file in question
 * @param[in] 	pstrAttrs Optional attributes, NULL for default.
 * @return 		Error code indicating success/failure
 * @note 		
 * @author		remil
 * @date		25 Oct 2010
 * @version		2.0 
 */
WILC_ErrNo WILC_FileSize(WILC_FileHandle* pstrFileHandle, WILC_Uint32* pu32Size,
	tstrWILC_FileOpsAttrs* pstrAttrs);



#ifdef CONFIG_WILC_EXTENDED_FILE_OPERATIONS
/**
 * @brief 		Returns the character currently pointed by the internal file position
 *				indicator of the specified stream. 
 *				The internal file position indicator is then advanced by one 
 *				character to point to the next character.
 * @param[in] 	WILC_FileHandle* pHandle
 * @return 		Returns the character currently pointed by the internal file position
 * @note 		Original Standard Function: int getc
 * @author		remil
 * @date		31 Oct 2010
 * @version		1.0 
 */
WILC_Sint32 WILC_getc(WILC_FileHandle* pHandle);


/**
 * @brief 		pushes the byte specified by c (converted to an unsigned char)
 *				back onto the input stream pointed to by stream.
 * @param[in]	WILC_Sint32 c
 * @param[in] 	WILC_FileHandle* pHandle
 * @return 		 returns the byte pushed back after conversion. Otherwise it returns EOF.
 * @note 		Original Standard Function:  ungetc
 * @author		remil
 * @date		31 Oct 2010
 * @version		1.0 
 */
WILC_Sint32 WILC_ungetc(WILC_Sint32 c,
					  WILC_FileHandle* pHandle);



/**
 * @author		remil
 * @date		31 Oct 2010
 * @version		1.0
 */
WILC_ErrNo WILC_freopen(WILC_FileHandle* pHandle, const WILC_Char* pcPath, 
	tstrWILC_FileOpsAttrs* pstrAttrs);

/**
*  @brief 		Translates character file open mode to the appropriate Enum Value
*  @details 	
*  @param[in] 	const WILC_Char* cpMode
*  @return 		tenuWILC_AccessMode
*  @note 		
*  @author		remil
*  @date		3 Nov 2010
*  @version		1.0
*/
tenuWILC_AccessMode WILC_resolveFileMode(const WILC_Char* cpMode);


/**
 * @author		remil
 * @date		31 Oct 2010
 * @version		1.0
 */
WILC_ErrNo WILC_rename(const WILC_Char *old_filename, const WILC_Char *new_filename);

WILC_ErrNo WILC_setbuf(WILC_FileHandle *pHandle, WILC_Char* buffer);


WILC_ErrNo WILC_setvbuf(WILC_FileHandle *pHandle, 
					  WILC_Char* buffer, 
					  WILC_Sint32 mode, 
					  WILC_Uint32 size);

/*
*Creates a temporary file in binary update mode (wb+). 
*The tempfile is removed when the program terminates or the stream is closed.
*On success a pointer to a file stream is returned. On error a null pointer is returned.
*/
WILC_ErrNo WILC_tmpfile(WILC_FileHandle *pHandle);


/*
 * Reads a line from the specified stream and stores it into the string pointed to by str.
 * It stops when either (n-1) characters are read,
 * the newline character is read, or the end-of-file is reached,
 * whichever comes first. The newline character is copied to the string.
 * A null character is appended to the end of the string.
 * On success a pointer to the string is returned. On error a null pointer is returned.
 * If the end-of-file occurs before any characters have been read, the string remains unchanged.
*/

//WILC_Char* WILC_fgets(WILC_Char* str, WILC_Sint32 n, WILC_FileHandle stream);


/**
*  @brief 		Clears the end-of-file and error indicators for the given stream.  
*  @details 	As long as the error indicator is set, 
				all stream operations will return an error until WILC_clearerr is called.
*  @param[in] 	WILC_FileHandle* pHandle
*  @return 		N/A
*  @note 		
*  @author		remil
*  @date		3 Nov 2010
*  @version		1.0
*/
void WILC_clearerr(WILC_FileHandle* pHandle);


/**
*  @brief 		Tests the error indicator for the given stream. 
*  @details 	If the error indicator is set, then it returns WILC_FAIL.
				If the error indicator is not set, then it returns WILC_SUCCESS.
*  @param[in] 	WILC_FileHandle* pHandle
*  @return 		WILC_ErrNo
*  @note 		
*  @author		remil
*  @date		3 Nov 2010
*  @version		1.0
*/
WILC_ErrNo WILC_ferror(WILC_FileHandle* pHandle);

/**
*  @brief 		Generates and returns a valid temporary filename which does not exist.
*  @details 	If the argument str is a null pointer, then the function returns 
				a pointer to a valid filename. 
				If the argument str is a valid pointer to an array,
				then the filename is written to the array and a pointer to the same array 
				is returned.The filename may be up to L_tmpnam characters long.
*  @param[in] 	WILC_Char* str
*  @return 		WILC_Char* 
*  @note 		
*  @author		remil
*  @date		3 Nov 2010
*  @version		1.0
*/
WILC_Char* WILC_tmpnam(WILC_Char* str);


#endif


#ifdef CONFIG_WILC_FILE_OPERATIONS_STRING_API

/**
 * @brief 		Reads a line.
 * @param[in] 	pHandle Handle to the file object
 * @param[out] 	pcBuffer Storage location for data
 * @param[in] 	u32Maxsize Maximum number of data to be read including NULL terminator
 * @return 		Error code indicating success/failure
 * @retval 		WILC_FILE_EOF If the End-of-File is encountered, no characters 
 				have been read and the contents of buffer remain unchanged
 * @retval 		WILC_FAIL If an error occurs, no characters 
 				have been read and the contents of buffer remain unchanged
 * @note 		Original Standard Function: 
 				char *fgets(char *s,int n,FILE *stream);
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0
 */
WILC_ErrNo WILC_fgets(WILC_FileHandle* pHandle, WILC_Char* pcBuffer
				, WILC_Uint32 u32Maxsize);

/**
 * @brief 		Prints formatted data to a stream
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	pcFormat Format-control string
 * @param[in]	... Optional arguments
 * @return 		Error code indicating success/failure
 * @note Original Standard Function: 
 				int fprintf( FILE *stream, const char *format, ... );
 */
WILC_ErrNo WILC_fprintf(WILC_FileHandle* pHandle, const WILC_Char* pcFormat, ...);

/**
 * @brief 		Writes formatted output using a pointer to a list of arguments
 * @param[in] 	pHandle Handle to the file object
 * @param[in] 	pcFormat Format specification
 * @param[in] 	argptr Pointer to list of arguments
 * @return 		Error code indicating success/failure
 * @note 		riginal Standard Function: 
 			int vfprintf( FILE *stream, const char *format, va_list argptr );
 * @author		syounan
 * @date		30 Aug 2010
 * @version		1.0
 */
WILC_ErrNo WILC_vfprintf(WILC_FileHandle* pHandle, const WILC_Char* pcFormat, 
				va_list argptr);

#endif

#ifdef CONFIG_WILC_FILE_OPERATIONS_PATH_API

/**
 * @brief 		Renames/Moves a file or directory
 * @param[in] 	pcOldPath the old path
 * @param[in] 	pcNewPath the new path
 * @param[in] 	pstrAttrs Optional attributes, NULL for default.
 * @return 		Error code indicating success/failure
 * @note 		if there is a file or folder exsiting in the new path, the 
 *				operation fails
 * @author		syounan
 * @date		31 Oct 2010
 * @version		2.0 
 */
WILC_ErrNo WILC_PathMove(WILC_Char* pcOldPath, WILC_Char* pcNewPath,
	tstrWILC_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Checks for the path exsitance
 * @details		Checks for the path exsitance, the path could be either a file or
				a directory, to test differentiate between files/directories 
				send a non-null poiter to the argument pbIsDirectory
 * @param[in] 	pcPath path of the examined file/directory
 * @param[out] 	pbIsDirectory set to WILC_TRUE if the path is directory, optional
				and could be WILC_NULL
 * @param[in] 	pstrAttrs Optional attributes, NULL for default.
 * @return 		WILC_TRUE if path exsits, WILC_FALSE if does not exist
 * @note 		if there is a file or folder exsiting in the new path, the 
 *				operation fails
 * @author		syounan
 * @date		31 Oct 2010
 * @version		2.0 
 */
WILC_Bool WILC_PathExsits(WILC_Char* pcPath, WILC_Bool* pbIsDirectory,
	tstrWILC_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		Deletes the given path
 * @details		Deletes the given path, wheather it is a file or a directory
 *				if it is a directory that contains other files and diretories, 
 *				they will be recusively deleted
 * @param[in] 	pcPath path to the File
 * @param[in] 	pstrAttrs Optional attributes, NULL for default. 
 * @return 		Error code indicating success/failure
 * @note 		if the path does not exist, the function returns an error
 * @author		mabubakr, syounan
 * @date		31 Oct 2010
 * @version		2.0 
 */
WILC_ErrNo WILC_PathDelete(WILC_Char* pcPath, tstrWILC_FileOpsAttrs* pstrAttrs);

/**
 * @brief 		creates a new directory
 * @details		creates a new directory in the given path, if a file or directory
				already exsits in this path the operation fails
 * @param[in] 	pcPath path to be created
 * @param[in] 	pstrAttrs Optional attributes, NULL for default. 
 * @return 		Error code indicating success/failure
 * @author		syounan
 * @date		31 Oct 2010
 * @version		2.0 
 */
WILC_ErrNo WILC_DirectoryCreate(WILC_Char* pcPath, tstrWILC_FileOpsAttrs* pstrAttrs);

#endif

#endif
