#include "grid.h"


//Prints the cells
void make_grid(void){
    for (int squares_printed = 0; squares_printed < CHANCES; squares_printed++){
        print_bound();
        print_container();
        print_bound();
        printw("\n");
    }
}

//El nombre del parametro es el utilizado en los define, no cambiar, preguntar a sami si es mala idea xD
char *get_guess(Position_t *_cursor){
    refresh();
    noecho();
    char *word_guessed = malloc(sizeof(char) * LETTER_QUANTITY);

    for (int letter_index = 0; letter_index < LETTER_QUANTITY; letter_index++){
        
        move _CURRENT_POSITION;
        char letter_guessed = getch();
        refresh();

        if (letter_guessed == 27 && _cursor -> x > 2){
            _cursor -> x LEFT;
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
                _cursor->x RIGHT;
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
    _cursor -> x = 2;
    _cursor -> y += 4;
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
