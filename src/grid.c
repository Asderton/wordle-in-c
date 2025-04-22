#include "../include/grid.h"


//Movement along the lines
char *get_guess(Position_t *_cursor){
    noecho();

    char *word_guessed = malloc(sizeof(char) * (LETTER_QUANTITY + 1));

    for (int letter_index = 0; letter_index < LETTER_QUANTITY; letter_index++){
        
        move _CURRENT_POSITION;
        char letter_guessed = getch();
        if (letter_guessed >= 'a' && letter_guessed <= 'z'){
            letter_guessed MAKE_UPPER;
        }
        refresh();

        if (letter_guessed == 27 && _cursor -> x > 2){
            _cursor -> x LEFT;
            move _CURRENT_POSITION;
            addch(' ');
            refresh();

            word_guessed[letter_index] = ' ';
            letter_index --;
        }

        //Use un switch nomas para practicarlo
        switch(letter_guessed){
            case 'A'...'Z':

                if (letter_index != LETTER_QUANTITY - 1){
                addch(letter_guessed);
                _cursor->x RIGHT;
                word_guessed[letter_index] = letter_guessed MAKE_LOWER;
                }
                else {
                addch(letter_guessed);
                refresh();
                word_guessed[letter_index] = letter_guessed MAKE_LOWER;
                }
                break;

            default:
                letter_index--;
                break;
        }  
    }

    word_guessed[LETTER_QUANTITY] = '\0';
    return word_guessed;
}

void erase_line(Position_t *_cursor){
    _cursor -> x = START_OF_LINE;
    move _CURRENT_POSITION;
    for (int i = 0; i < LETTER_QUANTITY; i++){
        addch(' ');
        _cursor -> x RIGHT;
        move _CURRENT_POSITION;
    }
    _cursor -> x = START_OF_LINE;
    move _CURRENT_POSITION;
}



//Creation of the rows 
void make_grid(game_settings *game){
    for (int squares_printed = 0; squares_printed < game ->chances; squares_printed++){
        print_bound();
        print_container();
        print_bound();
        printw("\n");
    }
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
