#include "../include/main.h"

game_settings *create_default_session(){

    game_settings *game = malloc(sizeof(game_settings));
    game ->n_letters = 5;
    game ->chances = 6;
    game ->language = EN;
    game ->won = false;  

    return game;
}


void show_invalid_message(int language, Position_t *_cursor){

    _cursor ->x += 6;
    move (_cursor ->y, _cursor -> x);
    if (language == EN){
        printw("Not a word!");
    }
    else {
        printw("Palabra Invalida!");
    }
    curs_set(0);
    refresh();

    napms(1000);
    curs_set(1);
    move _CURRENT_POSITION;
    printw("                 "); 
    return;
}

void show_guessed_letters(enum Color *color_list, char *guess, Position_t *_cursor){
    bool won = false;

    _cursor ->x = START_OF_LINE;
    move _CURRENT_POSITION;

    for (int i = 0; i < LETTER_QUANTITY; i++){

        if (color_list[i] == RED){
            attron(COLOR_PAIR(3));
            addch(guess[i] MAKE_UPPER);
            attroff(COLOR_PAIR(3));

        }
        else if (color_list[i] == GREEN){
            attron(COLOR_PAIR(1));
            addch(guess[i] MAKE_UPPER);
            attroff(COLOR_PAIR(1));      
        }
        else if (color_list[i] == YELLOW){
            attron(COLOR_PAIR(2));
            addch(guess[i] MAKE_UPPER);
            attroff(COLOR_PAIR(2));
            
        }
        _cursor ->x RIGHT;
        move _CURRENT_POSITION;
        refresh();
    }

    _cursor ->x = START_OF_LINE;
    _cursor ->y DOWN;   
    move _CURRENT_POSITION;
    refresh();
    return;
}


bool is_answer(enum Color *color_list){
    bool match = true;
    for (int i = 0; i < LETTER_QUANTITY; i++){
        if (color_list[i] != GREEN){
            match = false;
        }
    }
    return match;
}

void start_curses(void){
    initscr();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
}


int main(void){

    game_settings *game = create_default_session();
    start_curses();

    start_menu(game);
    node *trie = create_trie(game ->language);
    clear();

    Position_t cursor = {2, 1};
    enum Color *attempt_tracker[game ->chances];


    char *answer = get_random_word(trie);
    make_grid(game);
    printw("%s", answer);
    refresh();

    for (int attempt_number = 0; attempt_number < game ->chances; attempt_number++) {    
        
        char *guess = get_guess(&cursor);

        if (is_word(guess, trie)){
            enum Color *letter_colors = check_guess(guess, answer);
            attempt_tracker[attempt_number] = letter_colors;
    
            if (is_answer(letter_colors)){
                game ->won = true;
                end_game(game, attempt_number + 1, attempt_tracker, answer);
                return 0;
            }
            else {
                show_guessed_letters(letter_colors, guess, &cursor);
            }
        }
        else {
            show_invalid_message(game ->language, &cursor);
            erase_line(&cursor);
            attempt_number --;
            refresh();
        }   
    }
    end_game(game, game ->chances, attempt_tracker, answer);
    endwin();
}