#include<map>
#include<queue>
#include<cstdio>
using namespace std;
typedef pair<int,int> pir;
bool f;
map<pir,pir>m;
int n,a,k[3][20];
queue<int>q[3][2];
void bfs1(int d)
{
	int tx,ty,tz,l=q[0][0].size();
	if(d>n/2)
	{
		while(l--)
		{
			tx=q[0][0].front(),q[0][0].pop();
			ty=q[1][0].front(),q[1][0].pop();
			tz=q[2][0].front(),q[2][0].pop();
			m[pir(tx-ty,tx-tz)]=pir(1,tx);
		}
		return;
	}
	while(l--)
	{
		tx=q[0][0].front(),q[0][0].pop();
		ty=q[1][0].front(),q[1][0].pop();
		tz=q[2][0].front(),q[2][0].pop();
		q[0][0].push(tx+k[0][d]),q[1][0].push(ty+k[1][d]),q[2][0].push(tz);
		q[0][0].push(tx+k[0][d]),q[1][0].push(ty),q[2][0].push(tz+k[2][d]);
		q[0][0].push(tx),q[1][0].push(ty+k[1][d]),q[2][0].push(tz+k[2][d]);
	}
	bfs1(d+1);
	return;
}
void bfs2(int d)
{
	int tx,ty,tz,l=q[0][1].size();
	if(d==n/2)
	{
		while(l--)
		{
			tx=q[0][1].front(),q[0][1].pop();
			ty=q[1][1].front(),q[1][1].pop();
			tz=q[2][1].front(),q[2][1].pop();
			if(m[pir(ty-tx,tz-tx)].first)
			a=a>m[pir(ty-tx,tz-tx)].second+tx?a:m[pir(ty-tx,tz-tx)].second+tx,f=true;
		}
		return;
	}
	while(l--)
	{
		tx=q[0][1].front(),q[0][1].pop();
		ty=q[1][1].front(),q[1][1].pop();
		tz=q[2][1].front(),q[2][1].pop();
		q[0][1].push(tx+k[0][d]),q[1][1].push(ty+k[1][d]),q[2][1].push(tz);
		q[0][1].push(tx+k[0][d]),q[1][1].push(ty),q[2][1].push(tz+k[2][d]);
		q[0][1].push(tx),q[1][1].push(ty+k[1][d]),q[2][1].push(tz+k[2][d]);
	}
	bfs2(d-1);
	return;
}
int main(void)
{
	freopen("game.in","r",stdin);
	freopen("gae.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d%d%d",&k[0][i],&k[1][i],&k[2][i]);
	q[0][0].push(0),q[1][0].push(0),q[2][0].push(0);
	bfs1(1);
	q[0][1].push(0),q[1][1].push(0),q[2][1].push(0);
	bfs2(n);
	if(f)printf("%d",a);
	else printf("%s","Impossible");
	return 0;
}
