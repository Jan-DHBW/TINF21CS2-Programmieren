#include <stdio.h>

int printStudent (){
    structStudent *currentStudent = *firstStudent;

    printf("Geben Sie eine Matrikelnummer ein:")
    scanf("%f",  &searchM);

    while(currentStudent != NULL) {


        if (searchM == currentStudent.martikelnummer){
            printf("Nachname: %c \n", currentStudent.nachname);
            printf("Matrikelnummer: %f \n", currentStudent.matrikelnummer);
            printf("Eintrittsdatum: %d,%d,%d \n",  currentStudent.start_dat.day, currentStudent.start_dat.month, currentStudent.start_dat.year);
            printf("Austrittsdatum: %d,%d,%d \n", currentStudent.end_dat.day, currentStudent.end_dat.month, currentStudent.end_dat.year);
            printf("Geburtsdatum: %c \n", currentStudent.geb_dat.day, currentStudent.geb_dat.month, currentStudent.geb_dat.year);
            return 0;
    }
    structStudent currentStudent = currentStudent.next;
}
    printf("Matrikelnummer nicht gefunden! \n");
    return 1;
