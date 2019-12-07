
// IO_Thread.h

#ifndef __TESTGRADES_H__
#define __TESTGRADES_H__
#include "main.h"
#define MAX_STRING 50
//#define FILE_TYPES 13
#define FILENAME 20


// Includes --------------------------------------------------------------------

//#include "main.c"


// Function Declarations -------------------------------------------------------

/*
* IO thread. This thread is in charge of the user interface.
* Notes:
*   The thread calls the Echo function in a loop.
*   If the user enters "exit", the thread exits.
*   Not all threads are an eternal loop. This is just for
*   for the sake of this example.
*/
//DWORD WINAPI GetGradesThread(LPVOID lpParam);
DWORD WINAPI PullGrade(LPVOID lpParam);




#endif // 