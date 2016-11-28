#include <stdio.h>
int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
    {
      long long int n,k,q,i,j,start,end,totalcost=0,maxtotalcost=0,totalx=0,totaly=0,stop=0;
      long long int weights[100005],costs[100005],temp[100005];
      scanf("%lld%lld%lld",&n,&k,&q);
      for(i=0;i<k;i++)
	{
	  scanf("%lld",&weights[i]);
	  totaly+=weights[i];
	}
      for(i=k;i<n;i++)
	{
	  scanf("%lld",&weights[i]);
	}
      for(i=0;i<k;i++)
	{
	  scanf("%lld",&costs[i]);
	}
      for(i=k;i<n;i++)
	{
	  scanf("%lld",&costs[i]);
	  totalcost+=costs[i];
	}
      start=0,end=k-1;
      while(end<n-1)
	{
	  totalx+=weights[start];
	  totaly-=weights[start];
	  start++;
	  end++;
	  totaly+=weights[end];
	  totalcost-=costs[end];
	  while((totalx*q)<totaly)
	    {
	      totalx+=weights[start];
	      totaly-=weights[start];
	      start++;
	      end++;
	      totaly+=weights[end];
	      totalcost-=costs[end];
	    }
	  for(i=stop;i<start;i++)
	    {
	      if((totalx-weights[i])*q<totaly)
		{
		  stop=i;
		  break;
		}
	      totalx=totalx-weights[i];
	      totalcost+=costs[i];
	    }
	  if(totalcost>maxtotalcost)
	    maxtotalcost=totalcost;
	}
      printf("%lld\n",maxtotalcost);
    }
  return 0;
}
	  
	  

      
      
