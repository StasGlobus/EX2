//#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
// Includes --------------------------------------------------------------------
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "thread_functions.h"


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
int find_minimum(int array[], int array_size) {
	int c, index = 0, min=101;

	for (c = 0; c < array_size; c++)
		if (array[c] < min && array[c] != -1) {
			index = c;
			min = array[c];
		}

	return index;
}
float Average(int sum, int size) {
	return (sum / (float)size);
}


float CalculateGrade(int grades_array[])
{

	int local_grade_array[FILE_TYPES] = { 0 }, ex_arr[EXERESICES]={0},
		min_grade_index, sum = 0, 
		counter = 0, exam_grade, midterm;
	float final_avg = 0, ex_avg = 0;
	// copy the data to local array for calculations
	for (int i = 0; i < FILE_TYPES; i++) {
		local_grade_array[i]= grades_array[i];
		if (i < EXERESICES)
			ex_arr[i] = grades_array[i];
	}
	//delete two lowers exersice scores
	for (int i = 0; i < LOW_SCORES; i++) {
		min_grade_index = find_minimum(ex_arr, EXERESICES);
		ex_arr[min_grade_index] = -1;
	}
	// zero scores that are lower then PASS Grade
	for (int i = 0; i < FILE_TYPES; i++) {
		if (local_grade_array[i] != -1 && local_grade_array[i] < LOWEST_GRADE) {
			local_grade_array[i] = 0;
		}
	}
	//make an average of exersices grades
	for (int i = 0; i < EXERESICES; i++) {
		if (ex_arr[i] != -1) {
			sum = sum + ex_arr[i];
			counter++;
		}
	}
	if (VALID_EX == counter) { // check we have 8 valid exersice grades
		ex_avg = Average(sum, counter);
	}
	
	//take the midterm even if it's 0
	midterm = local_grade_array[MIDTERM];
	// check if student went to moed B
	if (0 == local_grade_array[MOEDB])
		exam_grade = local_grade_array[MOEDA];
	else
		exam_grade = local_grade_array[MOEDB];

	// final calculation
	final_avg = 0.2*exam_grade + 0.2*midterm + 0.6*exam_grade;
	return final_avg;
}
DWORD WINAPI GetGradesThread(LPVOID lpParam)//, char *dir)
{
	Sleep(10);
	FILE *fp;
	HANDLE p_thread_handles[FILE_TYPES];
	DWORD p_thread_ids[FILE_TYPES];
	DWORD exit_code;
	Grades *grades = (Grades *)lpParam;
	int local_grades[13] = { 0 };
	int ret_val, grades_array[FILE_TYPES] = { 0 };
	float final_grade;
	char file_names[FILE_TYPES][MAX_STRING] = { "ex01.txt","ex02.txt","ex03.txt","ex04.txt","ex05.txt",
					"ex06.txt","ex07.txt","ex08.txt","ex09.txt","ex10.txt",
					"midterm.txt","moedA.txt","moedB.txt" };
	char temp_dir[FILE_TYPES][MAX_STRING] = { '\0' };
	char slashes[2] = "\\";
	char output[MAX_STRING] = { '\0' };

	//open each thread to look for specific file
	for (int i = 0; i < FILE_TYPES; i++) {

		
		strcpy(temp_dir[i], grades->dir);
		strcat(temp_dir[i], grades->id);
		strcat(temp_dir[i], slashes);
		strcat(temp_dir[i], file_names[i]);
		p_thread_handles[i] = CreateThreadSimple(PullGrade, temp_dir[i], &p_thread_ids[i]);
		
		
	}
	DWORD dwRet = WaitForMultipleObjects(FILE_TYPES, p_thread_handles, TRUE, INFINITE);
	for (int i = 0; i < FILE_TYPES; i++) {
		ret_val = GetExitCodeThread(p_thread_handles[i], &exit_code);
		local_grades[i] = exit_code;
		printf("file %d exit code is %d\n", i, exit_code);
	}


	grades->grade_value = local_grades;
	final_grade = CalculateGrade(local_grades);
	printf("the final grade is%.2f", final_grade);
	strcpy(output, grades->dir);
	strcat(output, grades->id);
	strcat(output, slashes);
	strcat(output, "final_");
	strcat(output, grades->id);
	strcat(output, ".txt");
	fp = fopen(output, "w");
	if (NULL != fp) {
		fprintf(fp, "%0.2f\n", final_grade);
	}
	fclose(fp);
	return 0;
}


DWORD WINAPI PullGrade(LPVOID lpParam)
{
	Sleep(10);
	char *file_dir = (char*)lpParam;
	
	int grade = 0;
	grade = file(file_dir);
	//printf("%d\n", grade);

	
	return grade;

}
