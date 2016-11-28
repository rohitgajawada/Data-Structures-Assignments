#include <stdio.h>
typedef struct Node
{
  int val;
  struct Node* next;
} Node;
int arr[2000008];
Node* insert(Node* a, int b, int i)
{
  Node* temp=(Node *)malloc(sizeof(Node));
  temp->val=b;
  temp->next=a;
  return temp;
}
int findedges(Node** list, int v, int* state)
{
  if(state[v]==0)
    state[v]=1;
  Node* q=list[v];
  while(q->next!=NULL)
    {
      int tempsum=0;
      tempsum+=findedges(list, q->val, prev+1);
    }
 
}

  
Node* list[1000005];
int state[1000005];
 
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      int n,i,j,a,b;
      long long int ans;
      scanf("%d",&n);
      for(i=0;i<100005;i++)
	list[i]=NULL;
      for(i=0;i<n-1;i++)
	{
	  scanf("%d %d",&a,&b);
	  list[a]=insert(list[a],b);
	}
      ans=findedges(list,1,state);
      
    }
  return 0;
}
