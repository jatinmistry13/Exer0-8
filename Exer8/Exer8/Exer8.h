//
//ÅyÉtÉ@ÉCÉãñºÅz Exer8.h
//
//Åy  äT  óv  Åz Contains the various header files and macros. 
//
//Åy çXêVóöó Åz 2010/10/19	Jatin Mistry
//
////////////////////////////////////////////////////////////////////////////////
//Header Files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include "Jatin_Utility.h"

//File open error
#define	FILE_OPEN_ERR		"\n Cannot open file.[%s] \n"
//Request correct arguments
#define REQUEST_ARG			"\n Please pass correct Arguments \n"
//Starting without arguments
#define	START_WITHOUT_ARG	"\n String Replace Program ===%s=== By Jatin \n"
//Correcy Usage
#define	USAGE				"\n Usage: %s [File Name] \n"
//Internal Error
#define INTERNAL_ERR		"\n Internal error is occured\n"
//String format
#define STRING_FORM			"%s"
//Read mode of file
#define READ_MODE			"r"
//Write mode of file
#define WRITE_MODE			"w"
//No matching string found
#define NO_MATCH			" No matching string found "
//String format
#define STRING_FORM			"%s"
//Error outline
#define ERROR_OUTLINE		"Error Code : {%d}\nMessage :{%s}\n"
//error codes
#define INVALID_MAIN_ARG			"INCORRECT ARGUMENTS IN MAIN"
#define INVALID_FILEREAD_ARG		"INCORRECT ARGUMENTS IN FILEREAD"
#define INVALID_FILEWRITE_ARG		"INCORRECT ARGUMENTS IN FILEWRITE"
#define INVALID_STRINGREPLACE_ARG	"INCORRECT ARGUMENTS IN STRINGREPLACE"
#define MALLOC_FAIL					"INSUFFICIENT MEMORY"
#define REALLOC_FILEREAD_FAIL		"REALLOC FAIL IN FILEREAD"
#define REALLOC_STRINGREPLACE_FAIL	"REALLOC FAIL IN STRINGREPLACE"

#define MAX_STR_LEN			1024	//Max string length
#define MAX_ARG				4		//Max number of arguments 
#define MAX_FILENAME_LEN	512		//Max length of file name
#define	CHAR_SET			0		//Character to be set
#define	ARG_PRGPATH			0		//Argument for program path
#define	ARG_FILEPATH		1		//Argument for file path
#define ARG_SRCH_STR		2		//Argument for search string
#define ARG_REP_STR			3		//Argument for replace string

//Enums for errors
typedef enum Error
{
	ERR_SUCCESS = 0,
	ERR_MAIN_ARGUMENT,
	ERR_FILEREAD_ARGUMENT,
	ERR_STRINGREPLACE_ARGUMENT,
	ERR_FILEWRITE_ARGUMENT,
	ERR_MAIN_MALLOC,
	ERR_FILEREAD_REALLOC,
	ERR_STRINGREPLACE_REALLOC,
	ERR_FILEREAD_FILE_OPEN,
	ERR_FILEWRITE_FILE_OPEN,
	ERR_STRINGREPLACE_NO_MATCH_FOUND
}ErrorCode;

//-----------------------------------------------------------------------------
//Åyä÷êîñºÅz DispErrMsg
//
//Åyì‡  óeÅz Display a Message when an error occurs.
//
//Åyà¯  êîÅz [i] enum ErrorCode error: Error code to display message
//
//ÅyñﬂÇËílÅz returns nothing.
//
//Åyóö  óÅz 2010/10/18 Jatin Mistry
//-----------------------------------------------------------------------------
void DispErrMsg(enum ErrorCode error)
{
	switch(error)
	{

	case ERR_MAIN_ARGUMENT:
		printf(ERROR_OUTLINE, error,INVALID_MAIN_ARG);
		break;

	case ERR_FILEREAD_ARGUMENT:
		printf(ERROR_OUTLINE, error,INVALID_FILEREAD_ARG);
		break;

	case ERR_STRINGREPLACE_ARGUMENT:
		printf(ERROR_OUTLINE, error, INVALID_STRINGREPLACE_ARG);
		break;

	case ERR_FILEWRITE_ARGUMENT:
		printf(ERROR_OUTLINE, error, INVALID_FILEWRITE_ARG);
		break;

	case ERR_MAIN_MALLOC:
		printf(ERROR_OUTLINE, error, MALLOC_FAIL);
		break;

	case ERR_FILEREAD_REALLOC:
		printf(ERROR_OUTLINE, error, REALLOC_FILEREAD_FAIL);
		break;

	case ERR_STRINGREPLACE_REALLOC:
		printf(ERROR_OUTLINE, error,REALLOC_STRINGREPLACE_FAIL);
		break;

	case ERR_FILEREAD_FILE_OPEN:
		break;

	case ERR_FILEWRITE_FILE_OPEN:
		break;

	case ERR_STRINGREPLACE_NO_MATCH_FOUND:
		printf(ERROR_OUTLINE, error,NO_MATCH);
		break;
	default:
		break;
	}
}