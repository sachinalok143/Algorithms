#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void swap(int *a,int* b){int temp=*a;*a=*b;*b=temp;}

void heapify(int *S,int l,int i)
{
	//printf("%d\n",i );
	int left=2*i+1;
	int right=2*i+2;
	int parent=(i-1)/2;
	int min=9999999;
	int q=S[i];
	if(left>=l)return;
	if (right>=l)
	{
		if(S[i]>S[left]){swap(&S[i],&S[left]);
		heapify(S,l,parent);}
		return;
	}
	if(S[left]<S[i]){swap(&S[i],&S[left]);}
	if (S[right]<S[i])
	{
		swap(&S[i],&S[right]);
	}
	if(q!=S[i])heapify(S,l,parent);
}

void buidheap(int *S,int l)
{
	for (int i = (int)l/2; i >=0; i--)
	{
		heapify(S,l,i);
	}

}
int extract_min(int *S,int *l)
{
	int p=S[0];
	for (int i = 0; i < (*l)-1; ++i)
	{
		S[i]=S[i+1];
	}
	(*l)--;
	buidheap(S,*l);
	//printf("****%d\n",p );
	return p;
}
void mathod1(int *A,int *B,int m,int n ,int k)
{
	int q=0;
	int *S=(int *)malloc((m*n)*sizeof(int));
	for (int i = 0; i < m; ++i)
	{
		for (int j= 0; j<n; ++j)
		{
			S[q]=A[i]+B[j];
			/*printf("A[%d]+B[%d]=%d\t",i,j,A[i]+B[j]);
			if(q%5==0)printf("\n");*/
			q++;
		}
	}
	buidheap(S,n*m);
	int l=n*m;
	for (int i = 0; i < k; ++i)
	{
		int o=extract_min(S,&l);
		printf("%d\t",o );
	}
}


typedef struct 
{
	int i,j;	
}pair;



void heapifyQ ( pair Q[], int A[], int B[], int size, int i )
{
   int l, r, min;
   pair t;

   while (1) {
      l = 2*i; r = 2*i+1;
      if (l > size) return;
      min = ((l == size) || (A[Q[l].i]+B[Q[l].j] <= A[Q[r].i]+B[Q[r].j])) ? l : r;
      if (A[Q[min].i]+B[Q[min].j] >= A[Q[i].i]+B[Q[i].j]) return;
      t = Q[i]; Q[i] = Q[min]; Q[min] = t;
      i = min;
   }
}

void insertQ(pair* Q,int *A,int *B,int m,int n,int l,pair q)
{
	int i,p;
	i=l+1;
	Q[l+1]=q;
	p=l/2;
	while(1)
	{
		//printf("+++++++++\n");
		if(A[Q[p].i]+B[Q[p].j]<=A[Q[i].i]+B[Q[i].j])return;
		Q[i]=Q[p];Q[p]=q;
		i=p;
	}
}
/*

int printed ( int A[], int B[], pair P[], int l, int i, int j )
{
   int L, U, M, sum, t;
   if ((l == 0) || (i == 0) || (j == 0)) return 0;
   L = 0; U = l-1; sum = A[i]+B[j];
   while (L < U) {
      M = (L + U) / 2;
      if (sum > A[P[M].i] + B[P[M].j]) L = M+1; else U = M;
   }
  if (sum != A[P[L].i] + B[P[L].j]) return 0;
   t = L;
   while ((t >= 0) && (sum == A[P[t].i] + B[P[t].j])) {  
      if ((i == P[t].i) && (j == P[t].j)) return 1;      
      --t;
   }
   t = L + 1;
   while ((t < l) && (sum == A[P[t].i] + B[P[t].j])) {  
      if ((i == P[t].i) && (j == P[t].j)) return 1;     
      ++t;
   }
   return 0;
}
*/


int printed ( int A[], int B[], pair P[], int l, int i, int j )
{
   int L, U, M, sum, t;
   if ((l == 0) || (i == 0) || (j == 0)) return 0;
   printf("+++1\n");

   /* Standard binary search */
   L = 0; U = l-1; sum = A[i]+B[j];
   while (L < U) {
      M = (L + U) / 2;
      if (sum > A[P[M].i] + B[P[M].j]) L = M+1; else U = M;
   }
   printf("+++2\n");
   /* Unsuccessful search */
   if (sum != A[P[L].i] + B[P[L].j]) return 0;
   printf("+++3\n");
   /* Successful search. We assume that the following two loops run for
      a constant number of times. */
   t = L;
   while ((t >= 0) && (sum == A[P[t].i] + B[P[t].j])) {  /* sum matches */
      if ((i == P[t].i) && (j == P[t].j)) return 1;      /* indices also match */
      --t;
   }
      printf("+++4\n");
   t = L + 1;
   while ((t < l) && (sum == A[P[t].i] + B[P[t].j])) {   /* sum matches */
      if ((i == P[t].i) && (j == P[t].j)) return 1;      /* indices also match */
      ++t;
   }
      printf("+++5\n");
   return 0;
}



