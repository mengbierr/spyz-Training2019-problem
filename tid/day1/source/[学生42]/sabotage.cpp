#include<bits/stdc++.h>
using namespace std;
long long sum;
double adv[100005],mi=11000.0;
int n[100005],a,begin[100005],end[100005];
void work(int x,int y)
{
	int j;
	double b,all=0.0,c,d;
	for(j=x;j<=y;j++)
		all+=n[j];
	c=a-(y-x+1);
	d=sum-all;
	b=d/c;
	if(b<mi)mi=b;
}
int main()
{
	int i,kk=0,m=1;
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	scanf("%d",&a);
	adv[0]=10000.0;
	for(i=1;i<=a;i++)
	{
		scanf("%d",&n[i]);
		sum+=n[i];
		adv[i]=(double)sum/i;
		if(adv[i]>adv[i-1]&&kk==0)
		{
			kk=1;
			begin[m]=i;
			continue;
		}
		if(adv[i]<adv[i-1]&&kk==1)
		{
			kk=0;
			end[m]=i-1;
			m++;
		}
	}
	for(i=1;i<m;i++)
		work(begin[i],end[i]);
	printf("%.3f",mi);
	return 0;
}
