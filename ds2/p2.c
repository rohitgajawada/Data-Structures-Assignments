#include <stdio.h>
int cmpfunc(const void* a, const void* b)
{
   return ( *(long long int*)a > *(long long int*)b );
}

int main()
{
  long long int t;
  long long int a[100005];
  scanf("%lld",&t);
  while(t--)
    {
      long long int n,i,j,count,max=0;
      scanf("%lld",&n);
      for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
      qsort(a,n,sizeof(long long int),cmpfunc);
      for(i=0;i<n-1;i++)
	{
	  count=n-i-1;
	  if(a[i]<count && a[i+1]>=count)
	    {
	      if(count>max)
		max=count;
	    }
	  else if(a[i]>=count+1)
	    {
	      if(count+1>max)
		max=count+1;
	    }
	}
      if(a[n-1]>=1)
	{
	  if(1>max)
	    max=1;
	}
      if(n==1)
	{
	  if(a[0]==0)
	    max=0;
	  else
	    max=1;
	}
      printf("%lld\n",max);
    }
  return 0;
}


