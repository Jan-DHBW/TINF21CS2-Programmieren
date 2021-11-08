#include "datetime.h"

struct student {
    char nachname[30];
    unsigned int matrikelnummer;
    struct date startDatum;
    struct date endDatum;
    struct date gebDatum;
    struct student *next;
};