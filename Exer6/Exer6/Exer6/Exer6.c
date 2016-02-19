//
//yƒtƒ@ƒCƒ‹–¼z Exer6.c
//
//y  ŠT  —v  z Reversing the assigned character string.
//				 	
//y XV—š—ğ z 2010/10/7 Jatin Mistry
//
///////////////////////////////////////////////////////////////////////////////
//Header file
#include "Exer6.h"

//-----------------------------------------------------------------------------
//yŠÖ”–¼z StringReverse
//
//y“à  —ez For reversing the string.
//
//yˆø  ”z [io] pszStr	: the string to be reversed.
//
//y–ß‚è’lz returns a pointer to the altered string.
//
//y—š  —ğz 2010/10/26 Jatin Mistry
//-----------------------------------------------------------------------------
char* StringReverse(char* pszStr)
{
	int nI=0;		//Loop variable.
	int nTemp=0;	//Temporary variable.
	int nLength=0;	//Length of the string.
	
	//Check input parameter.
	if(pszStr == NULL)
	{
		return NULL;
	}

	//Calculating the length of the string.
	nLength = strlen(pszStr);

	//Run upto middle of the string to reverse.
	for(nI=0; nI < nLength/2; nI++) 
	{
		nTemp = pszStr[nI];
		pszStr[nI] = pszStr[nLength - (nI+1)];
		pszStr[nLength - (nI+1)] = nTemp;
	}
	return pszStr;
}

//-----------------------------------------------------------------------------
//yŠÖ”–¼z main
//
//y“à  —ez Used for reversing the assigned character string. 	
//			 	
//yˆø  ”z [i] nothing.
//
//y–ß‚è’lz returns TRUE(1) on success, otherwise FALSE(0)
//
//y—š  —ğz 2010/10/7 Jatin Mistry
//-----------------------------------------------------------------------------
int main()
{
	char szStr[MAX_STR_LEN] = {0};	//String to be reversed.
	char* pszRev = NULL;			//Pointer to reversed string 

	//Request input
	printf(STRING_REQ);
	gets(szStr);

	//Reverse the string.
	pszRev = StringReverse(szStr);

	//Check return value.
	if(pszRev != NULL)
	{
		printf(PRG_OUTLINE);
		puts(szStr);
		printf(LINE_FEED);
		return TRUE;
	}

	return FALSE;
}