#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long sum,n,a[1000010],maxn;
double ans=1e9+7,b,s,summ,h;
bool judge(double num)
{
	s=0;
	h=0;
	summ=a[1]+a[n]-2*num;
	for(int i=2;i<=n-1;i++)
	{
		b=a[i]-num;
		summ+=b;
		s+=b;
		if(s<0) s=0;
		else h=max(s,h);
    }
	if(summ-h<=0) return true;
	else return false;
}
int main()
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]),sum+=a[i],maxn=max(maxn,a[i]);
	double l=0,r=double(sum-maxn)/double(n-1);
	while(r-l>1e-4)
	{
		double mid=(l+r)/2;
		if(judge(mid))
		{
			r=mid;
			ans=min(ans,mid);
		}
		else l=mid;
	}
	printf("%.3lf",ans);
}

