#include <stdio.h>

int printStudent (){
    int searchM;
    int counter = 0;

    printf("Geben Sie eine Matrikelnummer ein:")
    scanf("%f",  &searchM);

    while(searchM != matrikelnummer[count]) {
        counter++;
    // IfStatement einfügen,
    // if (counter > höchster Arrayeintrag)
    // {printf("Martikelnummer nicht gefunden!\n");
    // return 0;}
    }

    if (searchM == martikelnummer[counter]){
        printf("Nachname: %c \n", nachname[counter]);
        printf("Matrikelnummer: %f \n", matrikelnummer[counter]);
        printf("Eintrittsdatum: %c \n", startDatum[counter]);
        printf("Austrittsdatum: %c \n", endDatum[counter]);
        printf("Geburtsdatum: %c \n", gebDatum[counter]);
    }

    return 0;
}