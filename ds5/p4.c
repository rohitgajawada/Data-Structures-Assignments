#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int cyclecheck(Node** list, int v, int* state, int* tmp)
{
  int value;
  if(state[v]==0)
    {
      state[v]=1;
      tmp[v]=1;
      Node* ptr=list[v];
      while(ptr!=NULL)
	{
	  value=ptr->val;
	  if(state[value]==0 && cyclecheck(list,value,state,tmp)==1)
	    return 1;
	  else if(tmp[value]==1)
	    return 1;
	  ptr=ptr->next;
	}
    }
  tmp[v]=0;
  return 0;
}

Node* list[100005];
int state[100005];
int tmp[100005];

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      int n,i,j,k,a,b;
      int cstate=0;
      int keep[30]={0};
      char str[550][550];
      scanf("%d",&n);
      for(i=0;i<100;i++)
	list[i]=NULL;
      for(i=0;i<n;i++)
	scanf("%s",str[i]);
      i=0;
      while(i<n-1)
	{	    
	  j=0;
	  a=str[i][j]-'a';
	  b=str[i+1][j]-'a';
	  int check=0;
	  while(a==b)
	    {
	      check=0;
	      j++;
	      a=str[i][j]-'a';
	      b=str[i+1][j]-'a';
	      if(a=='\0'-'a')
		{
		  i++;
		  check=1;
		  break;
		}
	      else if(b=='\0'-'a')
		{
		  cstate=1;
		  break;
		}
	    }
	  if(check==1)
	    continue;
	  if(cstate==1)
	    break;
	  keep[a]=1;
	  keep[b]=1;
	  memset(state,0,sizeof(state));
	  memset(tmp,0,sizeof(tmp));	      
	      
	  list[a]=insert(list[a],b);
	  //printf("%d added to %d\n",b,a);

	  for(k=0;k<26;k++)
	    {
	      if(keep[k]==1 && state[k]==0)
		cstate=cyclecheck(list,k,state,tmp);
	      if(cstate==1)
		break;
	    }
	  if(cstate==1)
	    break;
	  i++;
	}
      if(cstate==1)
	printf("Impossible\n");
      else
	printf("Possible\n");
    }
  return 0;
}

      
