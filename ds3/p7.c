#include <stdio.h>
#include <stdlib.h>
long long int finalans=0;
long long int maxpathcost=0,maxpathlength=0;
long long int maxpath[100005]={0};
long long int maxpathwts[100005]={0};
long long int visit[100005]={0};
typedef struct Node
{
  long long int val;
  long long int weight;
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
void getonepath(Node** list,Node* root,long long int* path,long long int* pathwts,long long int pathcost,long long int p)
{
  long long int i,j;
  long long int state=0;
  long long int value,cost;
  Node* ptr=root;
  while(ptr!=NULL)
    {
      value=ptr->val;
      if(visit[value]==0)
	{
	  state=1;
	  visit[value]=1;
	  cost=ptr->weight;
	  finalans=finalans+2*cost;
	  path[p]=value;
	  pathwts[p-1]=cost;
	  getonepath(list,list[value],path,pathwts,cost+pathcost,p+1);
	  ptr=ptr->next;
	}
      else
	ptr=ptr->next;
    }
  if(state==0)
    {
      if(pathcost>maxpathcost)
	{
	  maxpathcost=pathcost;
	  maxpathlength=p;
	  for(i=0;i<p;i++)
	    maxpath[i]=path[i];
	  for(i=0;i<p-1;i++)
	    maxpathwts[i]=pathwts[i];	    
	}
      return;
    }
}
  
int main()
{
  long long int n,m,i,j,a,b,wt;
  scanf("%lld",&n);
  m=n-1;
  Node* list[100005]={NULL};
  Node* temp1=NULL;
  Node* temp2=NULL;
  for(i=0;i<m;i++)
    {
      scanf("%lld%lld%lld",&a,&b,&wt);
      temp2=(Node *)malloc(sizeof(Node));
      temp2->val=b;
      temp2->weight=wt;
      list[a]=insert(list[a],temp2);
      temp1=(Node *)malloc(sizeof(Node));
      temp1->val=a;
      temp1->weight=wt;
      list[b]=insert(list[b],temp1);
    }
  long long int path[100005]={0};
  long long int pathwts[100005]={0};
  long long int pathcost=0;
  path[0]=1,visit[1]=1;
  getonepath(list,list[1],path,pathwts,pathcost,1);
  //for(i=0;i<maxpathlength;i++)
  //printf("%lld ",maxpath[i]);
  //for(i=0;i<maxpathlength-1;i++)
  // printf("%lld-",maxpathwts[i]);
  //printf("\n");
  for(i=0;i<maxpathlength-1;i++)
    finalans=finalans-maxpathwts[i];
  printf("%lld\n",finalans);
  for(i=1;i<=n;i++)
    free(list[i]);
  return 0;
}
