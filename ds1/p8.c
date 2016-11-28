#include <stdio.h>
double c[100005],d[100005];
double lvals[100005],rvals[100005];
#define m 1000000007
void merge(double a[],long long int l,long long int r,long long int p,long long int q)
{
  long long int k=0,x,y;
  long long int i=l,j=p;
  while(i<=r && j<=q)
    {
      if(a[i]<a[j])
	{
	  c[k]=a[i];
	  d[k]=rvals[i];
	  k++,i++;
	}
      else if(a[i]>a[j])
	{
	  c[k]=a[j];
	  d[k]=rvals[j];
	  k++,j++;
	}
      else if(a[i]==a[j])
	{
	  if(rvals[i]<rvals[j])
	    {
	      c[k]=a[i];
	      d[k]=rvals[i];
	      k++,i++;
	    }
	  else
	    {
	      c[k]=a[j];
	      d[k]=rvals[j];
	      k++,j++;
	    }
	}
    }
  while(i<=r)
    {
      c[k]=a[i];
      d[k]=rvals[i];
      k++,i++;
    }
  
  while(j<=q)
    {
      c[k]=a[j];
      d[k]=rvals[j];
      k++,j++;
    }
  
  for(x=0,y=l;x<k,y<=q;x++,y++)
    {
      a[y]=c[x];
      rvals[y]=d[x];
    }   
}

void mergesort(double a[],long long int low,long long int high)
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

long long int invmerge(double a[],long long int l,long long int r,long long int p,long long int q)
{
  long long int k=0,x,y;
  long long int i=l,j=p,cross=0;
  while(i<=r && j<=q)
    {
      if(a[i]<a[j])
	c[k++]=a[i++];
      else
	{
	  c[k++]=a[j++];
	  cross=(cross + ((p-i))%m)%m;
	}
    }
  while(i<=r)
    c[k++]=a[i++];
  
  while(j<=q)
    c[k++]=a[j++];
  
  for(x=0,y=l;x<k,y<=q;x++,y++)
    {
      a[y]=c[x];
    }  
  return cross%m;
}
long long int invmergesort(double a[],long long int low,long long int high)
{
  long long int cross=0;
  if(low<high)
    {
      long long int mid=low+(high-low)/2;
      cross=(cross+(invmergesort(a,low,mid))%m)%m;
      cross=(cross+(invmergesort(a,mid+1,high))%m)%m;
      cross=(cross+(invmerge(a,low,mid,mid+1,high))%m)%m;
    }
  return cross%m;
}

int main()
{
  long long int n,i,j,xline=0,ans=0;
  double l,r,a,b,c;
  scanf("%lld%lf%lf",&n,&l,&r);
  for(i=0;i<n;i++)
    {
      scanf("%lf%lf%lf",&a,&b,&c);
      if(b==0)
	xline++;
      else
	{
	  lvals[i] = ((-1)*(c+a*l))/(b);
	  rvals[i] = ((-1)*(c+a*r))/(b);
	}
    }
  mergesort(lvals,0,n-1-xline);
  ans=(invmergesort(rvals,0,n-1-xline))%m;
  ans=(ans+(xline*(n-xline))%m)%m;
  printf("%lld\n",ans);
  return 0;
}
