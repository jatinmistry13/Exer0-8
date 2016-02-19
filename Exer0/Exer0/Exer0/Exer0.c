//
//�y�t�@�C�����z Exer0.c
//
//�y  �T  �v  �z Display the Command line arguments specified at the 
//				 time of start-up,in a sequence in standard output.	
//
//�y �X�V���� �z 2010/10/07	Jatin Mistry
//
///////////////////////////////////////////////////////////////////////////////
//Header file
#include "Exer0.h"

//-----------------------------------------------------------------------------
//�y�֐����z main
//
//�y��  �e�z used for displaying the Command line arguments specified at 
//			 the time of start-up,in a sequence in standard output.	
//
//�y��  ���z [i] nArgc			: gives the no. of arguments passed. 
//			 [i] pszArgv[]		: stores the arguments passed.
//
//�y�߂�l�z returns TRUE(1) on success, otherwise FALSE(0)
//
//�y��  ���z 2010/10/07	Jatin Mistry
//-----------------------------------------------------------------------------
int main(int nArgc, char* pszArgv[])
{
	int nCount = 0;							//Keep a count.
	char szPrgName[MAX_FILENAME_LEN] = {0};	//Stores filename with extention.

	//Display the outline of the program.
	printf(PRG_OUT);

	//Split the executable path.
	if(!(GetFileName(pszArgv[ARG_PRGPATH], szPrgName, sizeof(szPrgName))))
	{
		printf(INTERNAL_ERR);
		return FALSE;
	}

	//Till count does not reach nArgc(Total arguments passed.)
	while(nCount != nArgc)	
	{
		if(nCount == 0)
		{
			printf(PRG_OP_LINE1, nCount);
			printf(STRING_FORM, szPrgName);
			printf(PRG_OP_LINE2);
			//Increment counter
			nCount++;
			continue;
		}
		
		printf(PRG_OP_LINE1, nCount);
		printf(STRING_FORM, pszArgv[nCount]);
		printf(PRG_OP_LINE2);
		//Increment counter
		nCount++;			
	}	
	return TRUE;
}