#include "TestManager.h"

BOOL CreateProcessSimple(LPTSTR CommandLine, PROCESS_INFORMATION *ProcessInfoPtr)// This part is copied from Recitation Code
{
	STARTUPINFO	startinfo = { sizeof(STARTUPINFO), NULL, 0 }; /* <ISP> here we */
															  /* initialize a "Neutral" STARTUPINFO variable. Supplying this to */
															  /* CreateProcess() means we have no special interest in this parameter. */
															  /* This is equivalent to what we are doing by supplying NULL to most other */
															  /* parameters of CreateProcess(). */

	return CreateProcess(NULL, /*  No module name (use command line). */
		CommandLine,			/*  Command line. */
		NULL,					/*  Process handle not inheritable. */
		NULL,					/*  Thread handle not inheritable. */
		FALSE,					/*  Set handle inheritance to FALSE. */
		NORMAL_PRIORITY_CLASS,	/*  creation/priority flags. */
		NULL,					/*  Use parent's environment block. */
		NULL,					/*  Use parent's starting directory. */
		&startinfo,				/*  Pointer to STARTUPINFO structure. */
		ProcessInfoPtr			/*  Pointer to PROCESS_INFORMATION structure. */
	);
}
int SendToTestGrade(char *id) {

	int temp_result = 0;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));


	char TestGrade[LONG] = { "TestGrade.exe 123456789" };
	//strcat(TestGrade, id);
	int result;
	PROCESS_INFORMATION procinfo;
	DWORD				waitcode;
	DWORD				exitcode;
	BOOL				retVal;
	CHAR				command[LONG];
	memcpy(&command, &TestGrade, sizeof(TestGrade));
	retVal = CreateProcessSimple(command, &procinfo);

	if (retVal == 0)
	{
		printf("Process Creation Failed!\n");
		return -1;
	}


	waitcode = WaitForSingleObject(
		procinfo.hProcess,
		TIMEOUT_IN_MILLISECONDS); // Waiting 5 secs for the process to end 

	GetExitCodeProcess(procinfo.hProcess, &exitcode);// this returns the result from the son project




	CloseHandle(procinfo.hProcess); // Closing the handle to the process 
	CloseHandle(procinfo.hThread); // Closing the handle to the main thread of the process 
	return exitcode;
}

int main() {

	char Statement[LONG] = { '\0' }, output[LONG] = { '\0' };
	char *needle = NULL;
	int result;
	result = SendToTestGrade("123456789");
	/*
	// Input Check
	if (argc > 2) {
		printf("Too many arguments supplied.\n");
	}
	else if (argc < 2) {
		printf("One argument expected.\n");
	}
	*/


}