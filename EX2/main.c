
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include "Testgrades.h"
#include "main.h"




void* Grades_default(Grades *grades) {

	grades->dir = (char*)malloc(MAX_STRING * sizeof(char));
	grades->id = (char*)malloc(ID * sizeof(char));
	grades->grade_value = (int*)calloc(FILE_TYPES, sizeof(int));
	strcpy(grades->dir, DIR);
	
}

int main(int argc, char *argv[])
{
	HANDLE p_thread_handles[NUM_THREADS];
	DWORD p_thread_ids[NUM_THREADS];
	DWORD wait_code;
	BOOL ret_val;
	size_t i;
	Grades *grades;
	char id[ID] = { '\0' };
	if (argc > 2) {
		printf("Too many arguments supplied.\n");
	}
	else if (argc < 2) {
		printf("One argument expected.\n");
	}
	memcpy(&id, argv[1], ID);

	
	

	grades = (Grades *)malloc(sizeof(Grades));// multiply by the amount of ID's in the filr
	Grades_default(grades);
	strcpy(grades->id, id); //Integration  chage it to argv later.
	// Temp Setup, need to move it to function, maybe should allocate space first

	// a separate thread will be opend for each ID
	p_thread_handles[0] = CreateThreadSimple(GetGradesThread, grades, &p_thread_ids[0]);
	
	wait_code = WaitForSingleObject(p_thread_handles[0], INFINITE);
	if (WAIT_OBJECT_0 != wait_code)
	{
		printf("Error when waiting");
		return ERROR_CODE;
	}

	// Terminate the other thread
	// Normally, we would avoid terminating a thread so brutally,
	// because it might be in the middle of an operation that should not
	// be interrupted (like writing a file).
	// There are gentler ways of terminating a thread.
	//ret_val = TerminateThread(p_thread_handles[1], BRUTAL_TERMINATION_CODE);
	/*
	if (false == ret_val)
	{
		printf("Error when terminating\n");
		return ERROR_CODE;
	}
	*/

	// Close thread handles
	for (i = 0; i < 1; i++)
	{
		ret_val = CloseHandle(p_thread_handles[i]);
		if (false == ret_val)
		{
			printf("Error when closing\n");
			return ERROR_CODE;
		}
	}
	//getchar();
	return 0;
}
HANDLE CreateThreadSimple(LPTHREAD_START_ROUTINE p_start_routine,
	LPVOID p_thread_parameters,
	LPDWORD p_thread_id)
{
	HANDLE thread_handle;

	if (NULL == p_start_routine)
	{
		printf("Error when creating a thread");
		printf("Received null pointer");
		exit(ERROR_CODE);
	}

	if (NULL == p_thread_id)
	{
		printf("Error when creating a thread");
		printf("Received null pointer");
		exit(ERROR_CODE);
	}

	thread_handle = CreateThread(
		NULL,                /*  default security attributes */
		0,                   /*  use default stack size */
		p_start_routine,     /*  thread function */
		p_thread_parameters, /*  argument to thread function */
		0,                   /*  use default creation flags */
		p_thread_id);        /*  returns the thread identifier */

	return thread_handle;
}
