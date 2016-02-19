//
//ÅyÉtÉ@ÉCÉãñºÅz Exer8.c
//
//Åy  äT  óv  Åz Replace any character string in a text file with any other 
//				 character string.	
//
//Åy çXêVóöó Åz 2010/10/19 Jatin Mistry
//
///////////////////////////////////////////////////////////////////////////////
//Header file
#include "Exer8.h"

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz FreeMemory
//
//Åyì‡  óeÅz Deallocates or frees a memory block.
//
//Åyà¯  êîÅz [i] pMemBlock : Previously allocated memory block to be freed 
//
//ÅyñﬂÇËílÅz returns nothing.
//
//Åyóö  óÅz 2010/10/26	Jatin Mistry
//-----------------------------------------------------------------------------
void FreeMemory(void* pMemBlock)
{
	//Check Input Parameter
	if(pMemBlock == NULL)
	{
		return;
	}
	free(pMemBlock);
	pMemBlock = NULL;
}

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz FileRead
//
//Åyì‡  óeÅz For reading a file and storing its contents.
//
//Åyà¯  êîÅz [i] pszFilePath: Path of file to read.
//			 [o] pszSource	: The string to store contents of file.
//
//ÅyñﬂÇËílÅz returns ERR_SUCCESS(0) on success, otherwise Error
//
//Åyóö  óÅz 2010/10/19 Jatin Mistry
//-----------------------------------------------------------------------------
ErrorCode FileRead(char* pszFilePath, char** pszSource)
{
	char szFileName[MAX_FILENAME_LEN] = {0};//File Name
	char pszTemp[MAX_STR_LEN] = {0};		//Temp string
	int nOriginal = 0;						//Original length
	int nTempLen = 0;						//Length of Temp String
	FILE* fpFile = NULL;					//File Pointer
	BOOL bReturn = FALSE;					//Boolean return value

	//Check input arguments
	if(pszFilePath == NULL || *pszSource == NULL)
	{
		return ERR_FILEREAD_ARGUMENT;
	}

	//Open file in read mode to read the data.
	fpFile = fopen(pszFilePath, READ_MODE);

	//Check if its open properly
	if (fpFile == NULL) 
	{
		//Splitpath
		bReturn = GetFileName(pszFilePath, szFileName, sizeof(szFileName));

		//Print error message
		bReturn ? printf (FILE_OPEN_ERR, szFileName) : printf (INTERNAL_ERR);
		return ERR_FILEREAD_FILE_OPEN;
	}

	//reset to remove garbage 
	memset(*pszSource, 0, sizeof(char));

	//Read the file and store contents in pszSource
	while(fgets(pszTemp, sizeof(pszTemp), fpFile) != NULL)
	{
		//Get the length of read data
		nTempLen = strlen(pszTemp);
		//Add the length with existing length
		nOriginal = nOriginal + nTempLen;
		//Allocate proper memory
		*pszSource = (char*) realloc (*pszSource, nOriginal + 1);
		if(*pszSource == NULL)
		{
			return ERR_FILEREAD_REALLOC;
		}
		//Concat data
		strcat(*pszSource, pszTemp);
		//Reset pszBase for new read
		memset(pszTemp, CHAR_SET, strlen(pszTemp));
	}

	//when no further reading left, close the file.
	FileClose(fpFile);	

	return ERR_SUCCESS;
}

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz FileWrite
//
//Åyì‡  óeÅz For writing ito the file the string specified.
//
//Åyà¯  êîÅz [i] pszFilePath: Path of the file to write in.
//			 [i] pszBuffer	: the string to be written.
//
//ÅyñﬂÇËílÅz returns ERR_SUCCESS(0) on success, otherwise Error
//
//Åyóö  óÅz 2010/10/19 Jatin Mistry
//-----------------------------------------------------------------------------
ErrorCode FileWrite(char* pszFilePath, char** pszBuffer)
{
	FILE* fpFile = NULL;					//File Pointer
	char szFileName[MAX_FILENAME_LEN] = {0};//File Name
	BOOL bReturn = FALSE;					//Boolean return 

	//Check input arguments
	if(pszFilePath == NULL || *pszBuffer == NULL)
	{
		return ERR_FILEWRITE_ARGUMENT;
	}

	//Open file in write mode to write the data.
	fpFile = fopen(pszFilePath, WRITE_MODE);

	//Check if its open properly
	if (fpFile == NULL) 
	{
		//Splitpath
		bReturn = GetFileName(pszFilePath, szFileName, sizeof(szFileName));

		//Print error message
		bReturn ? printf (FILE_OPEN_ERR, szFileName) : printf (INTERNAL_ERR);
		return ERR_FILEWRITE_FILE_OPEN;
	}

	//write the contents of pszBuffer in File
	fputs(*pszBuffer, fpFile);

	//close the file
	FileClose(fpFile);

	return ERR_SUCCESS;
}

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz StringReplace
//
//Åyì‡  óeÅz For replacing all occurrences of a character string with any
//			 other character string.
//
//Åyà¯  êîÅz [i] pszSource	: the source string.
//			 [i] pszSrch	: string to be searched for replacement.
//			 [i] pszReplace	: string to replace the searched string.
//			 [o] pszBuffer	: the output after replacement.
//			 [o] pbMatch	: pointer to check match found or not
//
//ÅyñﬂÇËílÅz returns ERR_SUCCESS(0) on success, otherwise Error
//
//Åyóö  óÅz 2010/10/19 Jatin Mistry
//-----------------------------------------------------------------------------
ErrorCode StringReplace(char* pszSource, char* pszSrch, 
						char* pszReplace, char** pszBuffer, BOOL* pbMatch)
{
	int nSourceLen = 0;		//Length of Source String
	int nSrchLen = 0;		//Length of Search String
	int nRepLen = 0;		//Length of Replace String
	int nOriginal = 0;		//Original length 
	char* pszLoc = NULL;	//Gives Location of Match
	char* pszSrcTemp = NULL;//Stores the initial location  of Source string

	//Check input arguments
	if(pszSource == NULL||
	   pszSrch == NULL || 
	   pszReplace == NULL || 
	   *pszBuffer == NULL ||
	   *pbMatch == TRUE )
	{
		return ERR_STRINGREPLACE_ARGUMENT;
	}

	//Calculate the length of the strings
	nSourceLen = strlen(pszSource);
	nSrchLen = strlen(pszSrch);
	nRepLen = strlen(pszReplace);

	//Store the initial location of Source String
	pszSrcTemp = pszSource;

	//reset to remove garbage 
	memset(*pszBuffer, 0, sizeof(char));

	//Do replacement
	while(strstr(pszSource, pszSrch))
	{
		//Get location of match
		pszLoc = strstr(pszSource, pszSrch);

		//Calculate size of reallocation
		nOriginal = nOriginal + (pszLoc - pszSource) + nRepLen;

		//Allocate memory
		*pszBuffer = (char*)realloc(*pszBuffer, nOriginal + 1);

		if(*pszBuffer == NULL)
		{ 
			return ERR_STRINGREPLACE_REALLOC;
		}

		//Copy the string before the match into buffer string.
		strncat(*pszBuffer, pszSource, pszLoc - pszSource);

		//Concatenate the bufer string with replacement string
		strcat(*pszBuffer, pszReplace);

		//Move the location of match
		pszLoc = pszLoc + strlen(pszSrch);

		//Move the location of base string pointer.
		pszSource = pszLoc;

		*pbMatch = TRUE;
	}

	//Allocate memory for Storage
	*pszBuffer = (char*)realloc(*pszBuffer, (nOriginal + strlen(pszSource) +1));
	if(*pszBuffer == NULL)
	{ 
		return ERR_STRINGREPLACE_REALLOC;
	}
	//Concat 
	strcat(*pszBuffer, pszSource);

	pszSource = pszSrcTemp;

	return ERR_SUCCESS;
}

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz main
//
//Åyì‡  óeÅz For replacing any character string in a text file with any other 
//			 character string.
//			 	
//Åyà¯  êîÅz [i] nArgc				: gives the no. of arguments passed. 
//			 [i] pszArgv[]			: store the arguments passed.
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success, otherwise FALSE(0)
//
//Åyóö  óÅz 2010/10/26 Jatin Mistry.
//-----------------------------------------------------------------------------
int main(int nArgc, char* pszArgv[])
{
	FILE* fpFile = NULL;					//make a function for file display
	char szPrgName[MAX_FILENAME_LEN] = {0};	//Program Name
	char szFileName[MAX_FILENAME_LEN] = {0};//File Name			
	ErrorCode errReturn = 0;				//Error value
	char* pszSource = NULL;					//Source String
	char* pszBuffer = NULL;					//Buffer String
	BOOL bMatch = FALSE;					//Check Match 

	//Check input arguments
	if(nArgc != MAX_ARG)
	{
		//Splitpath to get program name
		if(GetFileName(pszArgv[ARG_PRGPATH], szPrgName, sizeof(szPrgName)) == FALSE)
		{
			printf(START_WITHOUT_ARG, szPrgName);
			printf(USAGE, szPrgName);
			return FALSE;
		}
		printf(REQUEST_ARG);
		return FALSE;
	}

	pszSource = (char*) malloc (sizeof(char));
	//Check if malloc allocated properly
	if(	pszSource == NULL)
	{
		FreeMemory(pszSource);
		DispErrMsg(ERR_MAIN_MALLOC);
		return FALSE;
	}

	pszBuffer = (char*) malloc (sizeof(char));
	//Check if malloc allocated properly
	if(	pszBuffer == NULL)
	{ 
		FreeMemory(pszBuffer);
		DispErrMsg(ERR_MAIN_MALLOC);
		return FALSE;
	}

	//Read the file
	errReturn = FileRead(pszArgv[ARG_FILEPATH], &pszSource);
	if(errReturn != ERR_SUCCESS)
	{
		//free memory
		FreeMemory(pszSource);
		FreeMemory(pszBuffer);
		//Display error message
		DispErrMsg(errReturn);
		return FALSE;
	}
	
	//Perform replacement
	errReturn = StringReplace(pszSource, 
							  pszArgv[ARG_SRCH_STR], 
							  pszArgv[ARG_REP_STR], 
							  &pszBuffer,
							  &bMatch);

	//When no match found
	if(bMatch == FALSE)
	{
		errReturn = ERR_STRINGREPLACE_NO_MATCH_FOUND;
		//Display error message
		DispErrMsg(errReturn);
		return FALSE;
	}

	if(errReturn != ERR_SUCCESS)
	{
		//free memory
		FreeMemory(pszSource);
		FreeMemory(pszBuffer);
		//Display error message
		DispErrMsg(errReturn);
		return FALSE;
	}
	//free memory
	FreeMemory(pszSource);

	//Write into the file
	errReturn = FileWrite(pszArgv[ARG_FILEPATH], &pszBuffer);
	if(errReturn != ERR_SUCCESS)
	{
		//free memory
		FreeMemory(pszBuffer);
		//Display error message
		DispErrMsg(errReturn);
		return FALSE;
	}

	//free memory
	FreeMemory(pszBuffer);
	
	return TRUE;
}



