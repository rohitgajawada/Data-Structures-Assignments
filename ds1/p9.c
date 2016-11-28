#include <stdio.h>
long long int a[100005],dp[100005];
long long int getmin(long long int i,long long int j)
{
  long long int p,q;
  long long int minval=dp[i];
  for(p=i+1;p<=j;p++)
    {
      if(dp[p]<minval)
	minval=dp[p];
    }
  return minval;
} 
  
int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
    {
      long long int n,k,i,j,min;
      scanf("%lld%lld",&n,&k);
      for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
      dp[n-1]=a[n-1];  
      min=dp[n-1];
      for(i=n-2;i>=n-k-1;i--)
	{
	  if(dp[i+1]<min)
	    {
	      min=dp[i+1];
	    }
	  dp[i]=a[i]+min;
	  //printf("dp[%lld]=%lld\n",i,dp[i]);
	}
      for(i=n-k-2;i>=0;i--)
	{
	  if(dp[i+1]<min)
	    min=dp[i+1];
	  else if(dp[i+k+1]==min)
	    min=getmin(i+1,i+k);
	  dp[i]=a[i]+min;
	  //printf("dp[%lld]=%lld\n",i,dp[i]);
	}
      printf("%lld\n",dp[0]);
    }
  return 0;
}
	  
