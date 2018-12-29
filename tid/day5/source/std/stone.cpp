#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[105],maxx,ans;
int main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int n=a+b+c;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			for(int k=1;k<=c;k++)
			f[i+j+k]++;
		}
	}
	for(int i=3;i<=n;i++)
	{
		if(f[i]>maxx)
		{
			 maxx=f[i];
			 ans=i;
		}
	}
	cout<<ans;
}
