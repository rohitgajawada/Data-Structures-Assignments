#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000000007
typedef struct Node
{
  long long int val;
  struct Node* next;
} Node;
Node* insert(Node* a, Node* temp)
{
  if(a==NULL)
    {
      a=temp;
      temp->next=NULL;
      return a;
    }
  else
    {
      temp->next=a;
      return temp;
    }
}
long long int printdfs(long long int v,Node** list,long long int *state,long long int p,long long int* compcosts,long long int* cost)
{
  //printf("dfs of %lld\n",v);
  state[v]=1;
  Node* ptr=list[v];
  compcosts[p++]=cost[v];
  while(ptr!=NULL)
    {
      long long int x=ptr->val;
      while(ptr!=NULL)
	{
	  long long int z=ptr->val;
	  if(state[z]==0)
	    {
	      p=printdfs(z,list,state,p,compcosts,cost);
	    }
	  ptr=ptr->next;
	}
    }
  return p;
}
long long int dfs(long long int v,Node** list,long long int *state,long long int* tmp,long long int k)
{
  state[v]=1;
  Node* ptr=list[v];
  while(ptr!=NULL)
    {
      long long int z=ptr->val;
      if(state[z]==0)
	k=dfs(z,list,state,tmp,k);
      ptr=ptr->next;
    }
  tmp[k++]=v;
  return k;
}
int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
    {
      long long int n,m,i,j,a,b;
      long long int sort[100005];
      long long int tmp[100005];
      long long int cost[100005];
      scanf("%lld%lld",&n,&m);
      for(i=1;i<=n;i++)
	scanf("%lld",&cost[i]);
      Node* list1[100005]={NULL};
      Node* list2[100005]={NULL};
      long long int state1[100005]={0};
      long long int state2[100005]={0};
      Node* temp1=NULL;
      Node* temp2=NULL;
      for(i=0;i<m;i++)
	{
	  scanf("%lld%lld",&a,&b);
	  temp2=(Node *)malloc(sizeof(Node));
	  temp2->val=b;
	  list1[a]=insert(list1[a],temp2);
	  temp1=(Node *)malloc(sizeof(Node));
	  temp1->val=a;
	  list2[b]=insert(list2[b],temp1);
	}
      long long int k=0;
      for(i=1;i<=n;i++)
	{
	  if(state1[i]==0)
	    k=dfs(i,list1,state1,tmp,k);
	}
      for(i=n-1;i>=0;i--)
	{	  
	  sort[i]=tmp[n-1-i];
	  //printf("%lld ",sort[i]);
	}
      //printf("topo sort\n");
      //for(i=0;i<n;i++)
      //printf("%lld ",sort[i]);
      //printf("\n");
      long long int totalsum=0,totalways=1;
      for(i=0;i<n;i++)
	{
	  //printf("state2 of %lld is %lld\n",sort[i],state2[sort[i]]);
	  if(state2[sort[i]]==0)
	    {
	      long long int p=0,tmpcnt=0,mini=cost[sort[i]];
	      long long int compcosts[100005];
	      p=printdfs(sort[i],list2,state2,p,compcosts,cost);
	      for(j=0;j<p;j++)
		{
		  if(compcosts[j]<mini)
		    mini=compcosts[j];
		}
	      for(j=0;j<p;j++)
		{
		  if(compcosts[j]==mini)
		    tmpcnt++;
		}
	      totalways=((totalways%M)*(tmpcnt%M))%M;
	      //printf("mini added %lld\n",mini);
	      totalsum=totalsum+mini;
	    }
	}
      printf("%lld %lld\n",totalsum,totalways%M);
      for(i=0;i<=n;i++)
	{
	  free(list1[i]);
	  free(list2[i]);
	}
    }
  return 0;
}
  
