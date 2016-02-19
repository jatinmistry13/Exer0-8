//
//ÅyÉtÉ@ÉCÉãñºÅz Exer5.c
//
//Åy  äT  óv  Åz Read the text file and display the line matching with 
//				 character string specified in command line in the 
//				 standard output
//
//Åy çXêVóöó Åz 2010/10/07	Jatin Mistry
//
///////////////////////////////////////////////////////////////////////////////
//Header file
#include "Exer5.h"

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz StringSearch
//
//Åyì‡  óeÅz For locating the location of match when the two strings are
//			 provided.
//
//Åyà¯  êîÅz [i] pszBase : pointer to the base string
//			 [i] pszSrch : pointer to the search string	
//
//ÅyñﬂÇËílÅz returns a pointer to the first occurrence of pszSrch in pszBase, 
//			 or NULL if pszSrch does not appear in string. If pszSrch 
//			 points to a string of zero length, the function returns pszBase.
//
//Åyóö  óÅz 2010/10/07	Jatin Mistry
//-----------------------------------------------------------------------------
char* StringSearch(char* pszBase, char* pszSrch)
{
	int nLengthBase = 0;	//Length of base string.
	int nLengthSrch = 0;	//Length of search string.
	int nMaxLength = 0;		//Maximum length to search
	int nI = 0;				//Loop variable to locate the match
	int nChar = 0;			//Loop variable.
	BOOL bFound = 0;		//To note if match is found.

	//Check inputs
	if(pszBase == NULL || pszSrch == NULL)
	{
		return NULL;
	}

	//Get the lengths of each string.
	nLengthBase	=	strlen(pszBase);
	nLengthSrch	=	strlen(pszSrch);

	//If length of search string is zero.
	if(nLengthSrch == 0)	
	{
		return pszBase;
	}

	//Find the max array index where search string could possibly be found.
	nMaxLength = nLengthBase - nLengthSrch;

	//Loop through upto max array index.
	for(nI=0; nI <= nMaxLength; nI++)
	{
		//If the first character is matched
		if(pszBase[nI] == pszSrch[0])	
		{	
			//Then a possible starting point found.
			bFound = 1;
			
			//Now checking the rest of the string.
			for(nChar = (nI + 1); nChar < (nI + (nLengthSrch - 1)); nChar++)
			{
				//Check each charater. Stop when match not found.
				if(pszBase[nChar] != pszSrch[nChar - nI])
				{
					bFound=0;
					break;
				}
			}

			//If substring is found then bFound will be 1 else 0.
			if(bFound)
			{
				//Match found at this position
				return (pszBase + nI);						
			}	
		}
	}
	//No match found then return failure.
	return NULL;  
}

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz main
//
//Åyì‡  óeÅz For reading and displaying the line matching with character
//			 string specified in the Command line in standard output.
//			  	
//Åyà¯  êîÅz [i] nArgc			: gives the number of arguments passed. 
//			 [i] pszArgv[]		: store the arguments passed.
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success, otherwise FALSE(0)
//
//Åyóö  óÅz 2010/10/07	Jatin Mistry
//-----------------------------------------------------------------------------
int main(int nArgc, char* pszArgv[])
{
	BOOL bReturn = FALSE;					//Boolean return from GetFileName
	char szMystring[MAX_STR_LEN] = {0};		//Stores matched line
	char szSrchSt[MAX_STR_LEN] = {0};		//Search String.
	char szFileName[MAX_FILENAME_LEN] = {0};//Store file name with ext.
	char szPrgName[MAX_FILENAME_LEN] = {0};	//Store program name.
	FILE* fpFile = NULL;					//File pointer
	char* pszLoc = NULL	;					//Gives location of match.

	//Argument check for no arguments specified.
	if(nArgc != MAX_ARG)
	{
		//Splitpath to get program name
		bReturn = GetFileName(pszArgv[ARG_PRGPATH], szPrgName, sizeof(szPrgName));
		if(bReturn)
		{
			printf(START_WITHOUT_ARG, szPrgName);
			printf(USAGE, szPrgName);
			return FALSE;
		}
		printf(REQUEST_ARG);
		return FALSE;
	}

	//Copy the search string from command line to szSrchSt
	strncpy(szSrchSt, pszArgv[ARG_SRCHSTR], sizeof(pszArgv[ARG_SRCHSTR]));

	//Opening file.
	fpFile = fopen(pszArgv[ARG_FILEPATH], READ_MODE);
	
	//If the file does not exist
	if (fpFile == NULL) 
	{
		//Splitpath
		bReturn = GetFileName(pszArgv[ARG_FILEPATH], szFileName, sizeof(szFileName));
		
		//Print error message
		bReturn ? printf(FILE_OPEN_ERR, szFileName) : printf(INTERNAL_ERR);
		return FALSE;
	}

	//Read the characters and move the file pointer ahead.
	while(fgets(szMystring, sizeof(szMystring), fpFile) != NULL)		
	{	
		//Gives the position of first occurrence of szSrchSt.
		pszLoc = StringSearch(szMystring, szSrchSt);		 
				
		//A value other than FAILURE is returned then display the string.
		if(pszLoc != NULL)						
		{
			puts(szMystring);
		}
	}

	//Close file.
	FileClose(fpFile);
	return TRUE;
}	




