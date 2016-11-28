#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000007
typedef struct Node
{
  long long int val;
  struct Node* next;
} Node;

Node* list[200005];
long long int state[200005];
long long int height[200005];
long long int val[200005];

Node* insert(Node* a, long long int b)
{
  Node* temp=(Node *)malloc(sizeof(Node));
  temp->val=b;
  temp->next=a;
  return temp;
}
long long int pleasure(long long int v, Node **list)
{
  long long int sum,min=MAX,max=0;
  if(list[v]==NULL)
    return val[v];

  Node* q=list[v];
  while(q!=NULL)
    {
      if(height[v]%2==0)
	{
	  sum=pleasure(q->val, list);
	  if(sum>max)
	    max=sum;
	}
      else
	{
	  sum=pleasure(q->val, list);
	  if(sum<min)
	    min=sum;
	}
      q=q->next;
    }
  if(height[v]%2==0)
    return max;
  else
    return min;
}    	  
  
void got(long long int v, Node** list, long long int* state, long long int h)
{
  state[v]=1;
  height[v]=h;
  Node* ptr=list[v];
  while(ptr!=NULL)
    {
      long long int z=ptr->val;
      if(state[z]==0)
	got(z,list,state,h+1);
      ptr=ptr->next;
    } 
}
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      long long int n,m,i,j,a,b,w,ans;
      scanf("%lld",&n);
      for(i=0;i<=n;i++)
	{
	  state[i]=0;
	  height[i]=0;
	  list[i]=NULL;
	}
      for(i=1;i<n;i++)
	{
	  scanf("%lld%lld",&a,&b);
	  list[a]=insert(list[a],b);
	}
      for(i=1;i<=n;i++)
	scanf("%lld",&val[i]);
      got(1,list,state,0);
      ans=pleasure(1,list);
      printf("%lld\n",ans);
    }
  return 0;
}

