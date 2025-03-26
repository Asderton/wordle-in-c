#include "validate.h"


//Function that checks how similar is the guess to the answer
enum Color *check_guess(char *guess, char* answer){

    enum Color *display_colors = malloc(sizeof(enum Color) * 5);

    for (int i = 0; i < strlen(guess); i++){
        for (int j = 0; j < strlen(answer); j++){

            if(guess[i] == answer[j]){

                if (i == j){
                    display_colors[i] = GREEN;
                    break;
                }

                else {
                    display_colors[i] = YELLOW;
                    break;
                }

            }
            display_colors[i] = RED;
            
        } //TERMINA EL J

    }
    return display_colors;
}

//Function that creates an empty node
node *create_node(void){
    node *new_node = malloc(sizeof(node));

    for (int i = 0; i <= MAX_CHILDREN; i++){
        new_node -> children[i] = NULL;
    }

    new_node -> is_leaf = false;
    return new_node;
}

//Function that adds a word to the trie
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

//Function that creates a trie from a file
node *create_tree(void){

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

//Function that returns true if a given word is in the given trie
bool in_trie(char *word, node *root){

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