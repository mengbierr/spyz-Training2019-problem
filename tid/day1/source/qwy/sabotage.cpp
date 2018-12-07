#include<cstdio>
#include<algorithm>
using namespace std;
#define rg register
typedef double dl;
int n,a[100010],sum[100010],num;
dl x,ans=1e9;
inline void dfs(int l,int r)
{
	if(r==n) return;
	x=sum[l-1]+sum[n]-sum[r];
	num=l-1+n-r;
	x=x/dl(num);
	ans=min(ans,x);
	dfs(l,r+1);
}
int main(void)
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	scanf("%d",&n);
	for(rg int i=1;i<=n;i++){
		scanf("%d",a+i);
		sum[i]=sum[i-1]+a[i];
	}
	for(rg int i=2;i<n;i++) dfs(i,i);
	printf("%.3lf\n",ans);
	return 0;
}
