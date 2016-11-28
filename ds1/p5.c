#include <stdio.h>
#include <stdlib.h>
int a[2];
typedef struct nodes
{
  int x;
  int y;
  struct nodes* next;
} node;

typedef struct queues
{
  node* headnode;
  node* tailnode;
} queue;

void enqueue(queue* q1,int i,int j)
{
  node* temp=(node *)malloc(sizeof(node));
  node* p1;
  temp->x=i;
  temp->y=j;
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
int* dequeue(queue* q1)
{
  node* temp=q1->headnode;
  a[0]=temp->x;
  a[1]=temp->y;
  q1->headnode=temp->next;
  return a;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      int m,n,i,j,rot1=0,rot2=0,time=0,a,b,empty=0;
      int* pts;
      char c;
      char eggs[1005][1005]={0};
      queue* q1=(queue *)malloc(sizeof(queue));
      q1->headnode=NULL;
      scanf("%d%d",&m,&n);;
      for(i=0;i<m;i++)
        {
	  for(j=0;j<n;j++)
	    {
	      do c=getchar();
	      while(isspace(c));
	      eggs[i][j]=c;
	      if(c=='r')
		{
		  enqueue(q1,i,j);
		  rot1++;
		}
	      if(c=='e')
		empty++;
	    }
	}
      if(rot1==0)
	time=-1;
      else if(empty==m*n)
	time=0;
      else
	{
	  while(1)
	    {
	      pts=dequeue(q1);
	      rot1--;
	      a=pts[0];
	      b=pts[1];
	      if(eggs[a-1][b]=='f' && a!=0)
		{
		  enqueue(q1,a-1,b);
		  eggs[a-1][b]='r';
		  rot2++;
		}
	      if(eggs[a+1][b]=='f' && a!=m-1)
		{
		  enqueue(q1,a+1,b);
		  eggs[a+1][b]='r';
		  rot2++;
		}
	      if(eggs[a][b-1]=='f' && b!=0)
		{
		  enqueue(q1,a,b-1);
		  eggs[a][b-1]='r';
		  rot2++;
		}
	      if(eggs[a][b+1]=='f' && b!=n-1)
		{
		  enqueue(q1,a,b+1);
		  eggs[a][b+1]='r';
		  rot2++;
		}
	      if(rot1==0 && rot2>0)
		{
		  rot1=rot2;
		  rot2=0;
		  time++;
		}
	      if(rot1==0 && rot2==0)
		break;
	    }
	  for(i=0;i<m;i++)
	    {
	      for(j=0;j<n;j++)
		{
		  if(eggs[i][j]=='f')
		    {
		      time=-1;
		      break;
		    }
		}
	      if(time==-1)
		break;
	    }
	}
      printf("%d\n",time);
    }
  return 0;
}
