#include <stdio.h>
typedef long long int ll;
int main()
{
  ll t;
  scanf("%lld",&t);
  while(t--)
    {
      ll n,i,j,min=0,max = 0,ans;
      ll a[100005];
      ll counter[100005]={0};
      scanf("%lld",&n);
      for(i=1;i<=n;i++)
	{
	  scanf("%lld",&a[i]);
	  counter[a[i]]++;	
	}
      for(i=1;i<100001;i++)
	{
	  if(counter[i]>max)
	    max=counter[i];
	}
      if(max>=n/2)
	ans=max;
      else
	ans=n/2 + n%2;
      printf("%lld\n",ans);
    }
  return 0;
}
      
      
