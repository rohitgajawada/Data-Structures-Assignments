#include <stdio.h>
#include <stdlib.h>
#define M 1000000007
long long int twomods[100]={0};
long long int fastmod(long long int a,long long int b)
{
  long long int x,c=1000000007;
  for(x=0;x<64;x++)
    twomods[x]=0;
  twomods[0]=a%c;
  long long int i=1,t=0;
  long long int q=b,sum=1,count=0;
  while(i<=63)
    {
      twomods[i]=((twomods[i-1])*(twomods[i-1]))%c;
      i++;
    }
  while(q>0)
    {
      t=q%2;
      if(t==1)
	sum=((sum%c)*((twomods[count])%c))%c;
      count++;
      q/=2;
    }
  return sum%c;
}
typedef struct nodes
{
  long long int val;
  struct nodes* next;
} node;
typedef struct stacks
{
  node* headnode;
} stack;

void push(stack* stack1,long long int item)
{
  node* temp=(node *)malloc(sizeof(node));
  temp->val=item;
  temp->next=stack1->headnode;
  stack1->headnode=temp;
}
long long int pop(stack* stack1)
{
  node* temp=stack1->headnode;
  long long int data=temp->val;
  stack1->headnode=temp->next;
  free(temp);
  return data;
}
long long int top(stack* stack1)
{
  node* temp=stack1->headnode;
  return temp->val;
}
int main()
{
  long long int t;
  char str[200005];
  scanf("%lld",&t);
  while(t--)
    {
      long long int i=0,x,y,ans;
      stack* s1;
      s1=(stack *)malloc(sizeof(stack));
      s1->headnode=NULL;
      scanf("%s",str);
      while(str[i]!='\0')
	{
	  if(str[i]>='0' && str[i]<='9')
	    push(s1,str[i]-'0');
	  else if(str[i]=='+')
	    {
	      x=pop(s1);
	      y=pop(s1);
	      push(s1,(y+x+M)%M);
	    }
	  else if(str[i]=='-')
	    {
	      x=pop(s1);
	      y=pop(s1);
	      push(s1,(y-x+M)%M);
	    }
	  else if(str[i]=='*')
	    {
	      x=pop(s1);
	      y=pop(s1);
	      push(s1,((y%M)*(x%M))%M);
	    }
	  else if(str[i]=='/')
	    {
	      x=pop(s1);
	      y=pop(s1);
	      push(s1,((y%M)*((fastmod(x,M-2))%M))%M);
	    }
	  i++;
	}
      ans=pop(s1)%M;
      printf("%lld\n",ans);
    }
  return 0;
}
