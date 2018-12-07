#include<cstdio>
using namespace std;
int n,a[30][5],ans;
void dfs(int x,int y,int z,int t)
{
	if(t==n+1) return;
	if(x==y&&y==z) ans=ans>x?ans:x;
	dfs(x+a[t][1],y+a[t][2],z,t+1);
	dfs(x+a[t][1],y,z+a[t][3],t+1);
	dfs(x,y+a[t][2],z+a[t][3],t+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	dfs(0,0,0,1);
	if(ans==0) printf("Impossible");
	else printf("%d",ans);
}
