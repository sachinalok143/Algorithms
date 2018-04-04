#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
	int id;
	int f;
}node;


int max(node *A,int n)
{
	int l=0;
	for (int i = 0; i < n; ++i)
	 {
	 	if(l<=A[i].f)l=A[i].f;
	 } 
	return l;
}

void sort(node* A,int n,int k){
	int *count=(int*)malloc((k+1)*sizeof(int));
	node *output=(node*)malloc(n*sizeof(node));
	int i;
	for (int i = 0; i < k+1; ++i)count[i]=0;
	for (int i = 0; i < n; ++i)++count[A[i].f];
	for (int i = 1; i <k+1;++i)count[i]=count[i]+count[i-1];
	for (int i = n-1; i >=0 ; i--)
	 {
	 	output[count[A[i].f]]=A[i];
	 	count[A[i].f]--;
	 	//printf("A[%d].f=%d\n",i,A[i].f);
	 } 

	 for (int i = 1; i <=n; i++)
	 {
	 
	 	A[n-i]=output[i];
	 }

}

bool freindship( node *A,int** M,int n)
{
	int o=0;
	for (int i = 0; i < n; ++i)o=o+A[i].f;
	if(o%2!=0)return false;
	if(n==0)return true;
	int k=max(A,n);
	if(k>=n)return false;
	sort(A,n,k);
/*	for (int i = 0; i <n; ++i)
	{
		printf("A[%d].f=%d\n",i,A[i].f );
	}*/
	int n1;
	for (int i = 0; i < n; ++i)
	{
		if(A[i].f==0){n1=i;break;}
	}
	for (int i = 1; i <=A[0].f; ++i)
	{
		M[A[0].id][A[i].id]=1;
		M[A[i].id][A[0].id]=1;
		A[i].f--;
	}
	A[0].f=0;
	
	freindship(A,M,n1);
}

bool hanshake(node* A,int **M,int n)
{	
    int o=0;
	for (int i = 0; i < n; ++i)o=o+A[i].f;
//	if(o%2!=0)return false;
//	printf("+++++++++++++++\n");
	if(n==0)return true;
	int k=max(A,n);
	sort(A,n,k);
	int n1;
	for (int i = 0; i < n; ++i)
	{
		if(A[i].f==0){n1=i;break;}
	}
	if(n==2){
		sort(A,n,k);
		M[A[0].id][A[n1-1].id]=A[n1-1].f;
		M[A[n1-1].id][A[0].id]=A[n1-1].f;	
		A[0].f=0;
		A[n1-1].f=0;
		return true;	
	}
	if(n==1&&A[0].f!=0)return false;
	/*if(n==3){

		
	}*/

	M[A[0].id][A[n1-1].id]=A[n1-1].f;
	M[A[n1-1].id][A[0].id]=A[n1-1].f;	
	A[0].f=A[0].f-A[n1-1].f;
	A[n1-1].f=0;
	hanshake(A,M,n1);

}



void print_m(node *A,int **M,int n)
	{
		printf("\t\t");
		for (int i = 0; i < 10; ++i){ printf("%d\t", i+1);}

			printf("\tsum\n\t");
			printf("+");
		for (int i = 0; i < 100; ++i)printf("-");
			int *sum=(int*)malloc(n*sizeof(int));
			for (int i = 0; i < n; ++i)sum[i]=0;
		for (int i = 0; i < n; ++i)
		{	
			printf("\n%d\t|\t",i+1);
			int j;
			for ( j = 0; j < n; ++j)
			{	
				sum[i]=sum[i]+M[i][j];
				if(M[i][j]!=0)printf("%d\t",M[i][j] );
				else printf("\t");
			}
			printf("|");
			printf("\t%d",sum[i]);
		}
		printf("\n\t+");
		for (int i = 0; i < 100; ++i)printf("-");
		printf("\nsum\t|\t");
		for (int i = 0; i < n; ++i)
		{
		printf("%d\t",sum[i] );
		}
		printf("|\n");
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	node*  A=(node*)malloc(n*sizeof(node));
	for (int i = 0; i < n; ++i)
	{
	scanf("%d",&A[i].f);
	A[i].id=i;
	}
	int** M=(int**)malloc(n*sizeof(int*));
	for (int i = 0; i < n; ++i)
	{
		M[i]=(int*)malloc(n*sizeof(int));

	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			M[i][j]=0;
		}
	}
	bool nom=freindship(A,M,n);
	if(nom)print_m(A,M,n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			M[i][j]=0;
		}
	}
	//scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
	scanf("%d",&A[i].f);
	A[i].id=i;
	}
	nom=hanshake(A,M,n);
	if(nom)print_m(A,M,n);
	return 0;
}