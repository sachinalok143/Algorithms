#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	printf("%d\n",(int)(1+(log(n)/log(3/2))));
	return 0;
}