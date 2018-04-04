#include<stdio.h>
#include<stdlib.h>

int k;
int i;
void getNum(int j,int n,int sum,int *A)
{
  printf("+++++%d\n",sum );
if(n<=0||sum<0)return;
if(sum==0)
	{
	int *B=(int*)malloc(k*sizeof(int*));
	for(i=0;i<10;i++)B[A[i]]++;
	for(i=0;i<10;i++)if(A[i]!=B[i])break;
		else
		if(i==k-1){
		for(i=0;i<10;i++)printf("%d",A[i] );
			printf("\n");
		}

	return;
	}
for(i=0;i<10;i++)
	{
	  if(sum-i>=0)
		{
			printf("%i\n",i );
	      A[j]=i;
	      j++;
	      getNum(j,n-1,sum-i,A);
		}
	}
return;
}
void getNum1(int n,int *A)
{

  int i;
for(i=1;i<10;i++)
	{
	  if(n-i>=0)
		{
	      A[0]=i;
	      getNum(1,n-2,n-i,A);
		}
 	}
}

int main()
{
int i,n;
scanf("%d",&n);
k=n;
int* A=(int*)malloc(n*sizeof(int*));
for(i=0;i<n;i++)A[i]=0;
getNum1(n,A);
return 0;
}
