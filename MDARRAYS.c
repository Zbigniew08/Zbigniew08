#include <stdio.h>

#define T 32
#define X 65

int main()
{
    char sierpinski[T][X] = {[0][32] = '#'};
    
    for( int q = 1; q < T; q++)
    {
        for( int w = 0; w < X; w++)
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
                        
                    }
                }
            }
        }
    }
    
    //int j, i=0;
    //for( j = 0; j < X; j++)
    //{
    //    printf("%c\t", sierpinski[i][j]);
    //}
    
  return 0;
}
