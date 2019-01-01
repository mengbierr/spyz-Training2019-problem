#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
#define pii pair<int,int>
using namespace std;
queue<pii> q;
int movex[5]={0,0,0,1,-1};
int movey[5]={0,1,-1,0,0};
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int n,k,mp[105][11],cou;
bool vis[105][11],check[105][11];
char s[100005];
vector<int> v[15];
void bfs(int x1)
{
	while(!q.empty())
	{
		cou++;
		pii temp=q.front();q.pop();
		int x=temp.first,y=temp.second;
		for(int i=1;i<=4;i++)
		{
			if(x+movex[i]<=n&&x+movex[i]>=1&&y+movey[i]>=1&&y+movey[i]<=10&&mp[x+movex[i]][y+movey[i]]==x1&&!vis[x+movex[i]][y+movey[i]])
			{
				vis[x+movex[i]][y+movey[i]]=1;
				q.push(pii(x+movex[i],y+movey[i]));
			}
		}
	}
}
void change(int x1)
{
	while(!q.empty())
	{
		pii temp=q.front();q.pop();
		int x=temp.first,y=temp.second;
		for(int i=1;i<=4;i++)
		{
			if(x+movex[i]<=n&&x+movex[i]>=1&&y+movey[i]>=1&&y+movey[i]<=10&&mp[x+movex[i]][y+movey[i]]==x1&&!check[x+movex[i]][y+movey[i]])
			{
				check[x+movex[i]][y+movey[i]]=1;
				q.push(pii(x+movex[i],y+movey[i]));
			}
		}
	}
}
int main()
{
	freopen("xhl.in","r",stdin);
	freopen("xhl.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=10;j++)
		{
			mp[i][j]=s[j]-'0';
		}
	}
	while(1)
	{
		bool ac=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=10;j++)
			{
				if(!vis[i][j]&&mp[i][j]!=0)
				{
					vis[i][j]=1;
					q.push(pii(i,j));
					cou=0;
					bfs(mp[i][j]);
					if(cou>=k)
					{
						ac=1;
						q.push(pii(i,j));
						change(mp[i][j]);
					}
					
				}
			}
		}
		for(int i=1;i<=10;i++) v[i].clear();
		for(int i=n;i;i--)
		{
			for(int j=1;j<=10;j++)
			{
				if(mp[i][j]&&!check[i][j])
				v[j].push_back(mp[i][j]);
			}
		}
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		memset(check,0,sizeof(check));
		for(int j=1;j<=10;j++)
		{
			for(int i=0;i<v[j].size();i++)
			{
				mp[n-i][j]=v[j][i];
			}
		}
		if(!ac) break;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=10;j++)
		{
			printf("%d",mp[i][j]);
		}
		puts("");
	}
}
