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
ll n;ll k;
ll cou[1000005];
int main()
{
	cin>>n>>k;
	if(n==1)
	{
		cout<<k;
		return 0;
	}
	ll lim=sqrt(k);
	for(int i=2;i<=lim;i++)
	{
		while(k%i==0)
		{
			cou[i]++;
			k/=i;
		}
	}
	ll ans=1;
	for(int i=2;i<=lim;i++)
	{
		while(cou[i]>=n)
		{
			cou[i]-=n;
			ans*=i;
		}
	}
	cout<<ans;
}

