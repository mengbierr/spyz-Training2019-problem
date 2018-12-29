#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
 
#define ll long long
#define inf 1e9
#define eps 1e-8
#define md
#define N 5001
using namespace std;
struct yts { int x,t,ne;} e[N];
int v[N],link[N],X[51][51],Y[51][51];
int vis[N];
char st[51][51];
int num;
void put(int x,int y)
{
	num++; e[num].x=x; e[num].t=y;
	e[num].ne=v[x]; v[x]=num;
}
 
bool dfs(int x,int id)
{
	for (int i=v[x];i;i=e[i].ne)
	{
		int y=e[i].t;
		if (vis[y]==id) continue; vis[y]=id;
		if (!link[y]||dfs(link[y],id))
		{
			link[y]=x;
			return 1;
		}
	}
	return 0;
}
	
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",st[i]+1);
	int A=1,B=1;
	for (int i=1;i<=n;i++)
	{
	  for (int j=1;j<=m;j++)
	  {
	  	if (st[i][j]=='#') A++;
	  	X[i][j]=A;
	  }
	  A++;
	}
	for (int j=1;j<=m;j++)
	{
	  for (int i=1;i<=n;i++)
	  {
	  	if (st[i][j]=='#') B++;
	  	Y[i][j]=B;
	  }
	  B++;
	}
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=m;j++)
	    if (st[i][j]=='*') put(X[i][j],Y[i][j]);
	int ans=0;
	for (int i=1;i<=A;i++) ans+=dfs(i,i);
	printf("%d\n",ans);
	return 0;
}
