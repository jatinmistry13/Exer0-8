//
//ÅyÉtÉ@ÉCÉãñºÅz Exer3.c
//
//Åy  äT  óv  Åz To Count the number of characters and number of lines in the 
//				 Text file and display it on standard output.
//
//Åy çXêVóöó Åz 2010/10/07	Jatin Mistry
//
////////////////////////////////////////////////////////////////////////////////
//Header file
#include "Exer3.h"

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz main
//
//Åyì‡  óeÅz For Counting the number of characters and number of lines 
//			 in the Text file and display on standard output.
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
	FILE* fpFile = NULL;				//File pointer
	BOOL bReturn = FALSE;				//Boolean return from GetFileName
	char cCh = '0';						//Gets the actual character
	int nLines = 0;						//Counter for calculating lines 
	int nChars = 0;						//Counter for calculating characters
	char szFileName[MAX_FILENAME_LEN] = {0};//Store file name with ext
	char szPrgName[MAX_FILENAME_LEN] = {0};	//Store program name

	//Argument check for no. arguments specified
	if(nArgc != MAX_ARG)
	{
		//Splitpath to get program name
		bReturn = GetFileName(pszArgv[ARG_PRGPATH], szPrgName, sizeof(szPrgName));
		if(bReturn)
		{
			//Show usage
			printf(START_WITHOUT_ARG, szPrgName);
			printf(USAGE, szPrgName);
			return FALSE;
		}
		printf(REQUEST_ARG);
		return FALSE;
	}

	//Opening File
	fpFile = fopen(pszArgv[ARG_FILEPATH], READ_MODE);
	
	//If the file does not exist
	if (fpFile == NULL) 
	{
		//Splitpath
		bReturn = GetFileName(pszArgv[ARG_FILEPATH], szFileName, sizeof(szFileName));
		
		//Print error message
		bReturn ? printf (FILE_OPEN_ERR, szFileName) : printf (INTERNAL_ERR);
		return FALSE;
	}
	
	while((cCh = getc(fpFile)) != EOF)
	{
		//\n is found means we have a line
		if(cCh == NEW_LINE)  
		{
			++nLines;
		}
				
		//Character is found
		else
		{
			++nChars;	
		}
	}

	//Close File
	FileClose(fpFile);

	//Print output
	printf(PRG_OUTLINE);
	printf(DASHES);
	printf(PRG_OUTPUT, nLines, nChars);
	
	return TRUE;
}