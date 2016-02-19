//
//ÅyÉtÉ@ÉCÉãñºÅz Exer2.h
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

//Start without argument
#define START_WITHOUT_ARG	"\n Character String Search Program===%s=== by Jatin. \n"
//Usage
#define USAGE				"\n Usage:%s search_string fileName \n"
//Request correct arguments
#define REQUEST_ARG			"\n Please pass correct Arguments\n"
//Read mode of file
#define READ_MODE			"r"
//File Open Error
#define FILE_OPEN_ERR		"\n Cannot open file [%s]\n"
//Internal Error
#define INTERNAL_ERR		"\n Internal error is occured\n"

#define MAX_FILENAME_LEN	512		//Max file length with extention
#define MAX_ARG				3		//Max number of arguments reqd
#define MAX_STR_LEN			1024	//Max string length
#define	ARG_PRGPATH			0		//Argument for program path
#define	ARG_SRCHSTR			1		//Argument for search string
#define	ARG_FILEPATH		2		//Argument for file path
