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
    if (month > 0 && month < 13) {
        if(day >0 && day <31){
            if(year >1900 && year < 2010){
                return 0;
            }
        }     
    }
}    