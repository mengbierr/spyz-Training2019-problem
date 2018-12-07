#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[30]={0},b[30]={0},c[30]={0},yb,aa[400][400][400],bb[400][400][400];
int ans=0;
void dfs(int x,int y,int z,int cs)
{
	if(cs==yb+1)
	{
		
		if(x<=y&&x<=z)aa[0][y-x][z-x]=max(aa[0][y-x][z-x],x+y+z);
		else if(y<=x&&y<=z)aa[x-y][0][z-y]=max(aa[x-y][0][z-y],x+y+z);
		else if(z<=x&&z<=y)aa[x-z][y-z][0]=max(aa[x-z][y-z][0],x+y+z);
		return ;
	}
	dfs(x+a[cs],y+b[cs],z,cs+1);
	dfs(x+a[cs],y,z+c[cs],cs+1);
	dfs(x,y+b[cs],z+c[cs],cs+1);
	
}
void dfs2(int x,int y,int z,int cs)
{
	if(cs==n+1)
	{
		if(x>=y&&x>=z&&aa[0][x-y][x-z]+x+y+z>ans)ans=aa[0][x-y][x-z]+x+y+z;
		if(y>=x&&y>=z&&aa[y-x][0][y-z]+x+y+z>ans)ans=aa[y-x][0][y-z]+x+y+z;
		if(z>=x&&z>=y&&aa[z-x][z-y][0]+x+y+z>ans)ans=aa[z-x][z-y][0]+x+y+z;
		return ;
	}
	dfs2(x+a[cs],y+b[cs],z,cs+1);
	dfs2(x+a[cs],y,z+c[cs],cs+1);
	dfs2(x,y+b[cs],z+c[cs],cs+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	yb=n/2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	dfs(0,0,0,1);
	dfs2(0,0,0,yb+1);
	if(ans==0)printf("Impossible");
	else ans/=3,printf("%d",ans);
	return 0;
}
