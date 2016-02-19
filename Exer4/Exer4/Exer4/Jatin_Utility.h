//
//�y�t�@�C�����z Jatin_Utility.h
//
//�y  �T  �v  �z Contains the various utility functions that are used. 
//
//�y �X�V���� �z 2010/10/07	Jatin Mistry
//
////////////////////////////////////////////////////////////////////////////////
//Header file
#include <stdlib.h>

#define BOOL   int	//Boolean return type
#define	TRUE   1	//Success
#define	FALSE  0	//Failure

//-----------------------------------------------------------------------------
//�y�֐����z FileClose
//
//�y��  �e�z used for closing the file.
//
//�y��  ���z [i] fpFile : the file pointer.
//
//�y�߂�l�z returns nothing.
//
//�y��  ���z 2010/10/07	Jatin Mistry
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
//�y�֐����z GetFileName
//
//�y��  �e�z used for getting the file name from full path.
//
//�y��  ���z [i] pszFilePath		: the full path of the file.
//			 [o] pszFileName		: the file name with extention.
//			 [i] nBuffSize			: the size of buffer to store.
//
//�y�߂�l�z returns TRUE(1) on success,otherwise FALSE(0).
//
//�y��  ���z 2010/10/26	Jatin Mistry
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