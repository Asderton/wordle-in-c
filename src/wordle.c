#include "../headers/wordle.h"

int main(void){

    node *trie = create_trie();

    initscr();
    Position_t cursor = {START_POSITION};
    enum Color *attempt_tracker[CHANCES];
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    char *answer = get_random_word(trie);

    make_grid();
    refresh();


    //Dato curioso: Tenia tries pero se confundia despues con la estructura de datos
    for (int attempts = 0; attempts < CHANCES; attempts++) {    
        char *guess = get_guess(&cursor);
        
        // Validate if guess is a word
        if (is_word(guess, trie) != true){
            cursor.x RIGHT;
            move CURRENT_POSITION;

            printw("Palabra Invalida!");
            curs_set(0);
            refresh();

            napms(1000);
            curs_set(1);
            move CURRENT_POSITION;
            printw("                 ");
            erase_line(&cursor); 
            refresh();
            attempts--;
        
            napms(100);
        }

        else{

            cursor.x = START_OF_LINE;
            move CURRENT_POSITION;

            enum Color *letter_colors = check_guess(guess, answer);
            attempt_tracker[attempts] = letter_colors;
            int green_counter = 0;

            for (int i = 0; i < LETTER_QUANTITY; i++){

                if (letter_colors[i] == RED){
                    attron(COLOR_PAIR(3));
                    addch(guess[i] MAKE_UPPER);
                    attroff(COLOR_PAIR(3));

                }
                else if (letter_colors[i] == GREEN){
                    attron(COLOR_PAIR(1));
                    addch(guess[i] MAKE_UPPER);
                    attroff(COLOR_PAIR(1));
                    green_counter++;
                    if (green_counter == LETTER_QUANTITY){
                        end_game(true, attempts + 1, attempt_tracker, answer);
                        return 0;
                    }
                  
                }
                else if (letter_colors[i] == YELLOW){
                    attron(COLOR_PAIR(2));
                    addch(guess[i] MAKE_UPPER);
                    attroff(COLOR_PAIR(2));
                    
                }
                cursor.x RIGHT;
                move CURRENT_POSITION;
                refresh();
             }

            cursor.x = START_OF_LINE;
            cursor.y DOWN;   
            move CURRENT_POSITION;
            refresh();
        }
        free(guess);
        refresh();
    }

    end_game(false, CHANCES, attempt_tracker, answer);
    endwin();

}

void end_game(bool won, int attempts, enum Color **attempt_color_code, char *answer){
    
    clear();
    printw("|--------------------------------|\n");
    printw("|                                |\n");
    if(won)
        printw("|            You Won!            |\n");
    else
        printw("|            You Lost!           |\n");
    printw("|                                |\n");
    printw("|          The word was:         |\n");
    printw("|             \"%s\"            |\n", answer);
    printw("|                                |\n");
    printw("|         Your attempts:         |\n");
    printw("|                                |\n");//*****
    printw("|                                |\n");//***** 
    printw("|                                |\n");//***** 
    printw("|                                |\n");
    printw("|         Key to continue        |\n");
    printw("|--------------------------------|\n");
    

    Position_t cursor = {10, 9};
    move CURRENT_POSITION;
    for (int i = 0; i < attempts; i++){
        enum Color *_attempt_color_code = attempt_color_code[i];
        for (int j = 0; j < LETTER_QUANTITY; j++){
            
            if (_attempt_color_code[j] == GREEN){
                attron(COLOR_PAIR(1));
                addch('*');
                attroff(COLOR_PAIR(1));
            }
            else if (_attempt_color_code[j] == YELLOW){
                attron(COLOR_PAIR(2));
                addch('*');
                attroff(COLOR_PAIR(2));
            }
            else if (_attempt_color_code[j] == RED){
                attron(COLOR_PAIR(3));
                addch('*');
                attroff(COLOR_PAIR(3));
            }
        }
        switch (i){

            case 0:
            case 1:
                cursor.y++;
                cursor.x = 10;
                move CURRENT_POSITION;
                break;

            case 2:
                cursor.y = 9;
                cursor.x =18;
                move CURRENT_POSITION;
                break;
            
            case 3:
            case 4:
            case 5:
                cursor.y++;
                cursor.x = 18;
                move CURRENT_POSITION;
                break;
        }       
     }

        
    curs_set(0);
    refresh();
    getch();
    endwin();
}
