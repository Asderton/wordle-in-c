#include "grid.h"
#include<ncurses.h>
#include<stdlib.h>


void make_grid(void);

int main(void){

    initscr();

    make_grid();
    refresh();

    char *guess = get_guess();
// Space for answer-validation and coloration

    
    refresh();
   


    move(10,10);
    getch();
    

    endwin();

}


void make_grid(void){
    for (int tiles_printed = 0; tiles_printed < LETTER_QUANTITY; tiles_printed++){
        print_bound();
        print_container();
        print_bound();
        printw("\n");
    }
}

//El nombre del parametro es el utilizado en los define, no cambiar, preguntar a sami si es mala idea xD
char *get_guess(void){
    
    Position_t _cursor = {START_POSITION};
    noecho();
    char *word_guessed = malloc(sizeof(char) * LETTER_QUANTITY);

    for (int letter_index = 0; letter_index < LETTER_QUANTITY; letter_index++){
        
        move _CURRENT_POSITION;
        char letter_guessed = getch();
        refresh();

        if (letter_guessed == 27 && _cursor.x > 2){
            _cursor.x LEFT;
            move _CURRENT_POSITION;
            addch(' ');
            refresh();

            word_guessed[letter_index] = ' ';
            letter_index --;
        }

        switch(letter_guessed){
            case 'A'...'Z':
            case 'a'...'z':
                if (letter_index != LETTER_QUANTITY - 1){
                addch(letter_guessed);
                _cursor.x += 6;
                word_guessed[letter_index] = letter_guessed;
                }
                else{
                addch(letter_guessed);
                refresh();
                word_guessed[letter_index] = letter_guessed;
                }
                break;

            default:
                letter_index--;
                break;
        }  
    }
    return word_guessed;
}


void print_bound(void){
    char buffer[LETTER_QUANTITY * CELL_SIZE];
    buffer[0] = '\0';
    char *buffer_p = buffer;

    for (int times_printed = 0; times_printed < LETTER_QUANTITY; times_printed++){
        buffer_p = strcat(buffer, BOUNDS);
    }
    printw("%s\n", buffer_p);
}

void print_container(void){
    char buffer[LETTER_QUANTITY * CELL_SIZE];
    buffer[0] = '\0';
    char *buffer_p = buffer;

    for (int times_printed = 0; times_printed < LETTER_QUANTITY; times_printed++){
        buffer_p = strcat(buffer, CONTAINER);
    }
    printw("%s\n", buffer_p);

}
