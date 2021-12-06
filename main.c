#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "datetime.h"
//#include "menue"


inputStudent(){

    char nach[10];
    int m_nr;
    int day_sm;
    int month_sm;
    int year_sm;
    //Kurzzeitige Variablen in denen die Eingaben gespeichert werden um sie später dann richtig abzuspeichern

    printf("Eingabe der Daten eines Studentens\n");

    printf("Nachname:");
    scanf("%s", &nach);

    printf("Martrikelnummer:");
    scanf("%s", &m_nr);

    printf("Startdatum: (Day/Month/Year - Eingabe mit Leerzeichen");
    scanf("%s %s %s", &day_sm, &month_sm, &year_sm);
    start_dat.day = day_sm; //muss sehr wahrscheinlich nochmal überarbeitet werden. Speichert die eingegebenen Daten gerade einfach in das Struckt ab. Gild für alle drei Zeilen
    start_dat.month = month_sm;
    start_dat.year = year_sm;

    printf("Enddatum: (Day/Month/Year - Eingabe mit Leerzeichen");
    scanf("%s %s %s", &day_sm, &month_sm, &year_sm);
    end_dat.day = day_sm;
    end_dat.month = month_sm;
    end_dat.year = year_sm;

    printf("Geburtsdatum: (Day/Month/Year - Eingabe mit Leerzeichen");
    scanf("%s %s %s", &day_sm, &month_sm, &year_sm);
    geb_dat.day = day_sm;
    geb_dat.month = month_sm;
    geb_dat.year = year_sm;}

int main(){

    inputStudent();

    printf("Startdatum: %s", &start_dat);

    return 0;
}