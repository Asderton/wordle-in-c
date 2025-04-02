#ifndef VALIDATE_H
#define VALIDATE_H

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "utilities.h"


//Settings for the trie
#define MAX_CHILDREN 26
#define EN_WORDS "EN-WORDS.txt"
#define ES_WORDS "ES-WORDS.txt"
#define ANSWER "erase"


typedef struct node{
    struct node *children[MAX_CHILDREN];
    bool is_leaf;
} node;

//Guess validation
enum Color *check_guess(char *guess, char* answer);

//Check if guess is in the trie
bool is_word(char *word, node *root);

//Creation of the trie
node *create_trie(int lan);
node *create_node(void);
void add_word(char *word, node *root);
char *get_random_word(node *root);

#endif