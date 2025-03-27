#include "../headers/menu.h"

char *start_menu(char* language){
    
    curs_set(0);
    clear();
    noecho();

    if (language == "en"){
        printw("|--------------------------------|\n");
        printw("|                                |\n");
        printw("|      Welcome to Wordle         |\n");
        printw("|                                |\n");
        printw("|                                |\n");
        printw("|      Play                      |\n");
        printw("|      Difficulty                |\n");
        printw("|      Language                  |\n");
        printw("|                                |\n");
        printw("|                                |\n"); 
        printw("|                                |\n"); 
        printw("|                                |\n");
        printw("|                    Asderton :3 |\n");
        printw("|--------------------------------|\n");
    }
    else {
        printw("|--------------------------------|\n");
        printw("|                                |\n");
        printw("|      Bienvenido a Wordle       |\n");
        printw("|                                |\n");
        printw("|                                |\n");
        printw("|      Jugar                     |\n");
        printw("|      Dificultad                |\n");
        printw("|      Idioma                    |\n");
        printw("|                                |\n");
        printw("|                                |\n"); 
        printw("|                                |\n"); 
        printw("|                                |\n");
        printw("|                    Asderton :3 |\n");
        printw("|--------------------------------|\n");
    }
 

    const int play = 5;
    const int difficulty = 6;
    const int lan = 7;
    Position_t cursor = {4,5};
    move CURRENT_POSITION;
    addch('>');
    refresh();

    char menu_order = getch();
    while (menu_order!= '\n'){
        if ((menu_order == 'w' || menu_order == 'W') && cursor.y > play){
            move CURRENT_POSITION;
            addch(' ');
            cursor.y--;
            move CURRENT_POSITION;
            addch('>');
            refresh();
        }
        else if ((menu_order == 's' || menu_order == 'S') && cursor.y < lan){
            move CURRENT_POSITION;
            addch(' ');
            cursor.y++;
            move CURRENT_POSITION;
            addch('>');
            refresh();
        }
        menu_order = getch();
    }

    switch(cursor.y){
        case 5:
            return language;
        case 6:
            return language;
        case 7:
            language = language_menu(language);
            start_menu(language);

    }
    refresh();
    return language;
    
}

char *language_menu(char *language){

    curs_set(0);
    clear();
    noecho();

    if (language == "en"){
        printw("|--------------------------------|\n");
        printw("|                                |\n");
        printw("|    Choose your language        |\n");
        printw("|                                |\n");
        printw("|                                |\n");
        printw("|      English                   |\n");
        printw("|                                |\n");
        printw("|      Spanish                   |\n");
        printw("|                                |\n");
        printw("|                                |\n"); 
        printw("|                                |\n"); 
        printw("|                                |\n");
        printw("|                    Asderton :3 |\n");
        printw("|--------------------------------|\n");
    }
    else{
        printw("|--------------------------------|\n");
        printw("|                                |\n");
        printw("|    Escoge tu idioma            |\n");
        printw("|                                |\n");
        printw("|                                |\n");
        printw("|      Ingles                    |\n");
        printw("|                                |\n");
        printw("|      Español                  |\n");
        printw("|                                |\n");
        printw("|                                |\n"); 
        printw("|                                |\n"); 
        printw("|                                |\n");
        printw("|                    Asderton :3 |\n");
        printw("|--------------------------------|\n");
    }

    const int english = 5;
    const int spanish = 7;
    Position_t cursor = {5,5};
    move CURRENT_POSITION;
    addch('>');
    refresh();

    
    char menu_order = getch();
    while (menu_order!= '\n'){
        if ((menu_order == 'w' || menu_order == 'W') && cursor.y > english){
            move CURRENT_POSITION;
            addch(' ');
            cursor.y -= 2;
            move CURRENT_POSITION;
            addch('>');
            refresh();
        }
        else if ((menu_order == 's' || menu_order == 'S') && cursor.y < spanish){
            move CURRENT_POSITION;
            addch(' ');
            cursor.y += 2;
            move CURRENT_POSITION;
            addch('>');
            refresh();
        }
        menu_order = getch();
    }

    if (cursor.y == english){
        return "en";
    }
    else {
        return "es";
    }
    getch();
}



