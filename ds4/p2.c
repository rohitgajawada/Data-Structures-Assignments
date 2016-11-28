#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 1000000007
typedef struct Node
{
  int val;
  long long int wt;
  struct Node* next;
} Node;
typedef struct hnode
{
  int val;
  long long int length;
} hnode;

Node* insert(Node* a, int b, long long int w)
{
  Node* temp=(Node *)malloc(sizeof(Node));
  temp->val=b;
  temp->wt=w;
  temp->next=a;
  return temp;
}
void hinsert(hnode *heap,int n,int hval,long long int hlength)
{
  heap[n-1].val=hval;
  heap[n-1].length=hlength;
  int i=n-1,paren;
  hnode temp;
  while(i>0)
    {
      paren=(i-1)/2;
      if(heap[paren].length > heap[i].length)
	{
	  temp=heap[paren]; heap[paren]=heap[i]; heap[i]=temp;
	  i=paren;
	}
      else
	break;	
    }
}  
void heapify(hnode* heap,int i, int n)
{
  hnode temp;
  int child1=2*i+1;
  int child2=2*i+2;
  int child;
  if(heap[child1].length > heap[child2].length)
    child=child2;
  else
    child=child1;
  
  if(child<n && heap[i].length>heap[child].length)
    {
      temp=heap[i]; heap[i]=heap[child]; heap[child]=temp;
      heapify(heap,child,n);
    }
}
hnode delete(hnode* heap,int n)
{
  hnode top;
  top=heap[0];
  heap[0]=heap[n-1];
  heapify(heap,0,n-1);
  return top;
}

hnode heap[1000005];
int state[1000005]={0};

long long int spantree(Node** list,int n)
{
  long long int curr,currwt,i,count=0;
  hnode current;
  long long int ans=0;
  for(i=0;i<n+1;i++)
    {
      state[i]=0;
    }
  int tempn=0;
	
  state[1]=1;
  Node *q1=list[1];
  while(q1!=NULL)
    {
      hinsert(heap, ++tempn, q1->val, q1->wt);
      q1=q1->next;
    }
  while(1)
    {
      if(count==n-1)
	return ans;
      current=delete(heap,tempn--);
      curr=current.val;
      currwt=current.length;
      if(state[curr] == 1)
	continue;
      else
	{
	  state[curr]=1;
	  count++;
	  ans+=currwt;

	  Node* q=list[curr];
	  while(q!=NULL)
	    {
	      long long int k=q->val;
	      if(state[k]==0)
		{	      
		  hinsert(heap, ++tempn, k, q->wt);
		}
	      q=q->next;
	    }
	}
    }
}

Node* list[1000005];
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      int n,m,i,j,a,b;
      long long int w,ans,total=0;
      scanf("%d %d",&n,&m);
      Node *temp1=NULL,*temp2=NULL;
      for(i=0;i<100005;i++)
	list[i]=NULL;
      for(i=0;i<m;i++)
	{
	  scanf("%d %d %lld",&a,&b,&w);
	  total+=w;
	  list[a]=insert(list[a],b,w);
	  list[b]=insert(list[b],a,w);
	}
      ans=spantree(list,n);
      printf("%lld\n",total-ans);
    }
  return 0;
}
