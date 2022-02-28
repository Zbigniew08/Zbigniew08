#include <stdio.h>

#define SIZE 100

void dynamics()

int main()
{
    char algae[SIZE];
    char *algaew = algae;

    *algaew = 'A';
    for(int i=0; i < SIZE; i++)
    {
        if(*algaew == 'A') 
        {
            *++algaew = 'B'
        }
        else
        {
            *algaew = 'A';
        }
    }

    return 0;
}

void dynamics()
{
    
}
