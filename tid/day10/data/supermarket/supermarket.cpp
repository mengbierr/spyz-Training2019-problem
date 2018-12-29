#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define PROC "supermarket" 
using namespace std;
int n, b;
const int maxn=5010, inf=0x3f3f3f3f;
typedef long long LL;
int c[maxn], d[maxn], fa[maxn];
pair<int, int> seq[maxn];
int g[maxn][maxn], f[maxn][maxn], ff[maxn][maxn];
int len[maxn];

struct yjq{
	int f, t, n;
} naive[maxn];
int head[maxn], nn;

void addedge(int f, int t){
	nn++;
	naive[nn].f=f;
	naive[nn].t=t;
	naive[nn].n=head[f];
	head[f]=nn;
}

int dfs(int nowp){
	f[nowp][1]=c[nowp]-d[nowp];
	ff[nowp][1]=c[nowp]-d[nowp];
	int curs=1;
	for (int e=head[nowp]; e; e=naive[e].n){
		int t=naive[e].t;
		int tmp=dfs(t);
		for (int i=tmp; i; i--){
			for (int j=curs; j; j--){
				ff[nowp][i+j]=min(ff[nowp][i+j],f[nowp][j]+f[t][i]);
			}
		}
		curs+=tmp;
		for (int i=1; i<=curs; i++)
			f[nowp][i]=min(f[nowp][i],ff[nowp][i]);
	}
	for (int i=1; i<=curs; i++)
		f[nowp][i]=min(f[nowp][i], g[nowp][i]);
	return curs;
}

int main(){
	freopen(PROC".in", "r", stdin);
	freopen(PROC".out", "w", stdout);
	scanf("%d%d",&n,&b);
	memset(f,0x3f,sizeof f);
	memset(g,0x3f,sizeof g);
	memset(ff,0x3f,sizeof ff);
	for (int i=1; i<=n; i++){
		g[i][0]=f[i][0]=ff[i][0]=0;
		scanf("%d%d",&c[i],&d[i]);
		if (i>1){
			scanf("%d",&fa[i]);
			addedge(fa[i],i);
		}
		seq[i]=make_pair(c[i],i);
	}
	sort(seq+1,seq+1+n);
	for (int i=1; i<=n; i++){
		int v=seq[i].first;
		int p=seq[i].second;
		while (p){
			len[p]++;
			g[p][len[p]]=min(inf,g[p][len[p]-1]+v);
			p=fa[p];
		}
	}
	dfs(1);
//	for (int i=1; i<=n; i++)
//		for (int j=1; j<=len[i]; j++)
//			printf("f[%d][%d]=%lld, g=%lld\n",i,j,f[i][j],g[i][j]);
	for (int i=1; i<=n+1; i++){
		if (f[1][i]>b){
			printf("%d\n",i-1);
			break;
		}
	}
	return 0;
}
