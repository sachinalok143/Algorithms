#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N_DFLT 8
#define B_DFLT 2000
#define MIN_VAL 10
#define MAX_VAL 15
#define INFINITY 1000000000


typedef  struct 
{
	int w,a,id;
}node;
node b[100];
void merging( node *obj,int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if((float)obj[l1].w/obj[l1].a <=(float)obj[l2].w/ obj[l2].a)
         b[i] = obj[l1++];
      else
         b[i] = obj[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = obj[l1++];

   while(l2 <= high)   
      b[i++] = obj[l2++];

   for(i = low; i <= high; i++)
      obj[i] = b[i];
}

void sort(node* obj,int low, int high) {
   int mid;
   if(low < high) {
      mid = (low + high) / 2;
      sort(obj,low, mid);
      sort(obj,mid+1, high);
      merging(obj,low, mid, high);
   } else { 
      return;
   }   
}

/*void knapshak(node* obj,int W,int n)
{
	int *l=(int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		l[i]=0;
	}
	int  j, k=0;
	for (int i = 0; i < n; ++i)
	{
		for (j = 0; j <99999999 ; ++j)
		{
			if(W<obj[i].w*j)break;
		}
		W=W-obj[i].w*(j-1);
		k=obj[i].a*(j-1);
		l[obj[i].id]=j-1;
		if(W<obj[i+1].w)break;
	}
	printf("max value=%d\n",k );
	for (int i = 0; i < n; ++i)
	{
	printf("%d\t",l[i] );
	}
	printf("\n");

}*/


void printcounts (node *obj, int **CNT, int a, int i)
{
   if (i < 0) return;
   printcounts(obj,CNT,a-CNT[i][a]*obj[i].a,i-1);
   printf("%3d ", CNT[i][a]);
}

void knapshak(node * obj,int W,int n)
{

	int C, cost, i, j, k, weight;
   int **T, **CNT;
   double max, cperw;

   printf("\n+++ Method 1\n");
   /* In this method, we need a bound on the cost. Locate the object with
      the maximum cost/weight ratio. Fill the knapsack with objects of this
      type. */
   max = (double)obj[0].a / (double)obj[0].w; j = 0;
   ///printf("max=%f,j=%d\n",(double)obj[0].w/(double)obj[0].a,j );
   for (i=1; i<n; ++i) {
      cperw = (double)obj[i].a / (double)obj[i].w;
     /// printf("cperw =%f\n",cperw  );
      if (cperw > max) {
         max = cperw; j = i;
      }
   }
   C = 0.5 + (double)obj[j].a * (double)W / (double)obj[j].w;
   printf("C:%d\n",C );
   T = (int **)malloc(n * sizeof(int *));
   CNT = (int **)malloc(n * sizeof(int *));
   for (i=0; i<n; ++i) {
      T[i] = (int *)malloc((C+1) * sizeof(int));
      CNT[i] = (int *)malloc((C+1) * sizeof(int));
      for (j=0; j<=C; ++j) {
         T[i][j] = INFINITY;
         CNT[i][j] = 0;
      }
   }
   j = 0; cost = 0;
   while ((cost <= C) && (j * obj[0].w <= W) ){
      T[0][cost] = j * obj[0].w;
      CNT[obj[0].id][cost] = j;
      ++j; cost += obj[0].a;
   }
   for (i=1; i<n; ++i) {
      for (j=0; j<=C; ++j) {
         cost = j; weight = T[i-1][j]; k = 0;
         while ((weight <= W) && (cost <= C)) {
            if (weight < T[i][cost]) {
               T[i][cost] = weight;
               CNT[obj[i].id][cost] = k;
            }
            weight += obj[i].w; cost += obj[i].a; ++k;
         }
      }
   }
   cost = C;
   printf("cost=%d\n",cost );
   //printf("max=%f,j=%d\n",(double)obj[0].w/(double)obj[0].a,j );
   while (T[n-1][cost] ==1000000000){--cost;}
   printf("    Maximum cost = %d\n    Weight = %d\n", cost, T[n-1][cost]);
   printf("    Counts  : "); printcounts(obj,CNT,cost,n-1);
   printf("\n");
}


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int W;
	scanf("%d",&W);
	node *obj=(node*)malloc(n*sizeof(node));

	for (int i = 0; i < n; ++i)
	{
			scanf("%d",&obj[i].w);
			//printf("%d\n",obj[i].w );
	}
	for (int i = 0; i < n; ++i)
	{
			scanf("%d",&obj[i].a);
			//printf("%d\n",obj[i].a );
			obj[i].id=i;
	}
sort(obj,W,n);
/*printf(" id\tweight\tcost\n");

for (int i = 0; i < n; ++i)
{
	printf("%d.\t%d\t%d\n",obj[i].id,obj[i].w,obj[i].a );
}
*/
knapshak(obj,W,n);

	return 0;
}