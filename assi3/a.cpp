#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
struct NODE;
struct TREE;

typedef struct NODE
{
  struct NODE* l;
  struct NODE* r;
  struct NODE* p;
  int key;
}node;
typedef struct TREE
{
  node *root;
  int m,n;	
}tree;
void insert(tree *T,int k,int *n,int *m);
void balence(node * );
node* create_node(int x)
{
  node *A=(node*)malloc(sizeof(node));
  A->l=NULL;
  A->r=NULL;
  A->p=NULL;
  A->key=x;
  return A;
}

//node* T=create_node();
tree* create_tree()
{
  tree* T=(tree*)malloc(sizeof(tree));
  T->m=0;
  T->n=0;
  T->root=create_node(0);
  return T;
}
/*void copy(node* A,node *N){
  A->l=N->l;
  A->r=N->r;
  A->p=N->p;
  A->key=N->key;
  if((N->p)->l==N)(A->p)->l=A;
  else (A->p)->r=A;
  printf("&&&\n");
}*/
int size(node *k)
{
  if(k==NULL)return 1;
  return size(k->l)+size(k->r);
}
int height(node *k){
  if(k==NULL)return -1;
  if(height(k->l)>height(k->r))return height(k->l)+1;else return height(k->r)+1;
}
void inorder(node *k)
{
  if(k==NULL)return;
  inorder(k->l);
  printf("%d  ",k->key);
  inorder(k->r);
}
void inorder_store(node* k,int* A,int *i){
 // printf("\n");
  if(k==NULL)return;
  else
  {
  inorder_store(k->l,A,i);
  A[(*i)]=k->key;
  (*i)++;
  inorder_store(k->r,A,i);
  return;
  }
}


void destroy(node* v)
{
  if(v==NULL)return;
  destroy(v->l);
  destroy(v->r);
  free(v);
}
node* build(tree* T,int *A,int *l,int n,int m)
{
  int i;  
  for(i=0;i<(*l);i++){
    insert(T,A[i],&n,&m);
  }

  /*if(i>=0&&i<s){
    node* N=create_node(A[i]);
    node* Nl=create_node(A[--i]);
    node* Nr=create_node(A[++i]);
    N->l=Nl;
    N->r=Nr;
    (N->l)->p=N;
    (N->r)->p=N;
    N->l=build(A,s,--i);
    N->r=build(A,s,++i);
    return N;
  }*/
  return T->root;
}
node* rebuild(node *v,int s){
  int *A=(int*)malloc(s*sizeof(int));
  int i=0;
  inorder_store(v,A,&i);
  /*for (int l = 0; l < s; ++l)
  {
        printf("A[%d]=%d\n",i,A[l]);
  }*/
  destroy(v);
  tree* T=create_tree();
  T->m=s;
  T->n=0;
  (T->root)->key=A[i/2];
  T->root=build(T,A,&i,0,s);
  printf("[R %d]",s);
  return T->root;
}
node* search(node* N,int x){
  if(N==NULL) return NULL;
  if(N->key==x)return N;
  if(search(N->l,x)!=NULL||search(N->r,x)!=NULL)
    {
      //printf("***%d\t",x);
      if(search(N->l,x)!=NULL)return search(N->l,x);
      else if(search(N->r,x)!=NULL) search(N->r,x);
    }
    else return NULL;
}
void insert_x(node* T,int x,int *n,int *m,int *i){
(*i)++;
if(x<T->key)
  {
    if(T->l==NULL)
      {
        node* N=create_node(x);
        T->l=N;
        N->p=T;
     }
        else
        insert_x(T->l,x,n,m,i);
  }
if(x>T->key)
  {
  if(T->r==NULL)
   {
    node* N=create_node(x);
    T->r=N;
    N->p=T;
   }
   else
   insert_x(T->r,x,n,m,i);
  }
}
void balence(node* N)
{
  node* A=create_node(N->key);
  A=N;
  if(A->p==NULL)return;
  printf("+++++++\n");
  int m=(2/3)*size(A);
  if(size(A->l)>m||size(A->r)>m){N=rebuild(A,size(A));}
  balence(N->p);
 // balence(N->r);
}
void insert(tree* T,int x,int *n,int *m){
  if(search(T->root,x)) return;
  (*n)++;
  int i=0;
  if((T->root)->l==NULL&&(T->root)->l==NULL&&(T->root)->key==0&& x!=0)(T->root)->key=x;   
  else if(x<=(T->root)->key)
    {
      if((T->root)->l)insert_x((T->root)->l,x,n,m,&i);
      else
      {
        node* N=create_node(x);
        (T->root)->l=N;
        N->p=T->root;
        insert_x((T->root)->l,x,n,m,&i);
      }
    }
  else {
    if((T->root)->r)insert_x((T->root)->r,x,n,m,&i);
    else 
    {
      node* N=create_node(x);
        (T->root)->r=N;
        N->p=T->root;
        insert_x((T->root)->r,x,n,m,&i);
      }
    } 
  int k=(1+(log(size(T->root))/log(3/2)));
  if(i>k+1)balence(T->root);
    if((*n)>(*m))(*m)++;
}
node* find_min(node* N){
  if(N->l==NULL) return N;
  else return find_min(N->l);
}

