// IO_Thread.c

// Includes --------------------------------------------------------------------

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "IO_Thread.h"

// Constants -------------------------------------------------------------------

#define MAX_STRING 50
static const char P_EXIT_CMD[] = "exit";

// Function Declarations -------------------------------------------------------

/*
* Prints back the string that has been inputed on the command line.
* Returns:
*   BOOL: True if the user entered the string P_EXIT_CMD.
*/
static BOOL Echo(void);

// Function Definitions --------------------------------------------------------

DWORD WINAPI IOThread(LPVOID lpParam)
{
	BOOL continue_flag = true;

	while (continue_flag)
	{
		continue_flag = Echo();
	}

	return 0;
}

static BOOL Echo(void)
{
	char p_input_string[MAX_STRING];
	BOOL continue_flag = true;

	printf("Please enter a string.\n");
	scanf_s("%s", p_input_string, MAX_STRING);
	printf("%s\n", p_input_string);

	if (0 == strcmp(p_input_string, P_EXIT_CMD))
	{
		continue_flag = false;
	}

	return continue_flag;
}