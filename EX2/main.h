
// Communication_Thread.h

#ifndef __MAIN_H__
#define __MAIN_H__


// Includes --------------------------------------------------------------------

#include <windows.h>
//#include "Testgrades.h"

#define MAX_STRING 50
#define FILE_TYPES 13
#define FILENAME 20
static const char P_EXIT_CMD[] = "exit";
#define DIR "grades_"//123456789\\"//ex01.txt"
#define DIR_SIZE 18
#define NUM_THREADS 2
#define BRUTAL_TERMINATION_CODE 0x55
#define ERROR_CODE ((int)(-1))
#define ID 10
#define DEFAULT_ID "123456789"
typedef struct {

	char  *dir;
	//int grade_type;
	int *grade_value;
	char  *id;


}Grades; //contains all the grades of a student

typedef struct {

	char  *dir;
	//int grade_type;
	int grade;
	

}One_grade;// holds one grade at a time
// Function Declarations -------------------------------------------------------

/*
* Communication thread. This thread simulates a time consuming task.
* Notes:
*   This thread calls SendDiagnosticsToMicrosoft in a loop forever.
*   Not all threads are an eternal loop. This is just for
*   for the sake of this example.
*/
//DWORD WINAPI CommunicationThread(LPVOID lpParam);

//HANDLE CreateThreadSimple(LPTHREAD_START_ROUTINE p_start_routine,
	//LPDWORD p_thread_id, Grades *grades);
HANDLE CreateThreadSimple(LPTHREAD_START_ROUTINE p_start_routine,
	LPVOID p_thread_parameters,
	LPDWORD p_thread_id);
DWORD WINAPI GetGradesThread(LPVOID lpParam);


#endif // __COMMUNICATION_THREAD_H__