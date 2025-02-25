#include "lab4.h"
int main(void) {
    //given values for testing
    srand(time(NULL));
    int rows = 3;
    int lengths[3] = {4, 5, 6};
    int course_numbers[] = {1050, 2050, 3050};
    char *names[] = {"Kyler", "John", "Zook", "Job", "Daniel", "Wargo"};
    char *department[] = {"CS", "Math", "English", "Engineering", "Chemistry"};
    char info[50]; //empty string to print course info
    
    
    void **mem_block = allocateJagged2DArray((int)sizeof(Course), rows, lengths); //init memory block
    Course **courses = (Course **)mem_block; //changes to course ** type

    for (int i = 0; i < getRowCount((void **)courses); i++) {
        for (int j = 0; j < getColCount((void **)courses, i); j++) { //for each element of array
            
            //creates course pointer in new
            Course * new =  createCourse(course_numbers[return_rand_index(0, 2)],department[return_rand_index(0, 4)], names[return_rand_index(0, 5)]);
            
            //sets current address in array to new courses values
            setCourseDepartment(&courses[i][j], new->department); 
            setCourseName(&courses[i][j], new->name);
            setCourseNumber(&courses[i][j], new->number);
            
            if (getCourseInfo(&courses[i][j], info) == 1) { //if getcourse info was successful
                printf("%s\n", info); //prints each course
            } else {
                continue;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        printf("column count for row %d: %d\n", i, getColCount((void **)courses, i)); //getcolumn check for no reason ig
    }
    printf("rows: %d\n", getRowCount((void **)courses)); //getrow check for no reason

    // Free the entire jagged array
    freeJagged2DArray((void **)courses);

    return 0;
}