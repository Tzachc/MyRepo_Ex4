#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#include <string.h>
#define COLAROW 1000
int main(int argc,char* argv[])
{
   char ch;
   int v=0;
   char *dam=(char*)malloc(12*sizeof(char));
   while((ch=getchar())!=EOF)
   if(ch != ',' && ch!= '.'&&ch!='1'&&ch!='2'&&ch!='3'&&ch!='4'&&ch!='5'&&ch!='6'&&ch!='7'&&ch!='8'&&ch!='9'&&ch!='0'
   &&ch!='!'&&ch!='@'&&ch!='#'&&ch!='$'&&ch!='%'&&ch!='^'&&ch!='&'&&ch!='*'&&ch!='('&&ch!=')'){
   dam[v++]=ch;
   dam[v]='\0';
   }
   for(int i=0;dam[i];i++)
   {
       dam[i] = tolower(dam[i]);
   }
   char newS[COLAROW][COLAROW];
   int i,j,ctr;
   j=0;ctr=0;
   for(i=0;i<=(strlen(dam));i++)
   {
       if(dam[i]==' '||dam[i]=='\0'||dam[i]=='\n')
       {
           newS[ctr][j] = '\0';
           ctr++;
           j=0;
       }
       else
       {
           newS[ctr][j] = dam[i];
           j++;
        }
   }
    node* root= getNewNode();
    int y;
    int count = countWords(dam);
     if(argc == 2 && strcmp(argv[1],"r") ==0)
    {
         char* tmp = malloc(12*sizeof(char));
    for(i=0;i<count;++i)
    {
        for(j=i+1;j<count;++j)
        {
            if(strcmp(newS[i],newS[j]) < 0 )
            {
                strcpy(tmp,newS[i]);
                strcpy(newS[i],newS[j]);
                strcpy(newS[j],tmp);
            }
        }
    }
        free(tmp);
    }
    else{
    char* tmp = malloc(12*sizeof(char));
    for(i=0;i<count;++i)
    {
        for(j=i+1;j<count;++j)
        {
            if(strcmp(newS[i],newS[j]) >0 )
            {
                strcpy(tmp,newS[i]);
                strcpy(newS[i],newS[j]);
                strcpy(newS[j],tmp);
            }
        }
    }
        free(tmp);
    }
    for(y=0;y<count;y++)
    {
        insert(root,newS[y]);
    }
    int temp=0;
    for(int j=0;j<count;j++)
    {
        if(search(root,newS[j]) == 1)
        {
            root->count =1;
            for(int k=j+1; k<count;k++)
            {
                if(strcmp(newS[j],newS[k]) == 0)
                {
                    root->count++;
                    temp=k;
                }
            }
            if(root->count == 1)
            {
                printf("%s %ld\n",newS[j],root->count);
            }
            else
            {
                printf("%s %ld\n",newS[j],root->count);
                deletion(&root,newS[temp]);
            }
        }
    }
    free_trie(root);
    free(dam);
    return 0;
}