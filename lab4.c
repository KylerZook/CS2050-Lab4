#include "lab4.h"


void ** allocateJagged2DArray(int elementSize, int rows, int lengths[]){
    void** array = malloc(sizeof(int) + rows * sizeof(void*));  
    if(!array) return NULL;  // Early exit if allocation fails.

    *((int*)array) = rows;  // Store number of rows.
    void** base = (void**)((int*)array + 1);  // Move base pointer to avoid overwriting row count.

    for(int i = 0; i < rows; i++){
        base[i] = malloc(sizeof(int) + lengths[i] * elementSize);
        *(int*)base[i] = lengths[i];  // Store column count at beginning
        base[i] = (void*)((int*)base[i] + 1);  // Move pointer forward so users only see data.
    }

    return base; 
}


void freeJagged2DArray(void ** arrayJagged){
    if(!arrayJagged) return;
    
    int rows = *((int*)arrayJagged - 1);
    for(int i = 0; i < rows; i++){
        void * original_columns = (void*)((int*)arrayJagged[i] - 1);
        free(original_columns);
    }
    void** original_row = (void**)((int*)arrayJagged - 1);
    free(original_row);
}

int getRowCount(void ** arrayJagged){
    if(!arrayJagged){ return 0; }
    return *((int*)arrayJagged - 1);
}
int getColCount(void ** arrayJagged, int row){
    if(!arrayJagged || row < 0){ return 0; }
    
    return *(((int*)arrayJagged[row]) - 1);
}


Course * createCourse(int number, char * department, char * name){
    if(number < 0 || !department || !name){ return NULL; }

    Course * new_course = malloc(sizeof(Course));
    if(!new_course){ return NULL; }

    new_course->number = number;
    strcpy(new_course->name, name);
    strcpy(new_course->department, department);
    return new_course;
}

// destructor
void freeCourse(Course * pCourse){
    if(!pCourse){ return; }
    free(pCourse);
}

// getters - return 1 for success or 0 for failure
int getCourseInfo(Course * pCourse, char * outputString){
    if(!pCourse || !outputString){ return 0;}
    size_t size = 50;
    snprintf(outputString, size,"%s (%s) - %d", pCourse->name, pCourse->department, pCourse->number);
    return 1;
}

// setters - return 1 for success or 0 for failure
int setCourseNumber(Course * pCourse, int number){
    if(!pCourse || number < 0){ return 0; }

    pCourse->number = number;
    return 1;
}
int setCourseDepartment(Course * pCourse, char * department){
    if(!pCourse || !department){ return 0; }

    strcpy(pCourse->department, department);
    return 1;
}
int setCourseName(Course * pCourse, char * name){
    if(!pCourse || !name){ return 0; }

    strcpy(pCourse->name, name);
    return 1;
}

int return_rand_index(int min, int max){
    return(rand()% (max - min + 1) + min);
}


