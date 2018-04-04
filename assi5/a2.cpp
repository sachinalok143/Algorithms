#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

char EMPTY[] ="EMPTY";


typedef struct {
	char x[21], y[21]; /* Pair of NULL-terminated strings */
} pair;


typedef struct node {
	char att[21]; /* The attribute name: a NULL-terminated string */
	int nassoc; /* Number of attribute associations */
	struct node *assoc[10]; /* Array of pointers to associated attributes */
	struct node *next; /* Next pointer for maintaining the linked list */
} node;

typedef struct {
	int S; /* Size of A and B */
	node **A, **B; /* Arrays of pointers to head lists of nodes */
}hashtable;

bool cmp_srt(char *a,char* b){
	if(strlen(a)!=strlen(b))return false;
	int i;
	int l= strlen(a);
	for (i= 0; i<l; i++)
		if(a[i]!=b[i])
			return false;
	return true;
}

int Hs(char *Z,int s,int i)
{
	if(i<0)return 0;
	else{
		i--;
		return (128*(Hs(Z,s,i))+(int)Z[i])% s;
	}
}

node* create_node()
{

	node* a=(node*)malloc(sizeof(node));
	strcpy(a->att,EMPTY);
	a->nassoc=0;
	a->assoc[10];
	for (int j = 0; j < 10; ++j)
	{
		a->assoc[j]=NULL;
	}
	a->next=NULL;
return a;
}



hashtable inittable(int s)
{
	hashtable* H=(hashtable*)malloc(sizeof(hashtable));
	H->S=s;
	node** a=(node**)malloc(s*sizeof(node*));
	node** b=(node**)malloc(s*sizeof(node*));
	for (int i = 0; i < s; ++i)
	{	
		a[i]=create_node();
		strcpy((a[i])->att,EMPTY);
		a[i]->nassoc=0;
		a[i]->assoc[10];//=(node**)malloc(10*sizeof(node*));
		for (int j = 0; j < 10; ++j)
		{
			a[i]->assoc[j]=NULL;
		}
		a[i]->next=NULL;
	}
	for (int i = 0; i < s; ++i)
	{	
		b[i]=create_node();
		strcpy((a[i])->att,EMPTY);
		b[i]->nassoc=0;
		b[i]->assoc[10];//=(node**)malloc(10*sizeof(node*));
		for (int j = 0; j < 10; ++j)
		{
			b[i]->assoc[j]=NULL;
		}
		b[i]->next=NULL;
	}
	H->A=a;
	H->B=b;
return *H;
}


hashtable insertpair(hashtable *T,pair *P)
{

	int i =Hs(P->x,T->S,strlen(P->x));
	int j =Hs(P->y,T->S,strlen(P->y));
	printf("Insertion at(%d,%d)",i,j );
	node* k=create_node();
	node* l=create_node();
	strcpy(l->att,P->y);
	strcpy(k->att,P->x);
	k->assoc[k->nassoc]=l;
	k->nassoc++;
	l->assoc[l->nassoc]=k;
	l->nassoc++;
	node* temp=create_node();
	temp=(T->A[i]);
	while(1){if(!temp->next||cmp_srt(P->x,(temp->next)->att))break;temp=temp->next;}
	node* temp1=create_node();
	temp1=(T->B[j]);
	while(1){if(!temp1->next||cmp_srt(P->y,(temp1->next)->att))break;temp1=temp1->next;}
	if(temp->next)
	{	if(temp1->next)
		(temp->next)->assoc[(temp->next)->nassoc]=temp1->next;
		else (temp->next)->assoc[(temp->next)->nassoc]=l;
		(temp->next)->nassoc++;
		//strcpy(P->x,(temp->next)->att);

	}
	else if(!temp1->next)temp->next=k;
	else {temp->next=k;k->assoc[k->nassoc]=temp1->next;}
	if(temp1->next)
	{
		if(temp->next)
		(temp1->next)->assoc[(temp1->next)->nassoc]=temp->next;
		else (temp->next)->assoc[(temp->next)->nassoc]=k;
		(temp1->next)->nassoc++;
		///strcpy(P->y,(temp1->next)->att);
	}
	else if(!temp->next)temp1->next=l;else{temp1->next=l;l->assoc[l->nassoc]=temp->next;} 

return *T;

} 


