#include <stdio.h>
#include <stdlib.h>

void dynamics( char*[], int);
void print(char*[], int);

int main( int argc, char *argv[])
{
    int iter = (int)(*(*(argv+1))) - '0';
	if (argc<2)
	{
		printf("Podaj wartość tmax");
	}
	iter=atoi(argv[1]);
	char *sierpinski[iter];
	dynamics(sierpinski,iter);
	print(sierpinski,iter);
	return 0;
}


void dynamics(char *data[], int iter)
{
	int i, j, n, k = 9;
	data[0] = "A00100B";
 	for (i=1; i<iter+1; i++, k+=2)
    {
  		*(data+i) = malloc(k * sizeof(char));
		for (j=0, n=0; j<k-2; j++, n++)
	    {
			switch(*(*(data+i-1)+j))
		  	{
				case 'A':
					*(*(data+i)+n)='A';
					n+=1;
					*(*(data+i)+n)='0';
					break;
			    case 'B':
					*(*(data+i)+n)='0';
					n+=1;
					*(*(data+i)+n)='B';
					break;
				case '0':
					if((*(*(data+i-1)+j-1)=='1') ^ (*(*(data+i-1)+j+1)=='1'))
					{
						*(*(data+i)+n)='1';
					}
					else
					{
						*(*(data+i)+n)='0';
					}
					break;
		        case '1':
					*(*(data+i)+n)='0';
					break;
		       
			}
		}
    }
}
void print(char *data[], int iter)
{
    int i, j, k=7;
    for (i=0; i<iter+1; i++, k+=2)
    {
	    for (j=iter-i; j>0; j--) 
		{
			printf(" ");
		}
	    for (j=0; j<k; j++)
	    {
		    switch (*(*(data+i)+j))
		    {
			    case 'A':
			    	printf("A");
			    	break;
			    case 'B':
			      	printf("B");
			      	break;
			    case '0':
			      	printf("_");
			      	break;
			    case '1':
			      	printf("#");
			     	break;
			}
		}
	}
	printf("\n");
}
