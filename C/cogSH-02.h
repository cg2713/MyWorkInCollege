/*
 * Name		: Mohan Shah
 * Class	: CS-221 CA
 * Semester	: Semester 2020
 * Homework	: HW-00
 * Question	: Q00
 * File		: cogSH-02.h
*/

#ifndef __cogSH02_H
#define __cogSH02_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LINE_SIZE				8192
#define EXIT_MIN					0		// (-128)?
#define EXIT_MAX					255		// (127)?

#define MAX_NUMBER_OF_ALIASES		100

/*
 * some global variables make things somewhat easier
*/
const char *DEFAULT_PS1 = "$> ";
char *ps1;									// prompt string one
int cargc;									// keeps track of the number of tokens in the input phrase
char **cargv;								// the actual tokens in the input phrase

char *aliasName[MAX_NUMBER_OF_ALIASES];
char *aliasValue[MAX_NUMBER_OF_ALIASES];




/*
 * classification (types) of commands and functions to execute those
*/
enum CommandType {UNKNOWN, ALIAS, FUNCTION, INTERNAL, EXTERNAL};
typedef enum CommandType command_t;
command_t getCmdType(const char *cmd);		// returns proper command type as in the enum

// note that exec<CmdType> functions have access to the global vars cargc and cargv
// cargv has already been pre-processed (tokenized and all that)
// So userInput is passed here only for reference to the original input as user entered it
int execAlias(const char* userInput);
int execFunction(const char* userInput);
int execInternal(const char* userInput);
int execExternal(const char* userInput);




/*
 * helper functions for running of cogSH and for internal commands
*/
int initShell();							// initialization routines
int getArgValues(const char *rawInput);		// and a function to manage cargc and cargv

void progExit(void);						// to handle different exit variations


#endif	/* __cogSH02_H */

