//#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
// Includes --------------------------------------------------------------------
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "Testgrades.h"


// Constants -------------------------------------------------------------------



// Function Declarations -------------------------------------------------------





// This function goes to the specified file, reads ot, and return it's name
static int file(char *dir)
{	
	FILE *fp;
	char buff[5] = { '\0' };
	int grade = 0;
	//char *ptr;

	fp = fopen(dir, "r");
	fscanf(fp, "%d", &grade);
	
	fclose(fp);
	

	return grade;
}

DWORD WINAPI GetGradesThread(LPVOID lpParam)//, char *dir)
{
	Sleep(10);
	HANDLE p_thread_handles[FILE_TYPES];
	DWORD p_thread_ids[FILE_TYPES];
	Grades *grades = (Grades *)lpParam;
	char file_names[FILE_TYPES][FILENAME] = { "ex01.txt","ex02.txt","ex03.txt","ex04.txt","ex05.txt",
					"ex06.txt","ex07.txt","ex08.txt","ex09.txt","ex10.txt",
					"midterm.txt","moedA.txt","moedB.txt" };
	char temp_dir[FILE_TYPES][MAX_STRING] = { '\0' };
	/*
	* Convert (void *) to parameters type.
	* In this example, MATH_THREAD_params_t is a simple struct.
	* In general, it could be any type:
	* integer, array, array of struct, string etc.
	*/
	//grades = (Grades *)lpParam;

	//p_params->res = p_params->num1 + p_params->num2;

	//getchar();
	//Grades *grades = lpParam;
	
	//DWORD wait_code;
	//BOOL ret_val;
	//size_t i;

	
	//open each thread to look for specific file
	for (int i = 0; i < FILE_TYPES; i++) {

		//p_thread_handles[i] = CreateThreadSimple(PullGrade, &p_thread_ids[i], grade->dir);
		strcpy(temp_dir[i], grades->dir);
		strcat(temp_dir[i], file_names[i]);
		p_thread_handles[i] = CreateThreadSimple(PullGrade, temp_dir[i], &p_thread_ids[i]);
		Sleep(1);//Integration
		//memset(temp_dir[i], '\0', MAX_STRING);
	}
	DWORD dwRet = WaitForMultipleObjects(FILE_TYPES, p_thread_handles, FALSE, INFINITE);
	
	return 0;
}


DWORD WINAPI PullGrade(LPVOID lpParam)
{
	//Sleep(10);
	char *file_dir = (char*)lpParam;
	
	int grade = 0;
	
	//memcpy(file_dir, ptr, DIR_SIZE); //copy the part before the left bracket
	//strcat(file_dir, file_names[0]); // add the result to the new string
	grade = file(file_dir);
	printf("%d\n", grade);
	//getchar();
	
	return 0;

}
