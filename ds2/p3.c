#include <stdio.h>
#include <stdlib.h>
#define M 1000000007
int main()
{
  long long int t;
  long long int a[100005],modvals[100005]={0};
  scanf("%lld",&t);
  while(t--)
    {
      long long int n,k,i,j,val,sum,total=0;
      scanf("%lld%lld",&n,&k);
      for(i=0;i<n;i++)
	{
	  scanf("%lld",&val);
	  a[i]=val%k;
	  modvals[i]=0;
	}
      sum=a[0];
      modvals[a[0]]++;
      for(i=1;i<n;i++)
	{
	  sum=(sum+a[i])%k;
	  modvals[sum]++;
	}
      for(i=0;i<k;i++)
	{
	  total=(total%M+((modvals[i]*(modvals[i]-1))/2)%M)%M;
	}
      total=(total%M+(modvals[0])%M)%M;
      printf("%lld\n",total%M);
    }
  return 0;
}
