#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fileapi.h>
//#include "student.h"
//#include "datetime.h"
//#include "menue"

struct date
{
    int day;
    int month;
    int year;
    //der Tag des Jahres 325
} geb_dat, start_dat, end_dat; //direkte Initialisierung der drei notwenigen Struckts für Geburtstag, Startdatum, Enddatum

struct student
{
    char nachname[30];
    unsigned int matrikelnummer;
    struct date startDatum;
    struct date endDatum;
    struct date gebDatum;
    struct student *next;
};
struct student *firstStudent;
struct student *currentStudent;

int schaltjahr(int year)
{
    if (year % 4 == 0)
        return 1;
    else
        return 0;
}

int monthvalid(int month)
{
    if (month > 12)
    {
        printf("FEHLER, Monat muss zwischen 1 - 12 liegen!");
        return (0);
    }
    else
        return 1;
}

int datevalid(int day, int month, int year)
{
    if (year > 2100 || year < 1900)
    {
        printf("Ungültiges Datum\n");
        return 1;
    }
    if (month < 1 || month > 12)
    {
        printf("Ungültiges Datum\n");
        return 1;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 13)
    {
        if (day < 1 || day > 31)
        {
            printf("Ungültiges Datum\n");
            return 1;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day < 1 || day > 30)
        {
            printf("Ungültiges Datum\n");
            return 1;
        }
    }
    if (month == 2)
    {
        if (year % 4 == 0)
        {
            if (day < 1 || day > 28)
            {
                printf("Ungültiges Datum\n");
                return 1;
            }
        }
        else
        {
            if (day < 1 || day > 27)
            {
                printf("Ungültiges Datum\n");
                return 1;
            }
        }
    }
    return 0;
}

struct student *inputStudent()
{
    char nach[15];
    int m_nr = 0;

    int day_sm;
    int month_sm;
    int year_sm;
    //Kurzzeitige Variablen in denen die Eingaben gespeichert werden um sie später dann richtig abzuspeichern

    printf("Eingabe der Daten eines Studentens\n");

    printf("Nachname:");
    scanf("%s", nach);
    do
    {
        printf("Martrikelnummer:");
        scanf("%d", &m_nr);
        currentStudent = firstStudent;
        while (currentStudent != NULL)
        {
            if (m_nr == currentStudent->matrikelnummer)
            {
                printf("Diese Nummer ist bereits vergeben\n\n");
                m_nr = 0;
            }
            currentStudent = currentStudent->next;
        }
    } while (m_nr == 0);

    struct student *out = NULL;
    if ((out = malloc(sizeof(struct student))) == NULL)
    {
        printf("Kein Speicherplatz vorhanden fuer anfang\n");
        return NULL;
    };
    strcpy(out->nachname, nach);
    out->matrikelnummer = m_nr;

    day_sm = 0;
    month_sm = 0;
    year_sm = 0;
    int check = 0;
    do
    {
        printf("Startdatum: (Day/Month/Year) - Eingabe mit Leerzeichen\n");
        scanf("%d %d %d", &day_sm, &month_sm, &year_sm);
        check = datevalid(day_sm, month_sm, year_sm);
    } while (check != 0);

    out->startDatum.day = day_sm;
    out->startDatum.month = month_sm;
    out->startDatum.year = year_sm;

    day_sm = 0;
    month_sm = 0;
    year_sm = 0;
    check = 0;
    do
    {
        printf("Enddatum: (Day/Month/Year) - Eingabe mit Leerzeichen\n");
        scanf("%d %d %d", &day_sm, &month_sm, &year_sm);
        check = datevalid(day_sm, month_sm, year_sm);
    } while (check != 0);

    out->endDatum.day = day_sm;
    out->endDatum.month = month_sm;
    out->endDatum.year = year_sm;

    day_sm = 0;
    month_sm = 0;
    year_sm = 0;
    check = 0;
    do
    {
        printf("Geburtsdatum: (Day/Month/Year) - Eingabe mit Leerzeichen\n");
        scanf("%d %d %d", &day_sm, &month_sm, &year_sm);
        check = datevalid(day_sm, month_sm, year_sm);
    } while (check != 0);

    out->gebDatum.day = day_sm;
    out->gebDatum.month = month_sm;
    out->gebDatum.year = year_sm;

    return out;
}

void addStudent(struct student *in)
{
    in->next = NULL;

    if (firstStudent == NULL)
    {
        firstStudent = in;
        firstStudent->next = NULL;
        return;
    }

    currentStudent = firstStudent;

    if (strcmp(in->nachname, firstStudent->nachname) <= 0)
    {

        in->next = firstStudent;
        firstStudent = in;
        return;
    }

    while (currentStudent->next != NULL)
    {
        if (strcmp(in->nachname, currentStudent->next->nachname) <= 0)
        {
            in->next = currentStudent->next;
            currentStudent->next = in;
            return;
        }
        currentStudent = currentStudent->next;
    }
    currentStudent->next = in;
    in->next = NULL;
    return;
}

void printAllStudents()
{
    currentStudent = firstStudent;
    while (currentStudent != NULL)
    {
        printf("Nachname: %s \n", currentStudent->nachname);
        printf("Matrikelnummer: %u \n", (*currentStudent).matrikelnummer);
        printf("Eintrittsdatum: %d,%d,%d \n", (*currentStudent).startDatum.day, (*currentStudent).startDatum.month, (*currentStudent).startDatum.year);
        printf("Austrittsdatum: %d,%d,%d \n", (*currentStudent).endDatum.day, (*currentStudent).endDatum.month, (*currentStudent).endDatum.year);
        printf("Geburtsdatum: %d,%d,%d \n", (*currentStudent).gebDatum.day, (*currentStudent).gebDatum.month, (*currentStudent).gebDatum.year);
        printf("_____________________________________________________________________________\n");
        currentStudent = (*currentStudent).next;
    }
}