hashtable deletepair(hashtable *T,pair *P)
{

	int i =Hs(P->x,T->S,strlen(P->x));
	int j =Hs(P->y,T->S,strlen(P->y));
	printf("deletion at(%d,%d)\t",i,j );
	node* temp=create_node();
	node* prev=create_node();
	node* prev1=create_node();
	temp=(T->A[i])->next;
	node* temp1=create_node();
	temp1=(T->B[j])->next;	
	while(1){if(cmp_srt(P->x,temp->att)||!temp)break;prev=temp;temp=temp->next;}
	if(!temp)return *T;
	else
	{	int m=0;
		while(1)
			{
			if(!temp->assoc[m]||!temp1||m>=10)
			break;
			if (!temp1) return *T;
			if(cmp_srt(P->y,(temp->assoc[m])->att))
			{
				temp->assoc[temp->nassoc]=NULL;
				temp->nassoc--;
				temp1->assoc[temp1->nassoc]=NULL;
				temp1->nassoc--;
				while(1){if(cmp_srt(P->y,temp1->att)||!temp1)break;prev1=temp1;temp1=temp1->next;}
				if(temp->nassoc==0)
				{
					prev->next=temp->next;
					free(temp);
				}
				if (temp1->nassoc==0)
				{
					prev1->next=temp1->next;
					free(temp1);
				}

			}
			m++;
		}
	}
return *T;
}

void searchpair(hashtable *T,pair* P)
{
	bool N=false;
	int i =Hs(P->x,T->S,strlen(P->x));
	int j =Hs(P->y,T->S,strlen(P->y));
	node* temp=create_node();
	node* prev=create_node();
	node* prev1=create_node();
	temp=(T->A[i])->next;
	node* temp1=create_node();
	temp1=(T->B[j])->next;	
	while(!cmp_srt(P->x,temp->att)&&temp){prev=temp;temp=temp->next;}
	if(!temp)return ;
	else
	{	int m=0;
		while(temp->assoc[m]&&temp1&&m<10)
		{
			if (!temp1) return ;
			if(cmp_srt(P->y,(temp->assoc[m])->att))
			{
				
				N=true;

				/*temp->assoc[temp->nassoc]=NULL;
				temp->nassoc--;
				temp1->assoc[temp1->nassoc]=NULL;
				temp1->nassoc--;
				while(!cmp_srt(P->y,temp1->att)&&temp1){prev1=temp1;temp1=temp1->next;}
				if(temp->nassoc==0)
				{
					prev->next=temp->next;
					free(temp);
				}
				if (temp1->nassoc==0)
				{
					prev1->next=temp1->next;
					free(temp1);
				}*/

			}
			m++;
		}
	}
	if(N)printf("(%s,%s)found at(%d,%d)",P->x,P->y,i,j );
	else printf("(%s,%s)not found",P->x,P->y );
}

void searchattr(hashtable *T,char *z,int a)
{

	if(a==1)
	{
		printf("(%s,-) is associated with:\t",z);
		int i=Hs(z,T->S,strlen(z));
		node* temp=create_node();
		temp=(T->A[i])->next;
		while(1){if(temp==NULL||cmp_srt(z,temp->att))break;temp=temp->next;}
		//printf("****\n");
		if(!temp){return ;}
		else
		{	int m=0;
			while(temp->assoc[m]&&m<10)
			{
			printf("%s\t", (temp->assoc[m])->att);
			m++;
			}
		//	printf("\n");		
		} 
	}
	if(a==2)
	{
		printf("(-,%s) is associated with:\t",z);
		int i=Hs(z,T->S,strlen(z));
		node* temp1=create_node();
		temp1=(T->B[i])->next;
		while(1){if(temp1==NULL||cmp_srt(z,temp1->att))break;temp1=temp1->next;}
		if(!temp1)return ;
		else
		{	int m=0;
			while(temp1->assoc[m]&&m<10)
			{
			printf("%s\t", (temp1->assoc[m])->att);
			m++;
			}
		//	printf("\n");		
		} 
	}



}



int main()
{
	int s;
	scanf("%d",&s);
	hashtable T=inittable(s);
	int k;
	scanf("%d",&k);
	char z[21];
	char x[21],y[21];
	pair *P=(pair*)malloc(sizeof(pair));
	while(k)
		{
			switch(k)
				{
				case 1:
					scanf("%s",z);
					printf("\n+++Enter choice: 1  %s\n",z);
					searchattr(&T,z,1);
					break;
				case 2:
					scanf("%s",z);
					printf("\n+++Enter choice: 2  %s\n",z);
					searchattr(&T,z,2);
					break;
				case 3:
					scanf("%s%s",x,y);
					printf("\n+++Enter choice: 3  %s   %s\n",x,y);
					strcpy(P->x,x);
					strcpy(P->y,y);
					searchpair(&T,P);
					break;
				case 4:
					scanf("%s%s",x,y);
					printf("\n+++Enter choice: 4   %s   %s\n",x,y);
					strcpy(P->x,x);
					strcpy(P->y,y);
					insertpair(&T,P);
					break;
				case 5:
					scanf("%s%s",x,y);
					printf("\n+++Enter choice: 5  %s   %s\n",x,y);
					strcpy(P->x,x);
					strcpy(P->y,y);
					deletepair(&T,P);
					break;
				default:;

				}

			scanf("%d",&k);
		}
	return 0;
}