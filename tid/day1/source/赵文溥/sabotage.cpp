#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,s[100009]={0},a[200000];
double f[200000]={0},d[100009]={0},ans=0,aa=0;
int x=0,h=10,dd=0;
int main()
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		aa+=a[i];
	}
	
	double bb=double(aa)/double(n);
	double cc=bb;
	
	for(int i=1;i<=n;i++)
	{
		f[i]=a[i+1];
		f[i]-=cc;
	}
	int wn=n-2;
	for(int i=1;i<=wn;i++)
	{
		if(f[i]>0)
		{
			if(f[i-1]<=0)
			{
				h++;s[h]=1;
				d[h]+=f[i];
				if(f[i]<d[h-2]+d[h-1]+f[i])
				{
					s[h]+=s[h-2]+s[h-1];
				}
				f[i]=max(f[i],d[h-2]+d[h-1]+f[i]);
				if(f[i]>ans)ans=f[i],x=s[h];
			}
			else 
			{
				
				
				d[h]+=f[i];
				f[i]+=f[i-1];
				s[h]++;
				if(f[i]>ans)ans=f[i],x=s[h];
			}
		}
		if(f[i]<=0)
		{
			if(f[i-1]>0)
			{
				h++;
				d[h]+=f[i];
				s[h]++;
			}
			else d[h]+=f[i],s[h]++;
		}
		
	}
	ans+=cc*x;
	double ss=double(aa-ans)/double(n-x);
	printf("%.3lf",ss);
	return 0;
}
