#include <stdio.h>
typedef struct tri
{
  long long int val;
  long long int li;
  long long int ri;
} tri;
tri a[1000005];
long long int values[1000005]={0};
long long int ender[1000005];
int mycomp(const void *p,const void *q)
{
  long long int l=((tri *)p)->val;
  long long int r=((tri *)q)->val;
  return r-l;
}
int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
    {
      long long int n,i,j,k,p,q,max=0;
      scanf("%lld",&n);
      for(i=0;i<n;i++)
	{
	  scanf("%lld%lld%lld",&(a[i].li),&(a[i].ri),&(a[i].val));
	  if(a[i].ri > max)
	    max=a[i].ri;
	}
      qsort(a,n,sizeof(a[0]),mycomp);
      //printf("max is %lld\n",max);
      //for(i=0;i<n;i++)
      //printf("%lld %lld %lld\n",a[i].val,a[i].li,a[i].ri);
      for(i=0;i<=max+1;i++)
	{
	  values[i]=0;
	  ender[i]=-1;
	}
      for(i=0;i<n;i++)
	{
	  long long int nochange=0;
	  j=ender[a[i].li];
	  k=a[i].ri;
	  while(j!=-1)
	    {
	      if(j>=k)
		{
		  nochange=1;
		  break;
		}
	      j=ender[j];
	    }
	  if(j==-1)
	    j=a[i].li;
	  if(nochange==0)
	    {
	      for(p=j;p<k;p++)
		{
		  if(ender[p]!=-1)
		    {
		      p=ender[p]-1;
		      continue;
		    }
		  values[p]=a[i].val;
		  ender[p]=a[i].ri;
		}
	    }
	}
      //for(i=1;i<=max;i++)
      //printf("%lld ",values[i]);
      //printf("\n");
      for(i=1;i<=max;i++)
	{
	  if(values[i]!=values[i-1])
	    printf("%lld %lld\n",i,values[i]);
	}
    }
  return 0;
}
	  
	  
      
