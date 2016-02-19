//
//ÅyÉtÉ@ÉCÉãñºÅz Exer1.c
//
//Åy  äT  óv  Åz Read the text file and display it in the standard output
//				 	
//Åy çXêVóöó Åz 2010/10/07	Jatin Mistry
//
///////////////////////////////////////////////////////////////////////////////
//Header file
#include "Exer1.h"

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz main
//
//Åyì‡  óeÅz used for reading and displaying the text file specified 
//			 at the time of start-up.
//			 	
//Åyà¯  êîÅz [i] nArgc			: gives the no. of arguments passed. 
//			 [i] pszArgv[]		: store the arguments passed.
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success, otherwise FALSE(0)
//
//Åyóö  óÅz 2010/10/07	Jatin Mistry
//-----------------------------------------------------------------------------
int main(int nArgc, char* pszArgv[])
{					
	BOOL bReturn = 0;						//Boolean return from GetFileName
	char szMystring[MAX_STR_LEN] = {0};		//Store the string from file.
	char szFileName[MAX_FILENAME_LEN] = {0};//Store file name with ext.
	char szPrgName[MAX_FILENAME_LEN] = {0};	//Store program name.
	FILE* fpFile = NULL;					//File pointer
	
	//Check if sufficient arguments are passed.
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
	//Open the file.
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

	//Read the contents of the file and print. 
	while(fgets(szMystring, sizeof(szMystring), fpFile) != NULL)
	{
		printf(STRING_FORM, szMystring);
	}

	//Close the file.
	FileClose(fpFile);
	return TRUE;
}