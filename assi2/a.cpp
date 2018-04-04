#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
typedef struct NODE
{
	NODE* L;
	NODE* R;
	bool EOS;
}node;
/*typedef struct  TREE
{
node* root;	
}Tree;*/
node * create_node(bool eos){
	node *N=(node*)malloc(sizeof(node*));
	N->EOS=eos;
	N->L=NULL;
	N->R=NULL;
	return N;
}
node* create_tree()
{
	node *root=create_node(false);

	/*root->L=NULL;
	root->R=NULL;*/
	return root;
	//return create_node(false);
}
int bin(int a,int *p){
	int j=0;
	while(a!=0){
		p[j]=a%2;
		a=a/2;
		j++;
	}
	return j;
}
void printBin(int *p,int j){
	int i;
	for(i=j-1;i>=0;i--)printf("%d",p[i]);
}


void delete_node(node* T,node* parent){
if(T==NULL)return;
if(parent!=NULL){
	parent->L=NULL;
	parent->R=NULL;
}
if(T->L==NULL&&T->R==NULL&&T->EOS==false)//free(T);
if(T->L!=NULL)delete_node(T->L,T);
if(T->R!=NULL)delete_node(T->R,T);

}


void printTree(node * T,int a,int k){
if(T==NULL)return;
int i;
if(T->L!=NULL){printTree(T->L,2*a,++k);}
if(T->R!=NULL){printTree(T->R,(2*a)+1,++k);}
if(T->EOS==true)
{

	int p[10];
	int j=bin(a,p);
	printBin(p,j);
	//printf("{%d}",a );
	printf("\t");
}
}
void Delete(node *T,int a){
	int p[10];
	int i, j=bin(a,p);
	for(i=j-2;i>=0;i--){
		if(p[i]==0){
			if(T->L==NULL)return;
			T=T->L;
		}
		if(p[i]==1){
			if(T->R==NULL)return;
			T=T->R;	
			}
		if(i==0)if(T->EOS)T->EOS=false;else printf(" %d is NOT AVAILABLE\t",a);
	}
//delete_node(T,NULL);
}
void printInts(node *T,int a,int o){
if(T==NULL)return;
	if(T->EOS){
		printf("%d\t",a);
		
	}
printInts(T->L,2*a,++o);
printInts(T->R,2*a+1,++o);
}
node* insert(node *Root,int a){
	int i,p[10];
	int j=bin(a,p);
	node *T=create_node(false);
	T=Root;
	for(i=j-2;i>=0;i--){
		if(p[i]==0){
	        node* k=create_node(false);
			if(T->L==NULL)T->L=k;
			T=T->L;
		}
		if(p[i]==1){	
			node* k=create_node(false);
			if(T->R==NULL)T->R=k;
			T=T->R;	
			}
	if(i==0)T->EOS=true;
	}
	/*while(T)
		{if(T->EOS)printf("%d///\n",a );T=T->L;}
	while(T)
		{if(T->EOS)printf("%d/////////\n",a );T=T->R;}*/
return Root;
}
int main()
{	int p[10],j;
	node *T=create_tree();
	node *X=create_tree();
	X->R=T;
	int n,i,h;
	scanf("%d",&n);
	printf("\nnins= %d\n",n );
	node *k=create_node(false);
	printf("Insert:\t");
	for(i=0;i<n;i++){
	scanf("%d",&h);
	printf("%d\t",h);
	k=insert(T,h);
	j=bin(h,p);
	/*printf("\ninsert(");
	printBin(p,j);
	printf(")\t");*/
	}
	//printTree(X,0,-1);
	
	printf("\nafter Inserting:\n");
	printTree(T,0,-1);

	//printInts(T,0,-1);
	scanf("%d",&n);
	printf("\nndel = %d\n",n );
	printf("Delete: ");
	for(i=0;i<n;i++){
	scanf("%d",&h);
	printf("%d\t",h);
	Delete(T,h);
	/*printf("\ndeleting(%d):",h );
	printTree(T,0,-1);*/
	}
	printf("\nAfter Deletion:\t");
	printTree(T,0,-1);
	delete_node(T,NULL);
	printf("\nOld tree deleted:\n");
	//node *U=create_tree();
	scanf("%d",&n);
	for(i=0;i<n;i++){
	scanf("%d",&h);
	k=insert(T,h);
	printf("\ninserting(%d)\t",h);
	X->R=T;
	printInts(X,0,0);
	}
	printf("\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	scanf("%d",&h);
	Delete(T,h);
	printf("\ndeleting(%d)\t",h);
	X->R=T;
	printInts(X,0,0);
	}
return 0;
}