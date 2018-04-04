#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	char roll_no[9],Decision[2];
	int Smarks,Amarks,Rs,Ra;
}student;
int k,n;
void Arank(student *S,int j,int M,int R)
{
	if(R+j==n+1)return;
	int i,m=0,l;
	printf("j=%d,M=%d,R=%d\n",j,M,R );
	for(i=0;i<n;i++)
	{	
		if(S[i].Amarks==M)
		{
		S[i].Ra=R;
		j++;
		S[i].Amarks=-1;
		Arank(S,j,M,R);

		}
	}
	for(i=0;i<n;i++)
	{
		if(S[i].Amarks>=m && S[i].Amarks<M)
		{
			m=S[i].Amarks;
			l=i;
		}
	}
	if(S[l].Amarks>=m && S[l].Amarks<M){
	if(j==0){S[l].Ra=++R;S[l].Amarks=-1;}
  	else{
	R=R+j;
	j=1;
	S[l].Amarks=-1;
	S[l].Ra=R;
	}
Arank(S,j,m,R);
}
}

void Srank(student *S,int j,int M,int R)
{
	if(R+j==n+1)return;
	int i,m=0,l;
	printf("j=%d,M=%d,R=%d\n",j,M,R );
	for(i=0;i<n;i++)
	{	
		if(S[i].Smarks==M)
		{
		S[i].Rs=R;
		j++;
		S[i].Smarks=-1;
		Srank(S,j,M,R);

		}
	}
	for(i=0;i<n;i++)
	{
		if(S[i].Smarks>=m && S[i].Smarks<M)
		{
			m=S[i].Smarks;
			l=i;
		}
	}
	if(S[l].Smarks>=m && S[l].Smarks<M){
	if(j==0){S[l].Rs=++R;S[l].Smarks=-1;}
  	else{
	R=R+j;
	j=1;
	S[l].Smarks=-1;
	S[l].Rs=R;
	}
Srank(S,j,m,R);
}
}



void merging(int low, int mid, int high,student* S) {
   int l1, l2, i;
   student b[100];
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
    {
      if(k==1)
      {
      	if(S[l1].Smarks <= S[l2].Smarks)
         b[i] = S[l1++];
      else
         b[i] = S[l2++];
      }
      if(k==2)
      {
      	if(S[l1].Amarks <= S[l2].Amarks)
         b[i] = S[l1++];
      else
         b[i] = S[l2++];
      }
	}
   
   while(l1 <= mid)    
      b[i++] = S[l1++];

   while(l2 <= high)   
      b[i++] = S[l2++];

   for(i = low; i <= high; i++)
      S[i] = b[i];
}

void sort(int low, int high,student *S) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid,S);
      sort(mid+1, high,S);
      merging(low, mid, high,S);
   } else { 
      return;
   }   
}


void range(int sub,int a,int b,int n,student* Student)
{
student *S=(student*)malloc(n*sizeof(student*));
int i,j=0;
for(i=0;i<n;i++)
	{
		if(k==1)
		{
			if(Student[i].Smarks>=a&&Student[i].Smarks<=b)
			{
			S[j]=Student[i];
			j++;
			}
		}
		if(k==2)
		{
			if(Student[i].Amarks>=a&&Student[i].Amarks<=b)
			{
			S[j]=Student[i];
			j++;
			}
		}
	}
sort(0,j,S);

if(k==1)printf("+++Science:\ta-%d\tb-%d\n",a,b);
if(k==2)printf("+++Arts:\ta-%d\tb-%d\n",a,b);
printf("---List of student\n");
for(i=j;i>0;i--)
	printf("%s,\t%d,\t%d\n",S[i].roll_no,S[i].Smarks,S[i].Amarks );
}

int main()
{
student Student[100];
int t,i,a,b;
printf("enter no. of students:\n");
scanf("%d",&n);
printf("n-%d\n+++initial list",n);
printf("Enter the roll no.,science and arts marks:\n");
for(i=0;i<n;i++){
	scanf("%s%d%d",&(Student[i].roll_no),&Student[i].Amarks,&Student[i].Smarks);
	Student[i].Rs=0;
	Student[i].Ra=0;
	}
for(i=0;i<n;i++)
	{
	printf("%s,\t%d,\t%d\n",Student[i].roll_no,Student[i].Amarks,Student[i].Smarks );
	}

printf("Enter the sub(sub should be as 1 for science and 2 for Arts) and a,b:\n");
printf("+++interval search\n");
scanf("%d",&t);
while(t--)
	{
		scanf("%d%d%d",&k,&a,&b);
		range(k,a,b,n,Student);
	}
int A[100];
for (i = 0; i < n; ++i)A[i]=Student[i].Amarks;
Arank(Student,1,100,0);
for (i = 0; i < n; ++i)Student[i].Amarks=A[i];
for (i = 0; i < n; ++i)A[i]=Student[i].Smarks;
Srank(Student,1,101,0);
for (i = 0; i < n; ++i)Student[i].Smarks=A[i];
printf("\n-+++ Rank comparisons\n");
int x=0,y=0,z=0;
for (i = 0; i < n; ++i)
{
	if(Student[i].Rs>Student[i].Ra)
		{
			Student[i].Decision[0]='B';
			Student[i].Decision[1]='A';
			x++;
		}else{
	if(Student[i].Rs<Student[i].Ra)
		{
			Student[i].Decision[0]='B';
			Student[i].Decision[1]='S';
			y++;
		}
	else
		{
			Student[i].Decision[0]='S';
			Student[i].Decision[1]='C';
			z++;
		}
	}
	printf("%s ,\t%d,\t%d  ,Arts Rank-%d,\tScience Rank-%d ,\t Decision-%s \n",Student[i].roll_no,Student[i].Amarks,Student[i].Smarks, Student[i].Ra,Student[i].Rs,Student[i].Decision);
}
printf("No of BA-%d\nNo of BS-%d\nNo of SC-%d\n",x,y,z);
}