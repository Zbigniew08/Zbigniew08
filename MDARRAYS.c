//dyrektywy preprocesora
#include <stdio.h>

#define T 32
#define X 65

//funkcja główna
int main()
{
    //deklaracja tablicy i przypisanie wartości dla pierwszego wiersza
    char sierpinski[T][X] = {[0][32] = '#'};

    int q, w;
    
    //przypisanie wartości elementom tablicy
    for( q = 1; q < T; q++)
    {
        for( w = 0; w < X; w++)
        {
            if( sierpinski[q-1][w] == '#' )
            {
                sierpinski[q][w] = ' ';
            }
            else
            {
                if(sierpinski[q-1][w-1] == '#')
                {
                    if(sierpinski[q-1][w+1] == '#')
                    {
                        sierpinski[q][w] = ' ';
                    }
                    else
                    {
                        sierpinski[q][w] = '#';
                    }
                }
                else
                {
                    if(sierpinski[q-1][w+1] == '#')
                    {
                        sierpinski[q][w] = '#';
                    }
                    else
                    {
                        sierpinski[q][w] = ' ';
                    }
                }
            }
        }
    }
    
    //drukowanie tablicy
    int j, i;
    for( i = 0; i < T; i++)
    {
        for( j = 0; j < X; j++)
        {
            printf("%c ", sierpinski[i][j]);
        }
        printf("\n\n");
    }
    
  return 0;
}
