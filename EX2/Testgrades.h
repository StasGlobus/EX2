
// IO_Thread.h

#ifndef __TESTGRADES_H__
#define __TESTGRADES_H__
#include "main.h"
#define MAX_STRING 50
//#define FILE_TYPES 13
#define FILENAME 20
#define LOW_SCORES 2
#define LOWEST_GRADE 2// chenge it to 60 later
#define EXERESICES 10
#define MIDTERM 10
#define MOEDA 11
#define MOEDB 12
#define FINAL_GRADE 13
#define VALID_EX 8



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