#include <stdio.h>
#include <stdlib.h>

#define  n 1000000

extern void registerme ( const char * );
extern int readbit ( int , int );
extern void checksolution ( int );

void bin(int i,int *A)
{	int j=0;
	while(i)
	{
		A[j]=i%2;
		i=i/2;
		j++;
	}
}

int findmissing()
{
	int *A=(int*)malloc((n*log(n)/log(2))*sizeof(int));
	for (int i = 0; i < ; ++i)
	{
		/* code */
	}
	for (int i = 0; i < count; ++i)
	{
		bin(i,A);
	}
}

int main(int argc, char const *argv[])
{
	int x;
	registerme("99FB1331");
	x = findmissing();
	printf("x = %d\n", x);
	checksolution(x);
	exit(0);
	return 0;
}