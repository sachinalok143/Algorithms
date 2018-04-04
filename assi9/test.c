#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	while(n){
	printf("%d",n%2 ); 
	n=n/2;
	}
	printf("\n");
	return 0;
}