#include <stdio.h>
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      int n,w,i,j,k,max;
      int a[100005],temp[100005];
      scanf("%d%d",&n,&w);
      for(i=0;i<n;i++)
	scanf("%d",&a[i]);
      for(i=0;i<=n-w;i++)
	{
	  max=a[i];
	  for(j=i;j<i+w;j++)
	    {
	      if(a[j]>max)
		max=a[j];
	    }
	  printf("%d ",max);
	  max=0;
	}
      printf("\n");
    }
  return 0;
}
		 
