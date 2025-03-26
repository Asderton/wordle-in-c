#include "../headers/validate.h"



//Guess validation
enum Color *check_guess(char *guess, char* answer){

    enum Color *display_colors = malloc(sizeof(enum Color) * 5);
    char* _answer = malloc(sizeof(answer));
    for (int i = 0; i < LETTER_QUANTITY; i++){
        _answer[i] = answer[i];
    }

    for (int i = 0; i < LETTER_QUANTITY; i++){
        for (int j = 0; j < LETTER_QUANTITY; j++){
            if(guess[i] == _answer[j]){
                if (i == j){
                    display_colors[i] = GREEN;
                    _answer[j] = ' ';
                    break;
                }
                else {
                    display_colors[i] = YELLOW;
                    _answer[j] = ' ';
                    break;
                }
            }
            display_colors[i] = RED;
        }
    }
    return display_colors;
}


//Cheks if guess is in the trie (Deberia llamar al parametro guess Sami?)
bool is_word(char *word, node *root){
    
    node * trie_p = root;

    for (int i = 0; i < strlen(word); i++){

        int index = word[i] - 'a';
        if (trie_p -> children[index] != NULL){
            trie_p = trie_p -> children[index];
        }
        else{
            return false;
        }
    }
    if (trie_p -> is_leaf){
        return true;
    }
    else {
        return false;
    }
}


//Creation of the trie
node *create_trie(void){

    node *root = malloc(sizeof(node));
    root = create_node();
    FILE *file_p = fopen(TRIE_FILE, "r"); 

    if (file_p == NULL){
        printf("No hay archivo\n");
        return 0;
    }

    char current_word[40];
    while (fscanf(file_p, "%s", current_word) != EOF){
        add_word(current_word, root);
    }

    fclose(file_p);
    return root;
}

node *create_node(void){
    node *new_node = malloc(sizeof(node));

    for (int i = 0; i <= MAX_CHILDREN; i++){
        new_node -> children[i] = NULL;
    }

    new_node -> is_leaf = false;
    return new_node;
}

void add_word(char *word, node *root){

    node *trie_p = root;

    for (int i = 0; i < strlen(word); i++){
        int index = word[i] - 'a';

        if(trie_p -> children[index] == NULL){
            trie_p -> children[index] = create_node();
        }
        trie_p = trie_p -> children [index];
    }

    trie_p -> is_leaf = true;
}

char *get_random_word(node *root){
    node *trie_p = root;
    char *answer = malloc(sizeof(char) * LETTER_QUANTITY);
    srand(time(NULL));

    for (int i = 0; i < LETTER_QUANTITY; i++){
        int index = rand() % 26;
        if (trie_p -> children[index] != NULL){
            answer[i] = index + 'a';
            trie_p = trie_p -> children[index];
        }
        else{
            i--;
        }
    }
    return answer;
}