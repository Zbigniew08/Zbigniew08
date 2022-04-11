#include <stdlib.h>
#include <stdio.h>
//#include "turtle.h"  

typedef struct Koch
{
    char c;
    struct Koch *pNext;
}Koch_t;


void build_list(Koch_t *pRoot, int i)
{
    Koch_t *pEle1 = malloc(sizeof(Koch_t));
    Koch_t *pEle2 = malloc(sizeof(Koch_t));
    Koch_t *pEle3 = malloc(sizeof(Koch_t));
    Koch_t *pEle4 = malloc(sizeof(Koch_t));
    pRoot -> pNext = pEle1;
    pEle1 -> c = '+';
    pEle1 -> pNext = pEle2;
    pEle2 -> c = '-';
    pEle2 -> pNext = pEle3;
    pEle3 -> c = '-';
    pEle3 -> pNext = pEle4;
    pEle4 -> c = '+';
    pEle4 -> pNext = NULL;
    
    Koch_t *pEle11 = malloc(sizeof(Koch_t));

    

  
}

void print_list(Koch_t *pRoot)
{
    while(pRoot != NULL)
    {
        printf("%c", pRoot -> c);
        pRoot = pRoot -> pNext;
    }

  
}

void draw_koch(/* argumenty przesłane przez referencje i przez wartość*/){

  /* Korzystacie z biblioteki turtle.h                                */
  /* Wielkość rysunku, kroku oraz wartość początkowa                  */
  /* miejsca rysowania jest określana w pliku konfiguracyjnym         */
 
}


int main(){
    Koch_t *pRoot = malloc(sizeof(Koch_t));
    int i;
    
    build_list(pRoot, i);
    print_list(pRoot);
    //draw_koch(/* argumenty */);

    return 0;
}



//+--+ + +--+ - +--+ - +--+ + +--+ + +--+ + +--+ - +--+ - +--+ + +--+ - +--+ + +--+ - +--+ - +--+ + +--+ - +--+ + +--+ - +--+ - +--+ + +--+ + +--+ + +--+ - +--+ - +--+ + +--+
//+--+ + +--+ - +--+ - +--+ + +--+
//+--+