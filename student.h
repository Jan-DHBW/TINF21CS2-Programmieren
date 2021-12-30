#include "datetime.h"

struct student {
    char nachname[30];
    unsigned int matrikelnummer;
    struct date startDatum;
    struct date endDatum;
    struct date gebDatum;
    struct student *next;
}*firstStudent;


struct student addStudent(char nach[],int m_nr,struct date geb_dat,struct date start_dat,struct date end_dat){
    struct student *tmp1 = NULL;
    if((tmp1 = malloc(sizeof(struct student))) == NULL) {
        printf(stderr, "Kein Speicherplatz vorhanden fuer anfang\n");
        return;
    };
    strcpy(tmp1->nachname, nach);
    tmp1->matrikelnummer = m_nr;

    

        
}

void deleteStudent(int matrikelnummer){
    struct student *aktuell = firstStudent;
    struct student *next = aktuell->next;
    while(aktuell != NULL){
        
    }
    

    



    return 1;
}

void printAllStudents(){

    struct Student *currentStudent = firstStudent;

    while(currentStudent != NULL){
        printf("Nachname: %c \n", currentStudent.nachname);
        printf("Matrikelnummer: %f \n", currentStudent.matrikelnummer);
        printf("Eintrittsdatum: %d,%d,%d \n",  currentStudent.start_dat.day, currentStudent.start_dat.month, currentStudent.start_dat.year);
        printf("Austrittsdatum: %d,%d,%d \n", currentStudent.end_dat.day, currentStudent.end_dat.month, currentStudent.end_dat.year);
        printf("Geburtsdatum: %d,%d,%d \n", currentStudent.geb_dat.day, currentStudent.geb_dat.month, currentStudent.geb_dat.year);
        printf("_____________________________________________________________________________")}

    return 0;
}

