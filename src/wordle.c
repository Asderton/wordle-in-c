#include "wordle.h"

void main(void){

    node *trie = create_tree();

    initscr();
    Position_t cursor = {START_POSITION};

    make_grid();
    refresh();

    for (int tries = 0; tries < CHANCES; tries++) {    
        char *guess = get_guess(&cursor);
        
        // Validate if guess is a word
        if (in_trie(guess, trie) == false){

            cursor.x RIGHT;
            move(cursor.y, cursor.x);

            printw("Palabra Invalida!");
            curs_set(0);
            refresh();

            napms(1000);
            curs_set(1);
            move(cursor.y, cursor.x);
            printw("                 ");
            erase_line(&cursor); 
            refresh();

            tries--;
            
            napms(100);
        }
        else{

            // COMPARE AND PAINT HERE

            cursor.x = 2;
            cursor.y += 4;    

        }


        // Space for answer-validation and coloration
        free(guess);
        refresh();
    }
  
    refresh();
    getch();
    endwin();

}