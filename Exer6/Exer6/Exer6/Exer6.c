//
//�y�t�@�C�����z Exer6.c
//
//�y  �T  �v  �z Reversing the assigned character string.
//				 	
//�y �X�V���� �z 2010/10/7 Jatin Mistry
//
///////////////////////////////////////////////////////////////////////////////
//Header file
#include "Exer6.h"

//-----------------------------------------------------------------------------
//�y�֐����z StringReverse
//
//�y��  �e�z For reversing the string.
//
//�y��  ���z [io] pszStr	: the string to be reversed.
//
//�y�߂�l�z returns a pointer to the altered string.
//
//�y��  ���z 2010/10/26 Jatin Mistry
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
//�y�֐����z main
//
//�y��  �e�z Used for reversing the assigned character string. 	
//			 	
//�y��  ���z [i] nothing.
//
//�y�߂�l�z returns TRUE(1) on success, otherwise FALSE(0)
//
//�y��  ���z 2010/10/7 Jatin Mistry
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