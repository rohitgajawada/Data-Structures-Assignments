#include <stdio.h>

void merge(long long int a[],long long int l,long long int r,long long int p,long long int q)
{
  long long int c[200005],k=0,x,y;
  long long int i=l,j=p;
  while(i<=r && j<=q)
    {
      if(a[i]<a[j])
	c[k++]=a[i++];
      else
	c[k++]=a[j++];
    }
  while(i<=r)
    c[k++]=a[i++];
  
  while(j<=q)
    c[k++]=a[j++];
  
  for(x=0,y=l;x<k,y<=q;x++,y++)
    {
      a[y]=c[x];
    }   
}

void mergesort(long long int a[],long long int low,long long int high)
{
  if(low<high)
    {
      long long int temp;
      long long int mid=low+(high-low)/2;
      mergesort(a,low,mid);
      mergesort(a,mid+1,high);
      merge(a,low,mid,mid+1,high);
    }
}

int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
    {
      long long int n,i,j,key,count=0;
      long long int a[200005];
      scanf("%lld",&n);
      for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
      mergesort(a,0,n-1);
      key=a[0];
      count=1;
      for(i=1;i<n;i++)
	{
	  if(a[i]==key)
	    {
	      count++;
	      if(count>(n/2))
		break;
	    }
	  else
	    {
	      key=a[i];
	      count=1;
	    }
	}
      printf("%lld\n",key);
    }
  return 0;
}
