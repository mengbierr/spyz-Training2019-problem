#include<cstdio>
using namespace std;
int n,a[100002],p,sum,s;
double ans=1e9;
int main()
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),s+=a[i];
	for(int i=2;i<n;i++)
	{
		sum=0;
		for(int j=0;i+j<n;j++)
		{
			sum+=a[i+j];
			if(sum==130) printf("%d %d",i,j);
			if(double(s-sum)/double(n-j-1)<ans) ans=double(s-sum)/double(n-j-1);
		}
	}
	printf("%.3lf",ans);
}
