//
//ÅyÉtÉ@ÉCÉãñºÅz Exer1.h
//
//Åy  äT  óv  Åz Contains the various header files and macros. 
//
//Åy çXêVóöó Åz 2010/10/07	Jatin Mistry
//
////////////////////////////////////////////////////////////////////////////////
//Header Files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "Jatin_Utility.h"

//File Open Error
#define	FILE_OPEN_ERR		"\n Cannot open file.[%s] \n"
//Request correct arguments
#define REQUEST_ARG			"\n Please pass correct Arguments \n"
//Start without argument
#define	START_WITHOUT_ARG	"\n File Display Program ===%s=== By Jatin \n"
//Usage
#define	USAGE				"\n Usage: %s [File Name] \n"
//Internal Error
#define INTERNAL_ERR		"\n Internal error is occured\n"
//Read mode of file
#define	READ_MODE			"r"
//String format
#define	STRING_FORM			"%s"

#define	MAX_FILENAME_LEN	512	//Max lenth of filename
#define MAX_STR_LEN			1024//Max length of sting
#define MAX_ARG				2	//Max number of arguments
#define	ARG_PRGPATH			0	//Argument for program path
#define	ARG_FILEPATH		1	//Argument for file path
