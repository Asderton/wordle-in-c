#include "../headers/menu.h"

void start_menu(game_state *game){
    
    curs_set(0);
    clear();
    noecho();

    if (game -> language == EN){
        printw("|--------------------------------|\n");
        printw("|                                |\n");
        printw("|    Welcome to Wordle           |\n");
        printw("|                                |\n");
        printw("|                                |\n");
        printw("|      Play                      |\n");
        printw("|      Difficulty                |\n");
        printw("|      Language                  |\n");
        printw("|                                |\n");
        printw("|                                |\n"); 
        if (game -> chances == 8)
            printw("| Easy mode requires Fullscreen! |\n");
        else 
            printw("|                                |\n");
        printw("|                                |\n");
        printw("|                    Asderton :3 |\n");
        printw("|--------------------------------|\n");
    }
    else {
        printw("|--------------------------------|\n");
        printw("|                                |\n");
        printw("|    Bienvenido a Wordle         |\n");
        printw("|                                |\n");
        printw("|                                |\n");
        printw("|      Jugar                     |\n");
        printw("|      Dificultad                |\n");
        printw("|      Idioma                    |\n");
        printw("|                                |\n");
        printw("|                                |\n"); 
        if (game -> chances == 8)
            printw("| Modo facil requiere Fullscreen |\n"); 
        else
            printw("|                                |\n");   
        printw("|                                |\n");
        printw("|                    Asderton :3 |\n");
        printw("|--------------------------------|\n");
    }
 

    const int play = 5;
    const int difficulty = 6;
    const int language = 7;
    Position_t cursor = {5,play};
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
        else if ((menu_order == 's' || menu_order == 'S') && cursor.y < language){
            move CURRENT_POSITION;
            addch(' ');
            cursor.y++;
            move CURRENT_POSITION;
            addch('>');
            refresh();
        }
        menu_order = getch();
    }

    if (cursor.y == play){
        return;
    }
    else if (cursor.y == difficulty){
        difficulty_menu(game);
        start_menu(game);
        return;
    }
    else {
        language_menu(game);
        start_menu(game);
    }
    refresh();
    return;
    
}

void language_menu(game_state *game){

    curs_set(0);
    clear();
    noecho();

    if (game -> language == EN){
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
    Position_t cursor = {5,english};
    move CURRENT_POSITION;
    addch('>');
    refresh();

    
    char menu_order = getch();
    while (menu_order != '\n'){
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
        game -> language = EN;
        return;
    }
    else {
        game -> language = ES;
        return;
    }
    getch();
}

void difficulty_menu(game_state *game){

    curs_set(0);
    clear();
    noecho();

    const int easy = 5;
    const int normal = 6;
    const int hard = 7;

    if (game -> language == EN){
        printw("|--------------------------------|\n");
        printw("|                                |\n");
        printw("|    Pick your difficulty        |\n");
        printw("|                                |\n");
        printw("|                                |\n");
        printw("|      Easy                      |\n");
        printw("|      Normal                    |\n");
        printw("|      Hard                      |\n");
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
        printw("|    Escoge tu dificultad        |\n");
        printw("|                                |\n");
        printw("|                                |\n");
        printw("|      Facil                     |\n");
        printw("|      Normal                    |\n");
        printw("|      Dificil                   |\n");
        printw("|                                |\n");
        printw("|                                |\n"); 
        printw("|                                |\n"); 
        printw("|                                |\n");
        printw("|                    Asderton :3 |\n");
        printw("|--------------------------------|\n");

    }

    Position_t cursor = {5,normal};
    move CURRENT_POSITION;
    addch('>');
    refresh();

    char menu_order = getch();
    while (menu_order!= '\n'){
        if ((menu_order == 'w' || menu_order == 'W') && cursor.y > easy){
            move CURRENT_POSITION;
            addch(' ');
            cursor.y --;
            move CURRENT_POSITION;
            addch('>');
            refresh();
        }
        else if ((menu_order == 's' || menu_order == 'S') && cursor.y < hard){
            move CURRENT_POSITION;
            addch(' ');
            cursor.y ++;
            move CURRENT_POSITION;
            addch('>');
            refresh();
        }
        menu_order = getch();
    }

    if (cursor.y == easy){
        game -> chances = 8;
        return;
    }
    else if (cursor.y == normal){
        game -> chances = 6;
        return;
    }
    else {
        game -> chances = 5;
        return;
    }
}

