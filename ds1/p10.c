#include <stdio.h>
int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
    {
      long long int n,i,j,k,winwid;
      long long int a[100005],start[100005],end[100005];
      long long int out[100005]={0};
      scanf("%lld",&n);
      for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
      for(i=0;i<n;i++)
	{
	  for(j=i+1;j<n;j++)
	    {
	      if(a[j]<a[i])
		{
		  break;
		}
	    }
	  end[i]=j;
	  for(j=i-1;j>=0;j--)
	    {
	      if(a[j]<a[i])
		{
		  break;
		}
	    }
	  start[i]=j;
	}
      for(i=0;i<n;i++)
	{
	  winwid=end[i]-start[i]-1;
	  if(a[i]>out[winwid])
	    out[winwid]=a[i];
	}
      for(i=n;i>=1;i--)
	{
	  if(out[i+1]>out[i])
	    out[i]=out[i+1];
	}
      for(i=1;i<=n-1;i++)
	printf("%lld ",out[i]);
      printf("%lld\n",out[n]);
    }
  return 0;
}
	  
