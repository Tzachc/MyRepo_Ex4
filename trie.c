#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "trie.h"
node* getNewNode()
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->isLeaf=0;
    for(int i=0;i<NUM_LETTERS;i++)
    {
        newNode->children[i]=NULL;
    }
    return newNode;
}
void insert(node* root,char* word)
{
    node* curr = root;
    while(*word)
    {
        //create new node
        if(curr->children[*word - 'a']==NULL)
        curr->children[*word - 'a'] = getNewNode();
        //move to next node
        curr = curr->children[*word - 'a'];
        //next character
        word++;
    }
    //curr node is leaf
    curr->isLeaf=1;
    curr->count++;
}
int haveChildren(node* curr)
{
    for(int i=0;i<NUM_LETTERS;i++)
    if(curr->children[i])
    return 1;//child found
    return 0;
}
int search(struct node* head,char*str)
{
    if(head==NULL)
    return 0;
    struct node* curr = head;
    while(*str)
    {
        curr = curr->children[*str-'a'];
        if(curr==NULL)
        return 0;
        str++;

    }
    if(curr->isLeaf==0)
    {
        curr->count=0;
    }
    else
    {
        curr->count=1;
    }
    return curr->isLeaf;
}
void free_node(node* n)
{
    int i;
    if(n==NULL)
    {
        return;
    }
    if(0==haveChildren(n))
    {
        free(n);
    }
    else
    {
        for(i=0;i<NUM_LETTERS;i++)
        {
            free_node((n->children)[i]);
        }
    }
    return;
}
void free_trie(node* t)
{
    int i;
    if(t==NULL)
    return;
    for(i=0;i<NUM_LETTERS;++i)
    {
        free_node(t->children[i]);
    }
    free(t);
}
 int myCompare(const void* a,const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}
void sort(const char* arr[],int n)
{
    qsort(arr,n,sizeof(const char*),myCompare);
}
int deletion(struct node** curr,char* str)
{
    if(*curr==NULL)
    return 0;
    if(*str)
    {
        if(*curr!=NULL && (*curr)->children[*str - 'a'] != NULL&&
        deletion(&((*curr)->children[*str -'a']), str+1)&&
        (*curr)->isLeaf==0)
        {
            if(!haveChildren(*curr))
            {
                free(*curr);
                (*curr)=NULL;
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    if(*str =='\0' && (*curr)->isLeaf)
    {
        if(!haveChildren(*curr))
        {
            free(*curr);
            (*curr) = NULL;
            return 1;
        }
        else
        {
            (*curr)->isLeaf =0;
            return 0;
        }
    }
    return 0;
}
int words(const char* string)
{
    int count=0,i,len;
    char lastC;
    len=strlen(string);
    if(len>0)
    {
        lastC=string[0];
    }
    for(i=0;i<=len;i++)
    {
        if((string[i]==' '||string[i]=='\0')&&lastC!=' ')
        {
            count++;
        }
        lastC=string[i];
    }
return count+1;
}
unsigned countWords(char* str)
{
    int state = OUT;
    unsigned wc =0; //words count
    while(*str)
    {
        if(*str == ' '|| *str =='\n' || *str == '\t')
        state = OUT;
        else if(state ==OUT )
        {
            state = IN;
            ++wc;
        }
        ++str;
    }
    return wc;
}