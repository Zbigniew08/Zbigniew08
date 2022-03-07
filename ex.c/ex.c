#include <stdio.h>

#define SIZE 100
#define STEPS 1

int main()
{
    char algae[SIZE] = {'A'};
    char *glon = algae;

    char h[SIZE] = {'A'};
    char *glonh = h;
    int j;

    for(j=0; j < STEPS; j++)
    {
        while(*glon != '\0')
        {
            if(*glon == 'A')
            {
                *glonh = 'A';
                glonh++;
                *glonh = 'B';
                glon++;
            }
            else
            {
                *glonh = 'B';
                glonh++;
                *glonh = 'A';
                glon++;
            }
        }
        glon = h;
        glonh = algae;
    }

    *glon = algae;
    *glonh = h;
    while(*glon != '\0')
    {
        printf("%c", *glon++);
    }

    printf("\n");

    while(*glonh != '\0')
    {
        printf("%c", *glonh++);
    }

    return 0;
}