int tryInsertQ ( pair Q[] , int A[], int B[], int m, int n, int size,int i, int j, pair P[], int l )
{
   if ((i > m) || (j > n)) return 0;
   if ((printed(A,B,P,l,i/2,j)) || (printed(A,B,P,l,i,j/2))) return 0;
	insertQ(Q,A,B,m,n,size,(pair){i,j});
   return 1;
}

void deleteQ( pair Q[] , int A[], int B[], int *size )
{
   Q[0] = Q[(*size)];
   heapifyQ(Q,A,B,(*size)-1,1);
   printf("A=%d,B=%d\n",A[Q[*size].i],B[Q[*size].j] );
}



void mathod2(int *A,int *B,int m,int n,int k)
{
	buidheap(A,m);
	buidheap(B,n);
	int size=0;
	pair* Q=(pair*)malloc((8*k+10)*sizeof(pair));
	//printf("%d-A[0]+B[0]=%d+%d\n",A[0]+B[0],A[0],B[0] );
	pair* p=(pair*)malloc((8*k+1)*sizeof(pair));
	int l=0;
	//p->i=0;
	int w=tryInsertQ(Q,A,B,m,n,size,0,0,p,0);
	size++;
	p[l].i=Q[0].i;
	p[l].j=Q[0].j;
	l++;
	//printf("p----%d-A[%d]+B[%d]=%d+%d\n",A[p[l].i]+B[p[l].j],p[l].i,p[l].j,A[p[l].i],B[p[l].j] );
	//p->j=0;
	int e=0,r=0;
	int u=printed(A,B,p,l,e,r);
	/*pair* p1=(pair*)malloc(sizeof(pair));
	pair* p2=(pair*)malloc(sizeof(pair));
	pair* p3=(pair*)malloc(sizeof(pair));
	pair* p4=(pair*)malloc(sizeof(pair));*/
	for (int i = 0; i < k; ++i)
	{
		u=printed(A,B,p,l,Q[0].i,Q[0].j);

		printf("u=%d\n",u );
		if(u==0)
		{
			printf("%d-A[%d]+B[%d]=%d+%d\n",A[Q[0].i]+B[Q[0].j],Q[0].i,Q[0].j,A[Q[0].i],B[Q[0].j] );
			p[l].i=Q[0].i;
			p[l].j=Q[0].j;
			l++;
			deleteQ(Q,A,B,&size);
			/*p1->i=e;
			p1->j=2*r;
			p2->i=e;
			p2->j=2*r+1;
			p3->i=2*e;
			p3->j=r;
			p4->i=2*e+1;
			p4->j=r;*/
			printf("size=%d\n",size );
			int o=tryInsertQ(Q,A,B,m,n,size,e,2*r,p,l);
			if(o)size++;
			o=tryInsertQ(Q,A,B,m,n,size,e,2*r+1,p,l);
			if(o)size++;
			o=tryInsertQ(Q,A,B,m,n,size,2*e,r,p,l);
			if(o)size++;
			o=tryInsertQ(Q,A,B,m,n,size,2*e+1,r,p,l);
			if(o)size++;
			/*for (int i = 0; i < size; ++i)
			{
				printf("A[Q[%d].i]=%d,B[Q[%d].j]=%d\n",i,A[Q[i].i],i,A[Q[i].j]);
			}*/
			printf("\n");
		}
		if ((u==1))
		{
			deleteQ(Q,A,B,&size);
			size--;
		}
	}


}

int main(int argc, char const *argv[])
{
	int m,n;
	scanf("%d",&m);
	int *A=(int*)malloc(m*sizeof(int));
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&A[i]);
	}
	/*for (int i = 0; i < m; ++i)
	{
		printf("%d\t",A[i] );
		if(i%10==0)printf("\n");
	}*/
	scanf("%d",&n);
	int *B=(int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&B[i]);
	}
	/*for (int i = 0; i < n; ++i)
	{
		printf("%d\t",B[i] );
		if(i%10==0)printf("\n");
	}*/
	int k;
	scanf("%d",&k);
	printf("\n+++method1\n");
	mathod1(A,B,m,n,k);
	printf("\n");
	printf("\n+++method2\n");
	mathod2(A,B,m,n,k);
	return 0;
}