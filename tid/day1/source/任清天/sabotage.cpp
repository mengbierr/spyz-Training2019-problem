#include<bits/stdc++.h>
using namespace std;
double a[10001];
bool b[10001];
struct edge
{
	double he,nn,ect;
}e[10001];
bool cmp(edge a,edge b)
{
	return a.ect<b.ect;
}
int main()
{
    //freopen("sabotage.in",r,stdin);
	//freopen("sabotage.out",w,stdout);
	int n;
	double kk=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%lf",&a[i]);kk+=a[i];}
	int ppap=kk/n;
	for(int i=1;i<=n;i++){a[i]=a[i+1];}
	n-=2;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=ppap) b[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)
		e[i].nn=double(e[i-1].nn+1);
		e[i].he=double(e[i-1].he+a[i]);
		e[i].ect=double(kk-e[i].he)/double(n+2-e[i].nn);
	}
	sort(e+1,e+n+1,cmp);
	printf("%.3lf",e[1].ect);
	return 0;
}
