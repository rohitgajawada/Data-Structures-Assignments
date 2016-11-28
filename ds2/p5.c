#include<stdio.h>
#include<stdlib.h>
typedef struct qnode
{
  long long int val;
  struct qnode* next;
} qnode;
typedef struct queues
{
  qnode* headnode;
  qnode* tailnode;
} queue;

void enqueue(queue* q1,long long int item)
{
  qnode* temp=(qnode *)malloc(sizeof(qnode));
  qnode* p1;
  temp->val=item;
  if(q1->headnode==NULL)
    {
      q1->headnode=temp;
      q1->tailnode=temp;
    }
  else
    {
      p1=q1->tailnode;
      p1->next=temp;
      temp->next=NULL;
      q1->tailnode=temp;
    }      
}
long long int dequeue(queue* q1)
{
  qnode* temp=q1->headnode;
  long long int data=temp->val;
  q1->headnode=temp->next;
  return data;
}

int main()
{
  long long int n,i,j,ind;
  char a,name[100005];
  char values[100005];
  long long int list[30][100005];
  long long int put[30]={0};
  memset(list,0,sizeof(long long int)*30*100005);
  long long int visit[100005]={0};
  long long int cost[100005]={0};
  
  queue* q1=(queue *)malloc(sizeof(queue));
  q1->headnode=NULL;
  scanf("%lld",&n);
  scanf("\n");
  
  for(i=0;i<n;i++)
    {
      scanf("%c",&values[i]);
      scanf("%[^\n]s",name);
      scanf("\n");
      ind=values[i]-'a';
      list[ind][put[ind]]=i;
      put[ind]++;
    }
  
  long long int x,y,z;
  enqueue(q1,0);
  visit[0]=1;
  cost[0]=0;
  while(q1->headnode!=NULL)
    {
      x=dequeue(q1);
      if(x==n-1)
	break;
      if(visit[x-1]==0 && x!=0)
	{
	  visit[x-1]=1;
	  cost[x-1]=cost[x]+1;
	  enqueue(q1,x-1);
	}
      if(visit[x+1]==0)
	{
	  visit[x+1]=1;
	  cost[x+1]=cost[x]+1;
	  enqueue(q1,x+1);
	}
      for(y=0;y<put[values[x]-'a'];y++)
	{
	  z=list[values[x]-'a'][y];
	  if(visit[z]==0)
	    {
	      visit[z]=1;
	      cost[z]=cost[x]+1;
	      enqueue(q1,z);
	    }
	}
    }
  printf("%lld\n",cost[n-1]);
  free(q1);
  return 0;
}
