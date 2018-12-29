#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int n,L,l,r;
int c[50005],q[50005];
long long s[50005],f[50005],C;
double slop(int j,int k)
{
	return (f[k]-f[j]+(s[k]+C)*(s[k]+C)-(s[j]+C)*(s[j]+C))/(2.0*(s[k]-s[j]));
}
void dp()
{
	l=1,r=0;q[++r]=0;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&slop(q[l],q[l+1])<=s[i]) l++;
		int t=q[l];
		f[i]=f[t]+(s[i]-s[t]-C)*(s[i]-s[t]-C);
		while(l<r&&slop(q[r],i)<slop(q[r-1],q[r])) r--;
		q[++r]=i;
	}
}
int main()
{
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	n=read();L=read();C=L+1;
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++) s[i]=s[i-1]+c[i];
	for(int i=1;i<=n;i++) s[i]+=i;
	dp();
	cout<<f[n];
}
