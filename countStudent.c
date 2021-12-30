#include <stdio.h>

int countStudent(){
    int counter = 0;

    struct student *currentStudent = firstStudent;
    while (currentStudent != NULL)
    {
        counter++;
    }
    printf("Anzahl der Studenten im Programm beträgt: %d \n", counter);

    return 0;
}