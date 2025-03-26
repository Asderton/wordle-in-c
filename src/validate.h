#ifndef VALIDATE_H
#define VALIDATE_H
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CHILDREN 26
#define TRIE_FILE "palabras.txt"
#define ANSWER "erase"

enum Color {RED, YELLOW, GREEN};


typedef struct node{
    struct node *children[MAX_CHILDREN];
    bool is_leaf;
} node;


node *create_tree(void);
node *create_node(void);
void add_word(char *word, node *root);
bool in_trie(char *word, node *root);
enum Color *check_guess(char *guess, char* answer);


#endif