#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int a,b,c;
	head *H;
}node;
t


void  gengraph(int *a,int *c,int n) 
{
	int *q=(int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i)q[i]=a[i];
	int T=0;
	for (int i = 0; i < n; ++i)
	{
		T=T+c[i];
	}

}


int main(int argc, char const *argv[])
{
	int n=3;
///	scanf("%d",&n);
	int *c=(int*)malloc(n*sizeof(int));
	int *a=(int*)malloc(n*sizeof(int));
	int *b=(int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i)scanf("%d",&c[i]);
	for (int i = 0; i < n; ++i)scanf("%d",&a[i]);
	//for (int i = 0; i < n; ++i)scanf("%d",&b[i]);
	printf("Capacities:\t(");
	for (int i = 0; i < n; ++i)printf("%d,",c[i]);
	printf(")\nStart:\t(");
	for (int i = 0; i < n; ++i)printf("%d,",a[i]);
		printf(")\n");
/*	printf(")\nEnd:\t(");
	for (int i = 0; i < n; ++i)printf("%d,\t",b[i]);
	printf(")\n");*/
		gengraph(a,c,n);
	return 0;
}