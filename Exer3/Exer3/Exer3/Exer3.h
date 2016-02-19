//
//ÅyÉtÉ@ÉCÉãñºÅz Exer3.h
//
//Åy  äT  óv  Åz Contains the various header files and macros. 
//
//Åy çXêVóöó Åz 2010/10/07	Jatin Mistry
//
////////////////////////////////////////////////////////////////////////////////
//Header files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "Jatin_Utility.h" 

//Start witout arguments
#define START_WITHOUT_ARG	"\n Program for Counting no. of lines and characters===%s=== by Jatin. \n"
//Usage
#define USAGE				"\n Usage:%s fileName \n"
//Read Mode
#define READ_MODE			"r"
//Internal Error
#define INTERNAL_ERR		"\n Internal error is occured\n"
//File Open error
#define FILE_OPEN_ERR		"\n Cannot open file [%s] \n"
//File empty
#define FILE_EMPTY			"\n file is empty! \n"
//Request correct arguments
#define REQUEST_ARG			"\n Please enter correct arguments"
//Program  outline
#define PRG_OUTLINE			"\n Number of Lines \t\t\t Number of Characters \n"
#define DASHES				"\n --------------- \t\t\t -------------------- \n"
//Program output
#define PRG_OUTPUT			"\n \t %d \t\t\t \t\t %d \n"
#define NEW_LINE			'\n'

#define MAX_ARG				2	//Max arguments allowed
#define MAX_FILENAME_LEN	512	//Max length of file name
#define	ARG_PRGPATH			0	//Argument for program path
#define	ARG_FILEPATH		1	//Argument for file path
