//
//ÅyÉtÉ@ÉCÉãñºÅz Exer4.h
//
//Åy  äT  óv  Åz Contains the various header files and macros. 
//
//Åy çXêVóöó Åz 2010/10/08	Jatin Mistry
//
////////////////////////////////////////////////////////////////////////////////
//Header files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include "Jatin_Utility.h"

//Start without argument
#define START_WITHOUT_ARG	"Program for copying a file===%s=== By Jatin \n"
//Usage
#define USAGE				"Usage: %s sourceFileName destFileName \n"
//File Open Error
#define FILE_OPEN_ERR		"Cannot open file.[%s] \n"
//Read mode of file
#define READ_MODE			"rb"
//Write mode of file
#define WRITE_MODE			"wb"
//Internal Error
#define INTERNAL_ERR		"\n Internal error is occured\n"
//Request correct arguments
#define REQUEST_ARG			"Internal Error:Please enter correct arguments.\n"
//warning 
#define MSG_EXIST			"File already exist. Do you want to replace it? \n"
//user option 1
#define MSG_MENU			"Select your option from following options.\n"
//user option 1
#define MSG_YES				"Enter 1 for Yes\n"
//user option 2
#define MSG_NO				"Enter 2 for No\n"
//user option 2
#define MSG_INVALID			"Invalid selection...\n"
//enter choice
#define MSG_CHOICE			"Enter your Choice and press ENTER: "
//Interger format
#define INT_FORM			"%d"

#define MAX_ARG				3	//Max number of arguments
#define MAX_FILENAME_LEN	512	//Max length of filename
#define FALSE				0	//On Fail
#define TRUE				1	//On Success
#define ARG_PRGPATH			0	//Argument for program path
#define ARG_SRCFILE			1	//Argument for source file
#define	ARG_DESTFILE		2	//Argument for destination file
#define MODE_ACCESS			00	//Existence only 
#define MAX_STR_LEN			1024//Max length of string














