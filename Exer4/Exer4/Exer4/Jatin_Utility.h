//
//ÅyÉtÉ@ÉCÉãñºÅz Jatin_Utility.h
//
//Åy  äT  óv  Åz Contains the various utility functions that are used. 
//
//Åy çXêVóöó Åz 2010/10/07	Jatin Mistry
//
////////////////////////////////////////////////////////////////////////////////
//Header file
#include <stdlib.h>

#define BOOL   int	//Boolean return type
#define	TRUE   1	//Success
#define	FALSE  0	//Failure

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz FileClose
//
//Åyì‡  óeÅz used for closing the file.
//
//Åyà¯  êîÅz [i] fpFile : the file pointer.
//
//ÅyñﬂÇËílÅz returns nothing.
//
//Åyóö  óÅz 2010/10/07	Jatin Mistry
//-----------------------------------------------------------------------------
void FileClose(FILE* fpFile)
{
	//Check Input Parameter
	if(fpFile == NULL)
	{
		return;
	}
	fclose(fpFile);
	fpFile = NULL;
}
//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz GetFileName
//
//Åyì‡  óeÅz used for getting the file name from full path.
//
//Åyà¯  êîÅz [i] pszFilePath		: the full path of the file.
//			 [o] pszFileName		: the file name with extention.
//			 [i] nBuffSize			: the size of buffer to store.
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success,otherwise FALSE(0).
//
//Åyóö  óÅz 2010/10/26	Jatin Mistry
//-----------------------------------------------------------------------------
BOOL GetFileName(char* pszFilePath, char* pszFileName, int nBuffSize)
{	
	char szFname[_MAX_FNAME] = {0};		// file name
	char szExt[_MAX_EXT] = {0};			// file extention
	
	//Check Input Parameter
	if(pszFilePath == NULL || pszFileName == NULL || nBuffSize <= 0)
	{
		return FALSE;
	}
	//Split path
	_splitpath(pszFilePath, NULL, NULL, szFname, szExt);
	
	//Copy file name 
	strncpy(pszFileName, szFname, nBuffSize);
	
	if(strlen(pszFileName) < nBuffSize)
	{
		//Concatenate file name with extention
		strncat(pszFileName, szExt, (strlen(pszFileName) - nBuffSize));
	}
	
	return TRUE;	
}