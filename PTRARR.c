#include <stdio.h>
#include <stdlib.h>

void dynamics( char*[], int);

int main( int arg, char *argv[])
{
    int iter = (int)(*(*(argv+1))) - '0';
    char *sierpinski[iter];
    dynamics( sierpinski, iter);

    return 0;
}

void dynamics( char *data[], int iter)
{
    int i, k = 8;
    data[0] = "A..#..B";
    (data + 1) = malloc(k * sizeof(char));
}