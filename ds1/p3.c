#include <stdio.h>
#include <stdlib.h>
typedef struct nodes
{
  char val;
  struct nodes* next;
} node;
typedef struct stacks
{
  node* headnode;
} stack;

void push(stack* stack1,char item)
{
  node* temp=(node *)malloc(sizeof(node));
  temp->val=item;
  temp->next=stack1->headnode;
  stack1->headnode=temp;
}
char pop(stack* stack1)
{
  node* temp=stack1->headnode;
  int data=temp->val;
  stack1->headnode=temp->next;
  free(temp);
  return data;
}
char top(stack* stack1)
{
  node* temp=stack1->headnode;
  return temp->val;
}
int main()
{
  int t;
  char str[200005],noth;
  scanf("%d",&t);
  while(t--)
    {
      int i=0,state=1;
      char x;
      scanf("%s",str);
      stack* s1=(stack *)malloc(sizeof(stack));
      s1->headnode=NULL;
      while(str[i]!='\0')
	{
	  if(str[i]=='(' || str[i]=='[' || str[i]=='{')
	    push(s1,str[i]);
	  if(str[i]==')' || str[i]==']' || str[i]=='}')
	    {
	      x=top(s1);
	      if(x=='(' && str[i]==')')
		noth=pop(s1);
	      else if(x=='[' && str[i]==']')
		noth=pop(s1);
	      else if(x=='{' && str[i]=='}')
		noth=pop(s1);
	      else
		{
		  state=0;
		  break;
		}
	    }
	  i++;
	}
      free(s1);
      if(state==1)
	printf("Yes\n");
      else
	printf("No\n");
    }
  return 0;
}
	      
      
      

