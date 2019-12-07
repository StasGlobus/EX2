// Communication_Thread.h

#ifndef __COMMUNICATION_THREAD_H__
#define __COMMUNICATION_THREAD_H__

// Includes --------------------------------------------------------------------

#include <windows.h>

// Function Declarations -------------------------------------------------------

/*
* Communication thread. This thread simulates a time consuming task.
* Notes:
*   This thread calls SendDiagnosticsToMicrosoft in a loop forever.
*   Not all threads are an eternal loop. This is just for
*   for the sake of this example.
*/
DWORD WINAPI CommunicationThread(LPVOID lpParam);

#endif // __COMMUNICATION_THREAD_H__