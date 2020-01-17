#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM_LETTERS ((int)26)
#define OUT 0
#define IN 1
typedef enum {FALSE =0,TRUE=1} boolean;
typedef struct node
{
    long unsigned int count;
    struct node* children[NUM_LETTERS];
    int isLeaf; //should return 1 if it is a leaf
}node;
node* getNewNode();
int search(struct node* head,char*str);
int words(const char* string);
void insert(node* root,char* word);
void free_trie(node* t);
void free_node(node* n);
int haveChildren(struct node* curr);
int deletion(struct node** curr,char* str);
void sort(const char* arr[],int n);
unsigned countWords(char* str);
int myCompare(const void* a,const void* b);
