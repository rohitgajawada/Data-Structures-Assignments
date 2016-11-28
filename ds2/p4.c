#include <stdio.h>
#include <string.h>
char ab1[200005],bc1[200005],ca1[200005];
char ab2[200005],bc2[200005],ca2[200005];
char tmp1[300005],tmp2[300005],tmp3[300005],tmp4[300005],tmp5[300005],tmp6[300005];

void mycat(char a[],char b[],char ab1[])
{
  long long int i,j,k,count=0,count1=0,count2=0;
  long long int totalmatch=0,inside=0;
  long long int p,q,s,t;
  long long int len1=strlen(a),len2=strlen(b);
  long long int beg,end,start=-1,fin=-1;
  j=0;
  for(i=0;i<len1;i++)
    {
      if(a[i]==b[j])
	{
	  p=i,q=j;
	  p++,q++,count=1;
	  beg=i;
	  while(p<len1 && q<len2)
	    {
	      if(a[p]==b[q])
		{
		  count++;
		  p++,q++;
		}
	      else if(a[p]!=b[q])
		{
		  count=0;
		  break;
		}
	    }
	  if(p>=len1 || q>=len2)
	    {
	      totalmatch++;
	      if(q>=len2)
		{
		  inside=1;
		  break;
		}
	    }
	  else
	    count=0;
	  end=p-1;
	  if(count>count1)
	    {
	      count1=count;
	      start=beg;
	      fin=end;
	    }
	  count=0;
	}
    }
 
  k=0;
  if(totalmatch==0)
    {
      for(i=0;i<len1;i++)
	ab1[k++]=a[i];
      for(j=0;j<len2;j++)
	ab1[k++]=b[j];
      ab1[k]='\0';
    }
  else if(inside==1)
    {
      for(i=0;i<len1;i++)
	ab1[k++]=a[i];
      ab1[k]='\0';
    }
  else
    {
      for(i=0;i<start;i++)
	ab1[k++]=a[i];
      for(j=0;j<len2;j++)
	ab1[k++]=b[j];
      ab1[k]='\0';
    }
   //printf("part string is %s\n",ab1);
   //printf("part string is %s\n",ab2);
}     	      

int main()
{
  char a[100005],b[100005],c[100005];
  scanf("%s",a);
  scanf("%s",b);
  scanf("%s",c);
  long long int l[20],min=100000000;
  long long int i,j;
  mycat(a,b,ab1);
  mycat(b,a,ab2);
  mycat(b,c,bc1);
  mycat(c,b,bc2);
  mycat(c,a,ca1);
  mycat(a,c,ca2);
  //printf("--\n");
  mycat(ab1,c,tmp1);
  mycat(c,ab1,tmp2);
  l[0]=strlen(tmp1);l[1]=strlen(tmp2);
  mycat(ab2,c,tmp1);
  mycat(c,ab2,tmp2);
  l[2]=strlen(tmp1);l[3]=strlen(tmp2);
  mycat(bc1,a,tmp3);
  mycat(a,bc1,tmp4);
  l[4]=strlen(tmp3);l[5]=strlen(tmp4);
  mycat(bc2,a,tmp3);
  mycat(a,bc2,tmp4);
  l[6]=strlen(tmp3);l[7]=strlen(tmp4);
  mycat(ca1,b,tmp5);
  mycat(b,ca1,tmp6);
  l[8]=strlen(tmp5);l[9]=strlen(tmp6);
  mycat(ca2,b,tmp5);
  mycat(b,ca2,tmp6);
  l[10]=strlen(tmp5);l[11]=strlen(tmp6);
 
  for(i=0;i<12;i++)
    {
      if(l[i]<min)
	min=l[i];
    }
  printf("%lld\n",min);
  return 0;
}
	 
	 
