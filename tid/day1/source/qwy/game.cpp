#include<cstdio>
#include<algorithm>
using namespace std;
#define rg register
int n,a[30],b[30],c[30],f[400][400][400],g[400][400][400],ans;
bool ff;
inline void dfs1(int x,int y,int z,int deep)
{
	if(deep==(n>>1)+1){
		if(x<=y&&x<=z) f[0][y-x][z-x]=x+y+z,g[0][y-x][z-x]=1;
		else if(y<=x&&y<=z) f[x-y][0][z-y]=x+y+z,g[x-y][0][z-y]=1;
		else if(z<=x&&z<=y) f[x-z][y-z][0]=x+y+z,g[x-z][y-z][0]=1;
		return;
	}
	dfs1(x+a[deep],y+b[deep],z,deep+1);
	dfs1(x+a[deep],y,z+c[deep],deep+1);
	dfs1(x,y+b[deep],z+c[deep],deep+1);
}
inline void dfs2(int x,int y,int z,int deep)
{
	if(deep==n){
		if(x>=y&&x>=z&&g[0][x-y][x-z]) ans=max(ans,(f[0][x-y][x-z]+x+y+z)/3),ff=true;
		else if(y>=x&&y>=z&&g[y-x][0][y-z]) ans=max(ans,(f[y-x][0][y-z]+x+y+z)/3),ff=true;
		else if(z>=x&&z>=y&&g[z-x][z-y][0]) ans=max(ans,(f[z-x][z-y][0]+x+y+z)/3),ff=true; 
		return;
	}
	dfs2(x+a[deep],y+b[deep],z,deep+1);
	dfs2(x+a[deep],y,z+c[deep],deep+1);
	dfs2(x,y+b[deep],z+c[deep],deep+1);
}
int main(void)
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(rg int i=1;i<=n;i++) scanf("%d%d%d",a+i,b+i,c+i);
	dfs1(0,0,0,1);
	dfs2(0,0,0,(n>>1)+1);
	ff?printf("%d\n",ans):printf("Impossible\n");
	return 0;
}
