#include <stdio.h>

void swap(int *a,int* b){int temp=*a;*a=*b;*b=temp;}

int main(int argc, char const *argv[])
{
	int a=5,b=0;
	swap(&a,&b);
	printf("a=%d,b=%d\n",a,b);
	return 0;
}