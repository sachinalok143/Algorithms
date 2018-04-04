#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node
{
  int bday,sday;
  float value;
};
typedef struct node prof;	
int o,p,x,y;
int merge(int *B,int *S,int c,int low,int mid,int high)
{

	int min=99999999,m,max=0,M;
	for (int i = 0; i <mid; ++i)
	{
		if(B[i]<=min)
		{
			min=B[i];
			m=i;
		}
	}
	x=m;
	//printf("mid=%d,",mid );
	for (int i = mid; i <= high; ++i)
	{
		if(S[i]>=max)
		{
			max=S[i];
			M=i;
		}
	}
	y=M;
	int l=(int)(c/B[m])*(S[M]-B[m]);
	//printf("S[%d]=%d,B[%d]=%d\n",M,S[M],m,B[m] );
	return l;
}
int MAX(int a,int b)
{
	if(a>b)return a;else return b;
}
int devide(int *B,int *S,int n,int c,int low,int high)
{
	//printf("***\n");
	int i=0;
	int mid=(int)(low+high)/2;
	//printf("high=%d,low=%d,mid=%d\t",high,low,mid);
	if(low == high){o=low;p=low; return (int)(c/B[low])*(S[low]-B[low]);}
	//printf("B[%d]=%d\n",i,B[i] );
	int a=devide(B,S,n,c,low,mid);
	int b=devide(B,S,n,c,(int)(low+high+1)/2,high);
	int d=merge(B,S,c,low,(int)(low+high+1)/2,high);
	//printf("a=%d,b=%d,d=%d\n",a,b, d);
	int max=MAX(MAX(a,b),d);
	if(max==d){o=x;p=y;}
	return max;
}







void singleTranc1(int *B,int *S,int n,int c)
{
	int l= devide(B,S,n,c,0,n-1);
	printf("max profite=%d\n",l );
	printf("Buying date:\t%d\t Buying rate:\t%d\t\nSelling date:\t%d\tSelling rate:\t%d\n\n",o,B[o],p,S[p]);
}





void multiTranc(int *B,int *S,int n,int c)
{
	printf("+++MultiTranc:\n");
	int *T=(int*)malloc(n*sizeof(int));
	int *C=(int*)malloc(n*sizeof(int));
	int *bday=(int*)malloc(n*sizeof(int));
	int l=0;
	T[0]=(c/B[0])*(S[0]-B[0]);
	C[0]=c+T[0];
	bday[0]=0;
	int max=0;
	int u=0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <=i; ++j)
		{
			if(max<=(T[j-1]+(C[j-1]/B[j])*(S[i]-B[j])))
				{
					max=(T[j-1]+(C[j-1	]/B[j])*(S[i]-B[j]));
					u=j;
				}
		}
	bday[i]=u;
	T[i]=max;
	C[i]=c+T[i];
	}
	int i=n;
	for (int i = 0; i < n; ++i)
	{
	//	printf("bday[%d]-%d\n",i,bday[i] );
	}
	printf("Maximum profite:%d\n",T[n-1] );
	while(i--)
	{
		printf("Buying day:%d\tbuying rate:%d\nSelling day:%d Selling rate:%d\n\ncapital at end of day:%d\n",bday[i],B[bday[i]],i,S[i],C[i]);
		i=bday[i];
	}
	//printf("Buying day:%d\tbuying rate:%d\nSelling day:%d Selling rate:%d\n\ncapital at end of day:%d\n",bday[i],B[bday[i]],i,S[i],C[i]);
	for (int i = 0; i < n; ++i)
	{
	//printf("\nT[%d]:%d,C[%d]=%d \n",i,T[i],i,C[i]);
	}
}


/*


float max(float P[],int n)
{
  int i;
  float max=0;
  for(i=0;i<n;i++)
    {
      if(max<=P[i]){max=P[i];}
    }


  return max;
}


void print(prof T[],int n,float c[],int B[],int S[])
{
  printf(" buying date:%d\tbuying rate:%d\n selling date:%d\tselling rate:%d\n\n\ncurrent capital:%f\n",T[n].bday,B[T[n].bday],n,S[n],c[n-1]);
  int j=T[n].bday-1;
  if(n>0)print(T,j,c,B,S);
}


void multiTranc(int B[],int S[],int n,int C )
{
  prof *T ;
  float *P ,*c;
  c=(float*)malloc((n+1)*sizeof(float));
  T=(prof*)malloc((n+1)*sizeof (prof));
  P=(float *)malloc((n+1)*sizeof (float));
  int i,j;
  T[0].value=(C/B[0])*(S[0]-B[0]);
  T[0].bday=0;
  T[0].sday=0;
  P[0]=T[0].value;
  c[0]=C;
  c[1]=C+T[0].value;
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=i;j++)
        { 	
	  if((S[i]-B[j+1])<=0)continue;
	  c[j+1]= c[j]+P[j];
	  P[j]=T[j].value+(c[j+1]/B[j+1])*(S[i]-B[j+1]);
	}
      T[i].value=max( P,i );
      for(j=0;j<=i;j++)
        {
	  if(T[i].value==P[j])
	    {
	      T[i].bday=j+1;
	    }
        }

    }
  printf("initial capital: %d\nOptimal profite: %f\n",C,T[n].value);
  print(T,n,c,B,S);
}
*/

int main(int argc, char const *argv[])
{
	int n,c;
	scanf("%d",&n);
	printf("n-%d\n",n );
	int* B=(int*)malloc(n*sizeof(int));
	int* S=(int*)malloc(n*sizeof(int));
	printf("Buying rates-\t");
	for (int i = 0; i < n; ++i){scanf("%d",&B[i]);printf("%d\t",B[i] );}
	printf("\nSelling rates-\t");
	for (int i = 0; i < n; ++i){scanf("%d",&S[i]);printf("%d\t",S[i] );}
	scanf("%d",&c);
	printf("\nC-%d\n",c);
	singleTranc1(B,S,n,c);
	multiTranc(B,S,n,c);
		return 0;
}