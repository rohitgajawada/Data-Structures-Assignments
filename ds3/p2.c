#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int arr[2000007];
long long int state[2000007];
typedef struct Node
{
  long long int val;
  struct Node* next;
} Node;
Node* insert(Node* a, int b)
{
  Node* temp=NULL;
  temp=(Node *)malloc(sizeof(Node));
  temp->val=b;
  temp->next=a;
  return temp;
}
long long int getsubtrees(Node** list, int v)
{
  long long int count=1,value;
  Node* ptr=list[v];
  if(state[v]==0)
    state[v]=1;
  while(ptr!=NULL)
    {
      value=ptr->val;
      if(state[value]==0)
	count=(count)+(getsubtrees(list,value));
      ptr=ptr->next;
    }
  arr[v]=count;
  return count;
}
Node* list[2000005];
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      long long int n,i,j,a,b,ans;
      scanf("%lld",&n);
      for(i=0;i<=n+3;i++)
	{
	  state[i]=0;
	  arr[i]=0;
	  list[i]=NULL;
	}
      for(i=0;i<n-1;i++)
	{
	  scanf("%lld%lld",&a,&b);
	  list[a]=insert(list[a],b);
	}
      ans=getsubtrees(list,1);
      for(i=2;i<=n;i++)
      	printf("%lld ",arr[i]*(n-arr[i]));
      printf("\n");
    }
  return 0;
 }
