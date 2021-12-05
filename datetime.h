struct date {
   int day;
   int month;
   int year;
   //der Tag des Jahres 325
} geb_dat, start_dat, end_dat; //direkte Initialisierung der drei notwenigen Struckts für Geburtstag, Startdatum, Enddatum




int schaltjahr(int year) {
    if (year % 4 == 0)
        return 1;
    else
        return 0;
}

int monthvalid ( int month){
    if ( month > 12){
        printf ("FEHLER, Monat muss zwischen 1 - 12 liegen!");
        return (0);}
    else
        return 1;
}

int datevalid (int day, int month ,int year) {
    if (monthvalid(month) == 1) {
        switch (month) {
            case 1:
                if (day <= 31)
                    return 1;
                else {
                    printf("FEHLER, Datum ungültig");
                    return 0;
                }

            case 2:
                if (day <= 27)
                    return 1;
                else if (day == 28) {
                    if (schaltjahr(year) == 1)
                        return 1;
                    else {
                        printf("FEHLER, Datum ungültig");
                        return 0;
                    }
                } else {
                    printf("FEHLER, Datum ungültig");
                    return 0;
                }

            case 3:
                if (day <= 31)
                    return 1;
                else {
                    printf("FEHLER, Datum ungültig");
                    return 0;
                }

            case 4:
                if (day <= 30)
                    return 1;
                else {
                    printf("FEHLER, Datum ungültig");
                    return 0;
                }

            case 5:
                if (day <= 31)
                    return 1;
                else {
                    printf("FEHLER, Datum ungültig");
                    return 0;
                }

            case 6:
                if (day <= 30)
                    return 1;
                else {
                    printf("FEHLER, Datum ungültig");
                    return 0;
                }

            case 7:
                if (day <= 31)
                    return 1;
                else {
                    printf("FEHLER, Datum ungültig");
                    return 0;
                }

            case 8:
                if (day <= 31)
                    return 1;
                else {
                    printf("FEHLER, Datum ungültig");
                    return 0;
                }

            case 9:
                if (day <= 30)
                    return 1;
                else {
                    printf("FEHLER, Datum ungültig");
                    return 0;
                }

            case 10:
                if (day <= 31) { return 1; }
                else {
                    printf("FEHLER, Datum ungültig");
                    return 0;
                }

            case 11:
                if (day <= 30)
                    return 1;
                else {
                    printf("FEHLER, Datum ungültig");
                    return 0;
                }

            case 12:
                if (day <= 31)
                    return 1;
                else {
                    printf("FEHLER, Datum ungültig");
                    return 0;
                }

            default:
                printf("FEHLER, Datum ungültig");
                return 0;

        }
    } else {
        printf("FEHLER, Datum ungueltig\n");
        return 0;
    }
}