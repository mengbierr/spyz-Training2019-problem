#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
ll fac[200005],inv[200005];
int n,m,k;ll ans=0;
const int mod=998244353;
ll quick_mod(ll x,int y)
{
	ll ret=1;
	while(y)
	{
		if(y&1) ret=ret*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ret;
}
ll c(int x,int y)
{
	if(x<y) return 0;
	//cout<<fac[x]<<" "<<inv[y]<<" "<<inv[x-y]<<endl;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
	freopen("homework20.in","r",stdin);
	freopen("homework20.out","w",stdout);
	fac[0]=inv[0]=1;
	for(int i=1;i<=200000;i++) fac[i]=fac[i-1]*i%mod;
	inv[200000]=quick_mod(fac[200000],mod-2);
	for(int i=199999;i;i--) inv[i]=inv[i+1]*(i+1)%mod;
	n=read();m=read();k=read();
	ll temp1=1,temp2=1;
	for(int i=0;i<=k-1;i++)
	{
		(temp2*=c(n+m-2*i,2))%=mod;
		//cout<<c(n+m-2*i,2)<<" "<<temp2<<endl;
	}
	//cout<<temp2<<endl;
	for(int i=0;i<=k;i++)
	{
		ll temp=c(k,i);
		if(i%2==0)
		{
			ans+=1LL*temp*temp1%mod*temp2%mod;
			if(ans>=mod) ans-=mod;
		}
		else
		{
			ans-=1LL*temp*temp1%mod*temp2%mod;
			if(ans<0) ans+=mod;
		}
		(temp1*=c(m-2*i,2))%=mod;
		(temp2*=quick_mod(c(n+m-2*i,2),mod-2))%=mod;
	}
	cout<<ans;
}
// \sum i=0^k (-1)^i*c(k,i)*(\sum j=0^i-1 c(m-2*j,2))*(\sum j=i^k-1 c(n+m-2*j,2))