void Delete(node* N)
{
  if(N->l==NULL&&N->r==NULL)
    {
      if(N==(N->p)->r)(N->p)->r=NULL;
      else if(N==(N->p)->l)(N->p)->l=NULL;
      free(N);
    }
  else if(N->r!=NULL&&N->l==NULL)
    {
      /*node* W=create_node();
      W=N;
      if(N==(N->p)->r){printf("++++++++++++++++2\n");(W->p)->r=W;}
      else if(N==(N->p)->l){(W->p)->l=W;}*/
      if(N==(N->p)->r)
      {
        (N->p)->r=N->r;
        (N->r)->p=N->p;
      }
      else
      {
       (N->p)->l=N->r;
        (N->r)->p=N->p; 
      }
      free(N);
    }
  else if(N->l!=NULL&&N->r==NULL)
    {
      /*node* W=create_node();
      W=N->l;
      if(N==(N->p)->r)(W->p)->r=W;
      else if(N==(N->p)->l)(W->p)->l=W;
      */
      if(N==(N->p)->l)
      {
        (N->p)->l=N->l;
        (N->l)->p=N->p;
      }
      else
      {
      (N->p)->r=N->l;
      (N->l)->p=N->p; 
      }
      free(N);
    }
  else if(N->l!=NULL&&N->r!=NULL)
    {
      node* W=create_node(0);
      W=find_min(N->r);
      N->key=W->key;
      Delete(W);
    }
}
void deleteKey(tree* T,int x,int *n,int *m) {
  if(search(T->root,x))
    {	
      (*n)--;
      if((T->root)->key==x)(T->root)->key=0;
      else Delete(search(T->root,x));
      //printf("n=%d,m=%d\n",*n,*m);
      if((*n)>(int)((2*(*m))/3)+1)
       T->root=rebuild(T->root,size(T->root));
    }
    else
    return;
}

int main(int argc, char const *argv[])
{
  tree* T=create_tree();
  int i,nsml,k;
  int n=0,m=0;
  scanf("%d",&nsml);
  T->m=nsml;
  printf("nsml-%d\n",nsml );
  for(i=0;i<nsml;i++){
    scanf("%d",&k);
    printf("\n+++insert(%d):\t",k);
    insert(T,k,&n,&m);
    printf("height-%d\t",height(T->root));
   inorder(T->root);
  }
  scanf("%d",&nsml);
  printf("\nnsml for Delete-%d\n",nsml );
  for(i=0;i<nsml;i++){
    scanf("%d",&k);
    printf("\n+++Delete(%d):\t",k);
    printf("height-%d\t",height(T->root));
    deleteKey(T,k,&n,&m);
    inorder(T->root);
  }

  return 0;
}
