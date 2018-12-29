#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000005];
int n;
struct trie
{
	int ch[1000005][26];
	int f[1000005],sum[1000005],fin[210];
	int q[1000005],idx[200],sz;
	trie(){sz=1;for(char i='a';i<='z';i++) idx[i]=i-'a';}
	void insert(char *s,int k)
	{
		int u=0,len=strlen(s);
		for(int i=0;i<len;i++)
		{
			int x=idx[s[i]];
			if(!ch[u][x])
			ch[u][x]=sz++;
			u=ch[u][x];
			sum[u]++;
		}
		fin[k]=u;
	}
	void get_fail()
	{
		int lt=1,rt=0;
		for(int i=0;i<26;i++)
		{
			int u=ch[0][i];
			if(u)
			{
				f[u]=0;
				q[++rt]=u;
			}
		}
		while(lt<=rt)
		{
			int r=q[lt];lt++;
			for(int i=0;i<26;i++)
			{
				int &u=ch[r][i];
				if(!u)
				continue;
				int v=f[r];
				while(v&&!ch[v][i])
				v=f[v];
				f[u]=ch[v][i];
				q[++rt]=u;
			}
		}
		for(;rt;rt--) sum[f[q[rt]]]+=sum[q[rt]];
	}
}ac;
int main()
{
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		ac.insert(s,i);
	}
	ac.get_fail();
	for(int i=1;i<=n;i++)
	printf("%d\n",ac.sum[ac.fin[i]]);
	return 0;
} 