void printStudent(int m)
{
    currentStudent = firstStudent;
    while (currentStudent != NULL)
    {
        if (currentStudent->matrikelnummer == m)
        {
            printf("Nachname: %s \n", &currentStudent->nachname);
            printf("Matrikelnummer: %u \n", (*currentStudent).matrikelnummer);
            printf("Eintrittsdatum: %d,%d,%d \n", (*currentStudent).startDatum.day, (*currentStudent).startDatum.month, (*currentStudent).startDatum.year);
            printf("Austrittsdatum: %d,%d,%d \n", (*currentStudent).endDatum.day, (*currentStudent).endDatum.month, (*currentStudent).endDatum.year);
            printf("Geburtsdatum: %d,%d,%d \n", (*currentStudent).gebDatum.day, (*currentStudent).gebDatum.month, (*currentStudent).gebDatum.year);
            printf("_____________________________________________________________________________\n\n");
            return;
        }
        currentStudent = currentStudent->next;
    }
    printf("Der Student konnte nicht gefunden werden\n\n");
}

void deleteStudent(int m_nr)
{
    if (firstStudent->matrikelnummer == m_nr)
    {
        struct student *tmp;
        tmp = firstStudent;
        firstStudent = firstStudent->next;
        free(tmp);
        printf("Eintrg wurde gelöscht \n\n");
        return;
    }
    currentStudent = firstStudent;
    while (currentStudent != NULL)
    {
        if (currentStudent->next->matrikelnummer == m_nr)
        {
            struct student *tmp;
            tmp = currentStudent->next;
            currentStudent->next = currentStudent->next->next;
            free(tmp);
            printf("Eintrg wurde gelöscht \n\n");
            return;
        }
        currentStudent = currentStudent->next;
    }
    printf("Der Student wurde nicht gefunden\n\n");
    return;
}

void menue()
{
    int end = 0;
    int m;
    char beenden;
    while (end == 0)
    {
        printf("Willkommen im Menue!\n");
        printf("[1] um einen Student hinzuzufuegen\n");
        printf("[2] um einen Student zu loeschen\n");
        printf("[3] um einen Student anzusehen\n");
        printf("[4] um alle Student anzusehen\n");
        printf("[0] um das Programm zu beenden\n");
        int auswahl;
        scanf("%d", &auswahl);
        switch (auswahl)
        {
        case 1:

            addStudent(inputStudent());
            break;
        case 2:
            printf("Bitte geben sie die Matrikelnummer an:\n");
            scanf("%d", &m);
            deleteStudent(m);
            break;
        case 3:

            printf("Bitte geben sie die Matrikelnummer an:\n");
            scanf("%d", &m);
            printStudent(m);
            break;
        case 4:
            printAllStudents();
            break;
        case 0:
            printf("Moechten Sie das Programm wirklich beenden? (y/n)\n");

            scanf(" %c", &beenden);
            switch (beenden)
            {
            case 'y':
                printf("Programm beendet\n");
                end = 1;
                break;
            case 'n':
                printf("Zurück ins Menu\n");
                break;
            }
            break;
        }
    }
}

int getCount(struct student *in)
{
    int count = 0;
    currentStudent = in;
    while (currentStudent != NULL)
    {
        count++;
        currentStudent = currentStudent->next;
    }
    return count;
}
int getFileSize()
{
    FILE *fp = fopen("sav.bin", "rb");
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fclose(fp);
    return size;
}

void save()
{
    if (firstStudent != NULL)
    {
        FILE *countfp;
        FILE *fp;
        if ((fp = fopen("sav.bin", "wb")) == NULL)
        {
            printf("Fehler beim öffnen der Datei\n");
            return;
        }
        int count = getCount(firstStudent);
        currentStudent = firstStudent;
        for (int n = 1; n <= count; n++)
        {
            fwrite(currentStudent, sizeof(struct student), 1, fp);
            currentStudent = currentStudent->next;
        }
        fclose(fp);
        if ((countfp = fopen("count.bin", "wb")) == NULL)
        {
            printf("Fehler beim öffnen der Datei\n");
        }
        fwrite(&count, sizeof(int), 1, countfp);
        fclose(countfp);
    }
}
void open()
{
    // FILE *countfp;
    // FILE *fp;
    // if((fp = fopen("sav.bin","rb")) == NULL){
    //     printf("Fehler beim öffnen der Datei\n");
    //     return;
    // }
    // int count = sizeof(*fp)/sizeof(struct student);
    // struct student *tmp;
    // if((countfp = fopen("count.bin","rb")) == NULL){
    //     printf("Fehler beim öffnen der Datei\n");
    //     return;
    // }
    // fread(&count, sizeof(int), 1,countfp);
    // fclose(countfp);

    // fread(tmp, sizeof(struct student), 1, fp);
    // addStudent(tmp);
    FILE *fp;
    int size = getFileSize();

    int count = (size / sizeof(struct student));

    fp = fopen("sav.bin", "rb");
    for (int i = 0; i < count; i++)
    {
        struct student *in = malloc(sizeof(struct student));
        if (fp == NULL)
        {
            printf("Error beim lesen");
        }
        fread(in, sizeof(struct student), 1, fp);
        addStudent(in);
    }
}

int main()
{
    firstStudent = NULL;
    currentStudent = NULL;
    open();
    menue();
    save();

    return 0;
}