#include<bits/stdc++.h>
using namespace std;
long long s[100002];
int main()
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a[n+1];
	double minn=99999.9,k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+2,a+n);
	for(int i=2;i<n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<n;i++)
	{
		k=double(s[i]+a[1]+a[n])/double(i+1);
		if(k<minn)minn=k;
	}
	printf("%.3lf",minn);
} 
