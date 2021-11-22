#include <stdio.h>

int menue(){
    int end = 0;
    while (end == 0) {
        printf("Willkommen im Menue!\n");
        printf("[1] um einen Student hinzuzufuegen\n");
        printf("[2] um einen Student zu loeschen\n");
        printf("[3] um einen Student anzusehen\n");
        printf("[4] um alle Student anzusehen\n");
        printf("[0] um das Programm zu beenden\n");
        char auswahl;
        scanf("%c", &auswahl);
        switch (auswahl)
            case 1:
                inputStudent();
            case 2:
                deleteStudent();
            case 3:
                printStudent();
            case 4:
                printAllStudents();
            case 0:
                printf("Moechten Sie das Programm wirklich beenden? (y/n)");
                char beenden;
                scanf("%c",&beenden);
                switch (beenden)
                    case "y":
                        printf("Programm beendet");
                        end = 1;
                    case "n":
                        printf("Zurück ins Menu\n")
                        menue();}
    return 0;}

