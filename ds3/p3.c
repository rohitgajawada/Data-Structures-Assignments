#include <stdio.h>
#include <stdlib.h>
long long int levels[500005],checkprime[9000000]={0},myprimes[500005]={0};
long long int state[500005]={0};
long long int temp[500005]={0};
long long int cycleflag=0;
typedef struct Node
{
  long long int val;
  struct Node* next;
} Node;
Node* list[500005]={NULL};
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
long long int cyclecheck(Node** list,long long int v,long long int* state,long long int* temp)
{
  long long int value;
  if(state[v]==0)
    {
      state[v]=1;
      temp[v]=1;
      Node* ptr=list[v];
      while(ptr!=NULL)
	{
	  value=ptr->val;
	  if(state[value]==0 && cyclecheck(list,value,state,temp)==1)
	    {
	      return 1;
	    }
	  else if(temp[value]==1)
	    {
	      return 1;
	    }
	  ptr=ptr->next;
	}
    }
  temp[v]=0;
  return 0;
}
void topolevels(long long int v,Node** list,long long int *state)
{
  state[v]=1;
  Node* ptr=list[v];
  while(ptr!=NULL)
    {
      long long int value=ptr->val;
      if(levels[value]<=levels[v])
	levels[value]=levels[v]+1;
      if(state[value]==0)
	topolevels(value,list,state);
      ptr=ptr->next;
    }
} 
  
int main()
{
  long long int t;
  scanf("%lld",&t);
  long long int i,k=0,p;
  for(i=2;i<=9000000;i++)
    checkprime[i]=1;
  for(p=2;p*p<=9000000;p++)
    {
      if(checkprime[p]==1)
	{
	  for(i=p*2;i<=9000000;i+=p)
	    checkprime[i]=0;
	}
    }
  for(p=2;p<=9000000;p++)
    {
      if(checkprime[p]==1)
	myprimes[k++]=p;
    }
  while(t--)
    {
      cycleflag=0;
      long long int n,m,i,j,a,b;
      scanf("%lld%lld",&n,&m);
      for(i=0;i<n+1;i++)
	{
	  list[i]=NULL;
	  state[i]=0;
	  temp[i]=0;
	  levels[i]=-1;
	}
      Node* temp2=NULL;
      for(i=0;i<m;i++)
	{
	  scanf("%lld%lld",&a,&b);
	  temp2=(Node *)malloc(sizeof(Node));
	  temp2->val=a;
	  list[b]=insert(list[b],temp2);
	}
      for(i=0;i<n;i++)
	{
	  if(state[i]==0)
	    cycleflag=cyclecheck(list,i,state,temp);
	  if(cycleflag==1)
	    break;
	}
      long long int finalsum=0;
      if(cycleflag==1)
	printf("evil emperor loses\n");
      else
	{
	  levels[0]=0;
	  for(i=0;i<n;i++)
	    state[i]=0;
	  for(i=0;i<n;i++)
	    topolevels(i,list,state);
	  for(i=1;i<n;i++)
	    finalsum+=myprimes[levels[i]-1];
	  printf("%lld\n",finalsum);
	}
      Node *p,*q;
      for(i=0;i<n;i++)
	{
	  p=list[i];
	  while(p!=NULL)
	    {
	      q=p->next;
	      free(p);
	      p=q;
	    }
	} 
    }
  return 0;
}

