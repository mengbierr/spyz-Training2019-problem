#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=f*10+ch-'0';
	ch=getchar();}
	return f;
}
long long mod=1000000007;
int  f[20000005];int prime[6000005],tot; bool check[20000005];
int main()
{
	freopen("competition.in","r",stdin);
	freopen("competition.out","w",stdout);
	long long t=read();int l=read(),r=read();long long s=0,ans=0,x;bool ac=0;
	for(register int i=2;i<=r;i++)
	{
		if(!check[i])
		{
			prime[tot++]=i;
			x=i;
			f[i]=((x*(x-1))>>1)%mod;
		}
		for(int j=0;j<tot&&i*prime[j]<=r;j++)
		{
			check[i*prime[j]]=1;
			f[i*prime[j]]=(1LL*f[prime[j]]*i+1LL*f[i])%mod;

			if(i%prime[j]==0)
			break;
		}
		if(ac)
		s=(s*t)%mod;
		if(i==l)
		{
			ac=1;
			s=1;
		}
		if(ac)
		{
			ans+=f[i]*s;
			ans%=mod;
		}
	}
	cout<<ans;
}
