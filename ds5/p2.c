#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int sum=0;
long long int kans=0;
typedef struct node
{
  long long int val;
  long long int height;
  long long int ls;
  long long int rs;
  struct node* left;
  struct node* right;
} node;
node* rightrot(node* root);
node* leftrot(node* root);
void inorder(node* root)
{
  if(root==NULL)
    return;
  printf("%lld height: %lld  ls:%lld  rs:%lld\n",root->val,root->height,root->ls,root->rs);
  inorder(root->left);
  inorder(root->right);
}
long long int search(node* root,long long int data)
{
  if(root==NULL)
    return 0;
  else if(root->val==data)
    return 1;
  else if(data < root->val)
    return search(root->left, data);
  else if(data > root->val)
    return search(root->right, data);
} 
node* getminner(node* temp)
{
  node* ptr=temp;
  while (ptr->left!=NULL)
    ptr=ptr->left;
  return ptr;
}
long long int balancer(struct node* x)
{
  if(x == NULL)
    return 0;
  long long int a=0,b=0;
  if(x->left!=NULL)
    a=(x->left)->height;
  if(x->right!=NULL)
    b=(x->right)->height;
  return (a-b);
}
node* delete(node* root,long long int data)
{
  if(root==NULL)
    return root;
  if(data < root->val)
    {
      (root->ls)--;
      root->left=delete(root->left,data);
    }      
  else if(data > root->val)
    {
      (root->rs)--;
      root->right=delete(root->right,data);
    }
  else
    {
      if((root->left == NULL) || (root->right == NULL))
        {
	  node *temp = root->left ? root->left : root->right;
	  if(temp==NULL)
            {
	      temp=root;
	      root=NULL;
            }
	  else
	    {
	      root->val=temp->val;
	      root->height=temp->height;
	      root->ls=temp->ls;
	      root->rs=temp->rs;
	      
	      root->left=temp->left;
	      root->right=temp->right;
	    }	  
	  free(temp);
        }
      else
        {
	  struct node* temp=getminner(root->right);
	  root->val=temp->val;
	  root->right=delete(root->right,temp->val);
        }
    }
  if(root==NULL)
    return root;
  long long int lh=0,rh=0;
  node *p=root->left;
  node *q=root->right;
  if(p!=NULL)
    lh=p->height;
  if(q!=NULL)
    rh=q->height;
  long long int balance = lh - rh;  
  if (balance > 1 && balancer(root->left) >= 0)
    return rightrot(root);
  else if(balance > 1 && balancer(root->left) < 0)
    {
      root->left =  leftrot(root->left);
      return rightrot(root);
    }
  else if(balance < -1 && balancer(root->right) <= 0)
    return leftrot(root);
  else if(balance < -1 && balancer(root->right) > 0)
    {
      root->right = rightrot(root->right);
      return leftrot(root);
    }
  else
    {
      if(lh>rh)
	root->height=lh+1;
      else
	root->height=rh+1;
    }
  return root;
}

node* insert(node* root,long long int data)
{
  if(root==NULL)
    {
      node* temp=(node *)malloc(sizeof(node));
      temp->val=data;
      temp->left=NULL;
      temp->right=NULL;
      temp->ls=0;
      temp->rs=0;
      temp->height=1;
      return temp;
    }
  if(data < root->val)
    {
      (root->ls)++;
      root->left=insert(root->left,data);
    }
  else 
    {
      (root->rs)++;
      root->right=insert(root->right,data);
    }
  long long int lh=0,rh=0;
  node *p=root->left;
  node* q=root->right;
  if(p!=NULL)
    lh=p->height;
  if(q!=NULL)
    rh=q->height;
  long long int bal=lh-rh;
  if (bal > 1 && data < root->left->val)
    return rightrot(root); 
  else if(bal < -1 && data > root->right->val)
    return leftrot(root); 
  else if(bal > 1 && data > root->left->val)
    {
      root->left =  leftrot(root->left);
      return rightrot(root);
    } 
  else if(bal < -1 && data < root->right->val)
    {
      root->right = rightrot(root->right);
      return leftrot(root);
    }
  else
    {
      if(lh>rh)
	root->height=lh+1;
      else
	root->height=rh+1;
    }  
  return root;
}

long long int max(long long int a, long long int b)
{
  return (a > b)? a : b;
}

node* rightrot(node* y)
{
  if(y==NULL)
    return y;
  struct node *x = y->left;
  struct node *T2 = x->right;
  if(T2!=NULL)
    y->ls = T2->ls + T2->rs + 1;
  else
    y->ls=0;
  if(x!=NULL)
    x->rs = y->ls + y->rs + 1;
  
  x->right = y;
  y->left = T2;
  
  long long int a=0,b=0,c=0,d=0;
  if(y->left!=NULL)
    a=(y->left)->height;
  if(y->right!=NULL)
    b=(y->right)->height;

  y->height = max(a,b)+1;
  
  if(x->left!=NULL)
    c=(x->left)->height;
  if(x->right!=NULL)
    d=(x->right)->height;

  x->height = max(c,d)+1;

  return x;
}
node* leftrot(node* x )
{
  if(x==NULL)
    return x;
  struct node *y = x->right;
  struct node *T2 = y->left;

  if(T2!=NULL)
    x->rs = T2->ls + T2->rs +1;
  else
    x->rs=0;
  if(y!=NULL)
  y->ls = x->rs + x->ls +1;

  y->left = x;
  x->right = T2;

  long long int a=0,b=0,c=0,d=0;
  if(x->left!=NULL)
    a=(x->left)->height;
  if(x->right!=NULL)
    b=(x->right)->height;

  x->height = max(a,b)+1;
  
  if(y->left!=NULL)
    c=(y->left)->height;
  if(y->right!=NULL)
    d=(y->right)->height;
  
  y->height = max(c,d)+1;

  return y;
} 
void counter(node* root, long long int x)
{
  if(root==NULL)
    return;
  if(x==root->val)
    {
      sum+=root->ls;
      return;
    }
  else if(x < root->val)
    counter(root->left, x);
  else if(x > root->val)
    {
      sum+=root->ls +1;
      counter(root->right, x);
    }
}

void ksmall(node* root, long long int x)
{
  if(root==NULL)
    return;
  if(x==root->ls+1)
    {
      kans=root->val;
      return;
    }
  else if(x < root->ls + 1)
    ksmall(root->left, x);
  else if(x > root->ls + 1)
    ksmall(root->right, x - root->ls - 1);
}

int main()
{
  long long int n;
  scanf("%lld",&n);
  node *root=NULL;
  while(n--)
    {
      char op;
      sum=0,kans=0;
      long long int x;
      getchar();
      scanf("%c %lld",&op,&x);
      //if(op == 'P')
      //inorder(root);
      if(op=='I')
	{
	  if(search(root,x)==0)
	    root=insert(root,x);
	  //inorder(root);
	}
      else if(op=='D')
	{
	  if(search(root,x)==1)
	    root=delete(root,x);
	  //inorder(root);
	}
      else if(op=='K')
	{
	  if(root==NULL)
	    printf("invalid\n");
	  else if(x==0)
	    printf("0\n");
	  else if(x > root->ls + root->rs + 1)
	    printf("invalid\n");
	  else
	    {
	      ksmall(root,x);
	      printf("%lld\n",kans);
	      kans=0;
	    }
	}
      else if(op=='C')
	{
	  counter(root,x);
	  printf("%lld\n",sum);
	  sum=0;
	}
    }
  return 0;
}
