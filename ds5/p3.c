#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000007
typedef struct Node
{
  int val;
  struct Node* next;
} Node;

Node* insert(Node* a, int b)
{
  Node* temp;
  temp=(Node *)malloc(sizeof(Node));
  temp->val=b;
  temp->next=a;
  return temp;
}

Node* list[500005];
long long int ans,wt[500005];
long long int min,par[500005];
int state[500005];

void mindfs(Node** list,int v,int *state)
{
  int tmin;
  state[v]=1;
  Node* ptr=list[v];
  
  while(ptr!=NULL)
    {
      int z=ptr->val;
      if(state[z]==0)
	{
	  par[z]=v;
	  mindfs(list,z,state);
	  if(wt[z]<min)
	    min=wt[z];
	} 
      ptr=ptr->next;
    }
  state[v]=0;
}	  

int main()
{		      
  int n,i,j,k,a,b,q;
  par[1]=-1;
  scanf("%d%d",&n,&q);
  for(i=0;i<=n+1;i++)
    list[i]=NULL;

  for(i=0;i<n-1;i++)
    {
      scanf("%d%d",&a,&b);
      list[a]=insert(list[a],b);
      list[b]=insert(list[b],a);
    }
  for(i=1;i<=n;i++)
    scanf("%lld",&wt[i]);

  for(k=0;k<=n+1;k++)
    state[k]=0;
  
  mindfs(list,1,state);
  
  for(i=0;i<q;i++)
    {
      int q;
      scanf("%d",&q);
      if(q==0)
	{
	  int x;
	  long long int v;
	  scanf("%d%lld",&x,&v);
	  if(wt[x]>v)
	    {
	      wt[x]=v;
	    }
	}
      else
	{
	  int v;
	  scanf("%d",&v);
	  min=wt[v];
	  state[par[v]]=1;
	  mindfs(list,v,state);
	  state[par[v]]=0;
	  printf("%lld\n",min);
	}
    }
  return 0;
}
		    
	    
 
