#include "lab4.h"


void ** allocateJagged2DArray(int elementSize, int rows, int lengths[]){
    void** array = malloc(sizeof(int) + rows * sizeof(void*));  
    if(!array) return NULL;  //early exit if allocation fails.

    *((int*)array) = rows;  //store number of rows.
    void** base = (void**)((int*)array + 1);  //move base pointer to avoid overwriting row count.

    for(int i = 0; i < rows; i++){
        base[i] = malloc(sizeof(int) + lengths[i] * elementSize); //allocates room for lengths[i] many elements plus an int
        *(int*)base[i] = lengths[i];  //store column count at beginning
        base[i] = (void*)((int*)base[i] + 1);  //move pointer forward so users only see data
    }

    return base; //returns array
}


void freeJagged2DArray(void ** arrayJagged){
    if(!arrayJagged) return; //checks if valid array
    
    int rows = *((int*)arrayJagged - 1); //gets rows
    for(int i = 0; i < rows; i++){
        void * original_columns = (void*)((int*)arrayJagged[i] - 1); //moves back pointer in columns
        free(original_columns); //frees columns
    }
    void** original_row = (void**)((int*)arrayJagged - 1); //moves back pointer in row
    free(original_row);//frees row
}

int getRowCount(void ** arrayJagged){
    if(!arrayJagged){ return 0; } //checks if valid array
    return *((int*)arrayJagged - 1); //returns real first element
}
int getColCount(void ** arrayJagged, int row){
    if(!arrayJagged || row < 0){ return 0; } //checks if valid array and if row count is more than 0
    
    return *(((int*)arrayJagged[row]) - 1); //returns first element of said row
}


Course * createCourse(int number, char * department, char * name){
    if(number < 0 || !department || !name){ return NULL; } //if all valid paremeters

    Course * new_course = malloc(sizeof(Course)); //allocates space for new course
    if(!new_course){ return NULL; } //checks if allocated
    //sets values to given in parameters
    new_course->number = number;
    strcpy(new_course->name, name);
    strcpy(new_course->department, department);
    return new_course; //returns course pointer
}


void freeCourse(Course * pCourse){
    if(!pCourse){ return; } //parameter check
    free(pCourse); //frees course pointer
}

// getters - return 1 for success or 0 for failure
int getCourseInfo(Course * pCourse, char * outputString){
    if(!pCourse || !outputString){ return 0;} //checks if valid parameters
    size_t size = 50; //max string size because i got a warning or sum

    //takes department, name, and number from course pointer and combines into string of size 50
    snprintf(outputString, size,"%s (%s) - %d", pCourse->name, pCourse->department, pCourse->number);
    return 1;
}

// setters - return 1 for success or 0 for failure
int setCourseNumber(Course * pCourse, int number){
    if(!pCourse || number < 0){ return 0; } //parameter check

    pCourse->number = number; //sets course number to given
    return 1;
}
int setCourseDepartment(Course * pCourse, char * department){
    if(!pCourse || !department){ return 0; }//parameter check

    strcpy(pCourse->department, department);//copys given to course department
    return 1;
}
int setCourseName(Course * pCourse, char * name){
    if(!pCourse || !name){ return 0; }//parameter check

    strcpy(pCourse->name, name);//copys given to course name
    return 1;
}

int return_rand_index(int min, int max){ 
    return(rand()% (max - min + 1) + min);//returns random number between min and max index inclusive
}


