//Dyrektywy preprocesora
#include <stdlib.h>
#include <stdio.h> 
#include "turtle.h" 


//Deklaracje funkcji
char * strtok( char *, const char *);

void build_list(Node *, Node *, int);

void print_list(Node *);

void draw_koch(Node *, int, int);

//Stuktury
typedef struct Koch
{
    char c;
    struct Koch *pNext;
}Node;

struct Config
{
    int iter;
    int width;
    int height;
};

//Funkcja główna.
int main()
{
    Node* pRoot = malloc(sizeof(Node));
    struct Config config;
    char * line = NULL;
    char *odczyt;
    size_t lenght;
    int i, n = 1;
    pRoot->pNext = NULL;
    
    FILE* configf = fopen("config.txt", "r");
    if (configf == NULL)
    {
        printf("Brak informacji w pliku config");
    }
    while(getline(&line, &lenght, configf) != -1)
    {
        odczyt = strtok(line, "=");
        i = 1;
        while( odczyt != NULL )
        {
            if(i == 2)
            {
                if(n==1) config.iter = atoi(odczyt);
                else if(n==2) config.width = atoi(odczyt);
                else if(n==3) config.height = atoi(odczyt);
            }
            odczyt = strtok(NULL, "=");
            i++;
        }
        n++;
    }
    build_list(pRoot, pRoot->pNext, config.iter);
    print_list(pRoot);
    draw_koch(pRoot, config.width, config.height);

    return 0;
}

//Funkcja tworzy listę.
void build_list(Node *pRoot, Node *pLast, int iter)
{
    Node* pElement1 = malloc(sizeof(Node));
    Node* pElement2 = malloc(sizeof(Node));
    Node* pElement3 = malloc(sizeof(Node));
    Node* pElement4 = malloc(sizeof(Node));
    pRoot->pNext = pElement1;
    pElement1->c = '+';
    pElement1->pNext = pElement2;
    pElement2->c = '-';
    pElement2->pNext = pElement3;
    pElement3->c = '-';
    pElement3->pNext = pElement4;
    pElement4->c = '+';
    pElement4->pNext = pLast;
   if(iter > 1)
    {
        build_list(pRoot, pRoot->pNext, --iter);
    }
    
    if(pLast != NULL)
    {
        build_list(pLast, pLast->pNext, --iter);
    }
}

//Funkcja drukuje zawartość
void print_list(Node *pRoot)
{
    while(pRoot->pNext != NULL)
    {
        pRoot = pRoot->pNext;
        printf("%c", pRoot->c);

    }
}

//Funkcja kożystając z biblioteki turtle.c rysuje oraz zapisue obraz.
void draw_koch(Node *pRoot, int width, int height)
{
    turtle_init(width, height);

    while(pRoot != NULL)
    {
        if(pRoot->c == '+')
        {
            turtle_forward(5);
            turtle_turn_left(90);
        }
       else if(pRoot->c == '-')
        {
            turtle_forward(5);
            turtle_turn_right(90);
        }
        pRoot = pRoot->pNext;
    }
    turtle_draw_turtle();
    turtle_save_bmp("Koch.bmp");
}


//+--+ + +--+ - +--+ - +--+ + +--+ + +--+ + +--+ - +--+ - +--+ + +--+ - +--+ + +--+ - +--+ - +--+ + +--+ - +--+ + +--+ - +--+ - +--+ + +--+ + +--+ + +--+ - +--+ - +--+ + +--+
//+--+ + +--+ - +--+ - +--+ + +--+
//+--+
