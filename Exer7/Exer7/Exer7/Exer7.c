//
//ÅyÉtÉ@ÉCÉãñºÅz Exer7.c
//
//Åy  äT  óv  Åz Calculate the time required for transmission of data.	
//
//Åy çXêVóöó Åz 2010/10/12	Jatin Mistry
//
////////////////////////////////////////////////////////////////////////////////
//Header file
#include "Exer7.h"

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz ParseInt
//
//Åyì‡  óeÅz Converts input string to integer.
//
//Åyà¯  êîÅz [i] pszInputString : Input String.
//			 [o] pNInteger : Integer
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success, otherwise FALSE(0).
//
//Åyóö  óÅz 2010/10/12	Jatin Mistry
//-----------------------------------------------------------------------------
BOOL ParseInt(char* pszInputString, int* pNInteger)
{
	int nLength = MAX_DIGITS;	//Max digits for integers
	int i = 0;					//Loop variable
	int j = 0;					//Loop variable
	double dblSize = 0;			//To store value from atof()
	BOOL bFinish = FALSE;		//Boolean to indicate finish of string
	char szNumSize[MAX_DIGITS] = {0};	//To store the numbers from string

	//Check input parameters
	if(pszInputString == NULL || pNInteger == NULL)
	{
		return FALSE;
	}

	szNumSize[j] = PLUS_SIGN;
	j++;

	//Till End of String not reached...
	while(pszInputString[i] != END_OF_STRING && (j < nLength ))
	{
		//Till we have leading spaces...
		while(pszInputString[i] == SPACES || pszInputString[i] == TAB)
		{
			i++;
		}

		//If '+/-' sign is present
		if(pszInputString[i] == PLUS_SIGN ||
			(pszInputString[i] == MINUS_SIGN))
		{
			j = 0;
			szNumSize[j] = pszInputString[i];
			i++;
			j++;
		}

		//spaces or tab after sign
		while(pszInputString[i] == SPACES || pszInputString[i] == TAB)
		{
			i++;
		}

		//If we have leading zeroes
		while(pszInputString[i] == ZERO)
		{
			i++;
		}

		//If a End of string is found
		if(pszInputString[i] == END_OF_STRING)
		{
			szNumSize[j] = END_OF_STRING;
			bFinish = TRUE;
		}

		//If a Number is not found..
		if(bFinish == FALSE &&
		   (pszInputString[i] > NINE || pszInputString[i] < ONE))
		{
			printf(INVALID_INTEGER);
			return FALSE;
		}

		//If a Number is found and is in the range...
		while((pszInputString[i] <= NINE && pszInputString[i] >= ZERO) &&
			  (j < nLength ))
		
		{
			//Read the number in szNumSize
			szNumSize[j] = pszInputString[i];
			j++;
			i++;

			//If next character is '\0'
			if(pszInputString[i] == END_OF_STRING)
			{
				szNumSize[j] = END_OF_STRING;
				break;
			}

			//If next Charcter is "spaces"
			while(pszInputString[i] == SPACES)
			{
				i++;
				
				//If next characyter is '\0'
				if(pszInputString[i] == END_OF_STRING)
				{
					szNumSize[j] = END_OF_STRING;
					break;
				}

				//Check if next character is also a "space"
				if(pszInputString[i] != SPACES)
				{
					printf(INVALID_INTEGER);
					return FALSE;
				}
			}
		}
	}

	//Convert string to integer
	dblSize = atof(szNumSize);

	if(dblSize > INTEGER_RANGE)
	{
		printf(BIG_NUMBER);
		return FALSE;
	}

	*pNInteger = (int)dblSize;
	return TRUE;
}

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz CalculateTime
//
//Åyì‡  óeÅz Calculates Time for transmission.
//
//Åyà¯  êîÅz [i] nBytes	: Total bytes to transfer.
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success, otherwise FALSE(0).
//
//Åyóö  óÅz 2010/10/13	Jatin Mistry
//-----------------------------------------------------------------------------
BOOL CalculateTime(int nBytes)
{
	int nDays = 0;		//For days
	int nHours = 0;		//For Hours
	int nMinutes = 0;	//For Minutes
	int nSeconds = 0;	//For Seconds

	//Check input 
	if(nBytes < 0)
	{
		return FALSE;
	}
	//Calculate total time in seconds  
	nSeconds = nBytes / 960;

	//Calculate Days
	nDays = (int) (nSeconds / (60 * 60 * 24));
	nSeconds -= nDays * (60 * 60 * 24);

	//Claculate Hours
	nHours = (int)(nSeconds / (60 * 60));
	nSeconds -= nHours * (60 * 60);

	//Calculate Minutes
	nMinutes = (int)(nSeconds / 60);
	nSeconds -= nMinutes * 60;

	//If nBytes lies between 0 and 960
	if(nBytes<960 && nBytes>0)
	{
		nSeconds = 1;
	}

	printf(PRG_OUT);
	printf(OUTPUT, nDays, nHours, nMinutes, nSeconds);
	
	return TRUE;
}

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz main
//
//Åyì‡  óeÅz Calculate the time required for transmission of data.
//			 	
//Åyà¯  êîÅz [i] nothing. 	
//
//ÅyñﬂÇËílÅz returns TRUE(1) on success,otherwise FALSE(0).
//
//Åyóö  óÅz 2010/10/13	Jatin Mistry
//-----------------------------------------------------------------------------
int main()
{
	int nBytes = 0;						//Total btes top transfer
	int nSize = 0;						//Size of file to transfer
	int nChoice = 0;					//Users choice
	BOOL bChoice = FALSE;				//Boolean for proper choice
	char szChoice[STR_LEN] = {0};		//To store input for choice
	
	do
	{
		//Outlines from which user will choose
		printf(OUTLINE);
		printf(OPTION1);	 
		printf(OPTION2);
		printf(OPTION3);
		printf(OPTION4);
		printf(OPTION5);
		printf(GIVE_CHOICE);
		//Read the users choice
		gets(szChoice);

		bChoice = ParseInt(szChoice, &nChoice);
		
		if(bChoice == FALSE)
		{ 
			return FALSE;
		}

		//check the range of input
		if(nChoice < 0 || nChoice > 5)
		{
			printf(INVALID_CHOICE);
			return FALSE;
		}

		switch(nChoice)
		{
			//To calculate for Bytes 
			case 1:
				nSize = ReadInput();

				//If nSize not in byte range
				if(nSize > BYTE_RANGE)
				{
					printf(INVALID_INPUT);
					return FALSE;
				}

				if(nSize == FAILURE)
				{ 
					return FALSE;
				}

				nBytes = nSize;

				CalculateTime(nBytes);

				break;

			
			//To calculate for kilobytes
			case 2:
				nSize = ReadInput();

				//If nSize not in kilobyte range
				if(nSize > KB_RANGE)
				{
					printf(INVALID_INPUT);
					return FALSE;
				}

				if(nSize == FAILURE)
				{ 
					return FALSE;
				}

				//Convert KB to byte
				nBytes = nSize * KB_TO_BYTE;

				CalculateTime(nBytes);

				break;
			

			//To calculate for megabytes
			case 3:
				nSize = ReadInput();

				//If nSize not in megabyte range
				if(nSize > MB_RANGE)
				{
					printf(INVALID_INPUT);
					return FALSE;
				}

				if(nSize == FAILURE)
				{ 
					return FALSE;
				}

				//Convert MB to byte
				nBytes = nSize * MB_TO_BYTE;

				CalculateTime(nBytes);

				break;
			

			//To calculate for gigabytes
			case 4:
				nSize = ReadInput();

				//If nSize not in gigabyte range
				if(nSize > GB_RANGE)
				{
					printf(INVALID_INPUT);
					return FALSE;
				}

				if(nSize == FAILURE)
				{ 
					return FALSE;
				}

				//Convert GB to byte
				nBytes = nSize * GB_TO_BYTE;

				CalculateTime(nBytes);

				break;
			

			default:
				return FALSE;
		}
	}
	while(nChoice != 5);
	return TRUE;
}

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz ReadInput
//
//Åyì‡  óeÅz Reads the input from the user.
//			 	
//Åyà¯  êîÅz [i] nothing. 
//
//ÅyñﬂÇËílÅz returns nSize : User Input.
//
//Åyóö  óÅz 2010/10/13	Jatin Mistry
//-----------------------------------------------------------------------------
//Repetitive function
int ReadInput()
{	
	int nSize = 0;						//parsed user input
	BOOL bReturn = FALSE;				//Boolean return from ParseInt
	char szSizeBytes[STR_LEN] = {0};	//size in string

	printf(FILE_SIZE);
	fflush( stdin );
	//Read the data
	gets( szSizeBytes );
	//Perform parsing
	bReturn = ParseInt(szSizeBytes, &nSize);
	
	if(bReturn == FALSE)
	{ 
		return -1;
	}

	//Negative Number
	if(nSize < 0)
	{
		printf(NEGATIVE_VALUE);
		return -1;
	}
	return nSize;
}