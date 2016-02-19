//
//ÅyÉtÉ@ÉCÉãñºÅz Exer4.c
//
//Åy  äT  óv  Åz Read the text file and make a copy of the file.
//				 	
//Åy çXêVóöó Åz 2010/10/08	Jatin Mistry
//
///////////////////////////////////////////////////////////////////////////////
//Header file
#include "Exer4.h"

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz CopyFile
//
//Åyì‡  óeÅz Copy the file.
//
//Åyà¯  êîÅz [i] fpSrcFile		: the source file pointer.
//			 [i] fpDestFile		: the destination file pointer. 
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success, otherwise FALSE(0)
//
//Åyóö  óÅz 2010/10/08	Jatin Mistry
//-----------------------------------------------------------------------------
BOOL CopyFile(FILE* fpSrcFile, FILE* fpDestFile)
{
	char szStrBuff[MAX_STR_LEN] = {0};	//Buffer string

	//Check input
	if(fpSrcFile == NULL || fpDestFile == NULL)
	{
		return FALSE;
	}
	
	//Copy
	while(fread(szStrBuff, sizeof(char), sizeof(szStrBuff), fpSrcFile) > 0)
	{
		fwrite(szStrBuff, sizeof(char), sizeof(szStrBuff), fpDestFile);
	}
	return TRUE;
}

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz Copy
//
//Åyì‡  óeÅz Open Destination file and copies the contents of Source file
//
//Åyà¯  êîÅz [i] fpSrcFile			: the source file pointer.
//			 [i] pszDestFilePath	: the destination file path. 
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success, otherwise FALSE(0)
//
//Åyóö  óÅz 2010/10/26	Jatin Mistry
//-----------------------------------------------------------------------------
BOOL Copy(FILE* fpSrcFile, char* pszDestFilePath)
{
	FILE* fpDestFile = NULL;				//File pointer for destination file.
	BOOL bReturn = FALSE;					//Boolean return from GetFileName
	BOOL bReturnCopy = FALSE;				//Boolean return from CopyFile
	char szFileName[MAX_FILENAME_LEN] = {0};//Store file name with ext.

	//Check input
	if(fpSrcFile == NULL || pszDestFilePath == NULL)
	{
		return FALSE;
	}

	//Open destination file
	fpDestFile = fopen(pszDestFilePath, WRITE_MODE);

	if(fpDestFile == NULL) 
	{
		//Splitpath
		bReturn = GetFileName(pszDestFilePath, szFileName, sizeof(szFileName));

		//Print error message
		bReturn ? printf(FILE_OPEN_ERR, szFileName) : printf(INTERNAL_ERR);
		//Close Source File
		FileClose(fpSrcFile);
		return FALSE;
	}
	//Copy
	bReturnCopy = CopyFile(fpSrcFile, fpDestFile);
	if(!bReturnCopy)
	{
		//Closing Destination File
		FileClose(fpDestFile);
		return FALSE;
	}

	//Closing Destination File
	FileClose(fpDestFile);
	return TRUE;
}

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz main
//
//Åyì‡  óeÅz used for reading from source file and copying at destination file.
//			 	
//Åyà¯  êîÅz [i] nArgc				: gives the number of arguments passed. 
//			 [i] pszArgv[]			: store the arguments passed.
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success, otherwise FALSE(0)
//
//Åyóö  óÅz 2010/10/08	Jatin Mistry
//-----------------------------------------------------------------------------
int main(int nArgc, char* pszArgv[])
{
	FILE* fpFileSrc = NULL;					//File pointer for source file.
	BOOL bReturn = FALSE;					//Boolean return from GetFileName
	char szFileName[MAX_FILENAME_LEN] = {0};//Store file name with ext.
	char szPrgName[MAX_FILENAME_LEN] = {0};	//Store program name.
	int nChoice = 0;						//User choice.

	//Check the arguments
	if(nArgc != MAX_ARG)
	{
		//Splitpath to get program name
		bReturn = GetFileName(pszArgv[ARG_PRGPATH], szPrgName, sizeof(szPrgName));
		if(bReturn)
		{
			//Show proper usage
			printf(START_WITHOUT_ARG, szPrgName);
			printf(USAGE, szPrgName);
			return FALSE;
		}
		printf(REQUEST_ARG);
		return FALSE;
	}

	//Open source file in read mode.
	fpFileSrc = fopen(pszArgv[ARG_SRCFILE], READ_MODE);

	//If the file does not exist
	if (fpFileSrc == NULL) 
	{
		//Splitpath
		bReturn = GetFileName(pszArgv[ARG_SRCFILE], szFileName, sizeof(szFileName));
		
		//Print error message
		bReturn ? printf (FILE_OPEN_ERR, szFileName) : printf (INTERNAL_ERR);
		return FALSE;
	}

	/* Check for existence */
	if( (_access(pszArgv[ARG_DESTFILE], MODE_ACCESS)) == -1 )
	{
		bReturn = Copy(fpFileSrc, pszArgv[ARG_DESTFILE]);
		if(bReturn == FALSE)
		{
			//Closing Source File.
			FileClose(fpFileSrc);
			return FALSE;
		}
		//Closing Source File.
		FileClose(fpFileSrc);
		return TRUE;
	}

	//File already exist
	printf(MSG_EXIST);
	printf(MSG_MENU);
	printf(MSG_YES);
	printf(MSG_NO);
	printf(MSG_CHOICE);
	scanf(INT_FORM,&nChoice);

	switch(nChoice)
	{
		case 1:	
				bReturn = Copy(fpFileSrc, pszArgv[ARG_DESTFILE]);
				if(bReturn == FALSE)
				{
					//Closing Source File.
					FileClose(fpFileSrc);
					return FALSE;
				}
				//Closing Source File.
				FileClose(fpFileSrc);
				return TRUE;
		case 2:
				break;
		default: 
				printf(MSG_INVALID);
				break;
	}
	
	//Closing Source File.
	FileClose(fpFileSrc);
	return FALSE;
}



