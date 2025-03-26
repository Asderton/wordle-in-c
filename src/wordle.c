#include "wordle.h"

void main(void){

    node *trie = create_tree();


    initscr();
    Position_t cursor = {START_POSITION};
    
    make_grid();
    refresh();

    for (int tries = 0; tries < CHANCES; tries++) {    
        char *guess = get_guess(&cursor);

        // Space for answer-validation and coloration
        free(guess);
        refresh();
    }
  
    refresh();
    getch();
    endwin();

}