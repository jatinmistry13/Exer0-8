//
//ÅyÉtÉ@ÉCÉãñºÅz Exer2.c
//
//Åy  äT  óv  Åz Read the text file and display the line matching with 
//				 character string specified in command line in the 
//				 standard output
//
//Åy çXêVóöó Åz 2010/10/07	Jatin Mistry
//
///////////////////////////////////////////////////////////////////////////////
//Header file
#include "Exer2.h"

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz main
//
//Åyì‡  óeÅz Used for reading and displaying the line matching with character
//			 string specified in the Command line in standard output.
//			  	
//Åyà¯  êîÅz [i] nArgc					: gives the no. of arguments passed. 
//			 [i] pszArgv[]				: store the arguments passed.
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success, otherwise FALSE(0)
//
//Åyóö  óÅz 2010/10/07	Jatin Mistry
//-----------------------------------------------------------------------------
int main(int nArgc, char* pszArgv[])
{
	BOOL bReturn = FALSE;					//Boolean return from GetFileName
	char szMystring[MAX_STR_LEN] = {0};		//Stores line to be matched.
	char szFileName[MAX_FILENAME_LEN] = {0};//Store file name with ext.
	char szPrgName[MAX_FILENAME_LEN] = {0};	//Store program name.
	char* pszLoc = NULL;					//Gives location of match.
	FILE* fpFile = NULL;					//File pointer

	//Argument check for no arguments specified.
	if(nArgc != MAX_ARG)
	{
		//Splitpath to get program name
		bReturn = GetFileName(pszArgv[ARG_PRGPATH], 
							  szPrgName, 
							  sizeof(szPrgName));
		if(bReturn)
		{
			printf(START_WITHOUT_ARG, szPrgName);
			printf(USAGE, szPrgName);
			return FALSE;
		}
		printf(REQUEST_ARG);
		return FALSE;
	}

	//Open file.
	fpFile = fopen(pszArgv[ARG_FILEPATH], READ_MODE);
	
	//If the file does not exist
	if (fpFile == NULL) 
	{
		//Splitpath
		bReturn = GetFileName(pszArgv[ARG_FILEPATH], 
							  szFileName, 
							  sizeof(szFileName));
		
		//Print error message
		bReturn ? printf(FILE_OPEN_ERR, szFileName) : printf(INTERNAL_ERR);
		return FALSE;
	}
	
	//Reads the characters
	while(fgets(szMystring, sizeof(szMystring), fpFile) != NULL)		
	{	
		//Gives the position of first occurrence of search string
		pszLoc = strstr(szMystring, pszArgv[ARG_SRCHSTR]);		 
				
		//Value other than NULL is given than display the string
		if(pszLoc != NULL)						
		{
			puts(szMystring);
		}
	}
	
	//Close file.
	FileClose(fpFile);
	return TRUE;
}	
	

