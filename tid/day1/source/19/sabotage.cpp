#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	int n,a[100001],y=2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=a[1]+a[n];
	double min=x*1.000/2;
	for(int i=2;i<n;i++)
	{
		x+=a[i];
		y++;
		if(x*1.000/y<min) min=x*1.000/y;
	}
	x=a[1]+a[n];
	y=2;
	for(int i=n-1;i>1;i--)
	{
		x+=a[i];
		y++;
		if(x*1.000/y<min) min=x*1.000/y;
	}
	printf("%.3lf",min);
}
