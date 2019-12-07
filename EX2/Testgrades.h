
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

DWORD WINAPI PullGrade(LPVOID lpParam);
int find_minimum(int array[], int array_size);
float Average(int sum, int size);
float CalculateGrade(int grades_array[]);




#endif // 