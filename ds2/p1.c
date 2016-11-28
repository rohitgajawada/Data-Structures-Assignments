#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int state[100005];
typedef struct Node
{
  long long int val;
  struct Node* next;
} Node;
typedef struct stacks
{
  Node* headnode;
} stack;

void push(stack* stack1,long long int item)
{
  Node* temp=(Node *)malloc(sizeof(Node));
  temp->val=item;
  temp->next=stack1->headnode;
  stack1->headnode=temp;
}
long long int pop(stack* stack1)
{
  Node* temp=stack1->headnode;
  long long int data=temp->val;
  stack1->headnode=temp->next;
  free(temp);
  return data;
}
Node* insert(Node* a, Node* temp)
{
  Node* ptr;
  ptr=a;
  if(ptr==NULL)
    {
      a=temp;
      temp->next=NULL;
    }
  else
    {
      while(ptr->next!=NULL)
	{
	  ptr=ptr->next;
	}
      ptr->next=temp;
      temp->next=NULL;
    }
  return a;
}
void dfs(long long int v,stack* stack1,Node **list)
{
  long long int i,x;
  push(stack1,v);
  while(stack1->headnode!=NULL)
    {
      v=pop(stack1);
      if(state[v]==0)
	{
	  state[v]=1;
	}
      Node* ptr=list[v];
      while(ptr!=NULL)
	{
	  x=ptr->val;
	  if(state[x]==0)
	    {
	      push(stack1,x);
	    }
	  ptr=ptr->next;
	}
    }
}
  
int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
    {
      long long int flag=1;
      long long int n,m,i,j,a,b;
      memset(state,0,sizeof(long long int)*100005);
      Node* list[100005];
      Node* temp1=NULL;
      long long int visit[100005]={0};
      long long int indegree[100005]={0};
      long long int outdegree[100005]={0};
      stack* stack1=(stack *)malloc(sizeof(stack));
      stack1->headnode=NULL;
      
      scanf("%lld%lld",&n,&m);
      for(i=0;i<=n;i++)
	list[i]=NULL;
      
      for(i=0;i<m;i++)
	{
	  scanf("%lld%lld",&a,&b);
	  temp1=(Node *)malloc(sizeof(Node));
	  temp1->val=b;
	  list[a]=insert(list[a],temp1);
	  outdegree[a]++;
	  indegree[b]++;
	}
      dfs(1,stack1,list);
      for(i=1;i<=n;i++)
	{
	  if(state[i]==0)
	    {
	      if((indegree[i]!=0 && outdegree[i]!=0) || (i==n || i==1))
		{
		  flag=0;
		  break;
		}
	    }
	  if(indegree[i]!=outdegree[i])
	    {
	      flag=0;
	      break;
	    }
	}
      if(flag==1)
	printf("Yes\n");
      else if(flag==0)
	printf("No\n");
      -+
      for(i=1;i<=n;i++)
	free(list[i]);
      free(stack1);
    }
  return 0;
}
