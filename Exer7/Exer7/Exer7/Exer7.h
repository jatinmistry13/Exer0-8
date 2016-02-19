//
//ÅyÉtÉ@ÉCÉãñºÅz Exer7.h
//
//Åy  äT  óv  Åz Contains the various headers and macros. 
//
//Åy çXêVóöó Åz 2010/10/07	Jatin Mistry
//
////////////////////////////////////////////////////////////////////////////////
//Header files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "Jatin_Utility.h"

//Outline for user to choose
#define	OUTLINE		"\n Enter the choice of size format \n"
#define	OPTION1		"\n 1	In Bytes only upto 2147483647 \n"
#define OPTION2		"\n 2	In Kilobytes(KB) only upto 2097151 \n"
#define OPTION3		"\n 3	In Megabytes(MB) only upto 2047 \n"
#define OPTION4		"\n 4	In Gigabytes(GB) only upto 1 \n"
#define OPTION5		"\n 5	To quit \n"
#define GIVE_CHOICE	"\n Enter your choice :\t"
#define INVALID_CHOICE "\n Invalid choice \n"

//Integer format
#define INT_FORM		"%d"	
//Size to be transfered
#define FILE_SIZE		"\nEnter the size of the file: "		
//Program outline
#define PRG_OUT			"\nThe time taken for transmission is:"	
//Program output
#define	OUTPUT			"%d days %d hours %d minutes %d seconds\n"
//Invalid integer
#define INVALID_INTEGER	"\nInvalid Integer : Not a Valid Number\n"
//Big value
#define BIG_NUMBER		"\nInvalid Integer : Too big Number for Integer\n"
//negative value entered
#define NEGATIVE_VALUE	"\nCannot calculate for negative values\n"
//Invalid input
#define INVALID_INPUT	"\n Invalid Input \n"



#define	PLUS_SIGN		'+'	//Plus sign
#define MINUS_SIGN		'-'	//Minus sign
#define SPACES			' '	//Blank space
#define END_OF_STRING	'\0'//End of string character
#define ZERO			'0'	//zero
#define ONE				'1'	//One
#define	NINE			'9'	//Nine
#define TAB				'\t'//Tab

#define INTEGER_RANGE	+2147483647		//Max value for positive integer
#define MAX_DIGITS		13				//Max length of digits in Integer
#define STR_LEN			256				//Length of the string to read
#define	KB_TO_BYTE		1024			//KB to byte conversion factor
#define MB_TO_BYTE		1024*1024		//MB to byte conversion factor
#define	GB_TO_BYTE		1024*1024*1024	//GB to byte conversion factor
#define BYTE_RANGE		2147483647		//Max possible value for Byte value
#define KB_RANGE		2097151			//Max possible value for KB value
#define MB_RANGE		2047			//Max possible value for MB value
#define GB_RANGE		1				//Max possible value for GB value
#define FAILURE			-1
