#ifndef _LAB_4_H
#define _LAB_4_H
// General Prototypes for 2D Jagged Arrays
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void ** allocateJagged2DArray(int elementSize, int rows, int lengths[]);
void freeJagged2DArray(void ** arrayJagged);
int getRowCount(void ** arrayJagged);
int getColCount(void ** arrayJagged, int row);
// Specific ADT (Course) to test with Jagged Arrays
struct _Course
{
// The first 3 fields form the course "info"
int number;
char department[64];
char name[64];
};
typedef struct _Course Course;
// Specific functions for the Course ADT
// construcor - return null on a fail
Course * createCourse(int number, char * department, char * name);
// destructor
void freeCourse(Course * pCourse);
// getters - return 1 for success or 0 for failure
int getCourseInfo(Course * pCourse, char * outputString);
// setters - return 1 for success or 0 for failure
int setCourseNumber(Course * pCourse, int number);
int setCourseDepartment(Course * pCourse, char * department);
int setCourseName(Course * pCourse, char * name);
//for testing
int return_rand_index(int min, int max);
#endif
