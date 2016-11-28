#include <stdio.h>
int main()
{
  int t;
  scanf("%d",&t);
  while(t)
  {
      int a[100001],b[100001],c[100001],temp[100001];
      int i,j,x,y,z,count=0;
      scanf("%d",&x);
      for(i=0;i<x;i++)
	scanf("%d",&a[i]);
      scanf("%d",&y);
      for(i=0;i<y;i++)
	scanf("%d",&b[i]);
      scanf("%d",&z);
      for(i=0;i<z;i++)
	scanf("%d",&c[i]);
      int p=0,q=0,r=0,s=0,k=0;
      while(p<x && q<y)
	{
	  if(a[p]==b[q])
	    {
	      temp[k++]=a[p];
	      p++;q++;
	    }
	  else if(a[p]<b[q])
	    p++;
	  else if(b[q]<a[p])
	    q++;
	}
      while(r<z && s<k)
	{
	  if(c[r]==temp[s])
	    {
	      count++;
	      r++;s++;
	    }
	  else if(c[r]<temp[s])
	    r++;
	  else if(temp[s]<c[r])
	    s++;
	}
      printf("%d\n",count);
      t-- ;
  }
  return 0;
}
	  
      
