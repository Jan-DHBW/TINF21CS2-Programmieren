#include <stdio.h>

int printAllStudents(){

    structStudent *currentStudent = *firstStudent;

    while(currentStudent != NULL){
        printf("Nachname: %c \n", currentStudent.nachname);
        printf("Matrikelnummer: %f \n", currentStudent.matrikelnummer);
        printf("Eintrittsdatum: %d,%d,%d \n",  currentStudent.start_dat.day, currentStudent.start_dat.month, currentStudent.start_dat.year);
        printf("Austrittsdatum: %d,%d,%d \n", currentStudent.end_dat.day, currentStudent.end_dat.month, currentStudent.end_dat.year);
        printf("Geburtsdatum: %d,%d,%d \n", currentStudent.geb_dat.day, currentStudent.geb_dat.month, currentStudent.geb_dat.year);
        printf("_____________________________________________________________________________")}

    return 0;
}