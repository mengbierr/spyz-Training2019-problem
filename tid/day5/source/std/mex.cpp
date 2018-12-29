#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 200200
using namespace std;
struct abcd{
	int l,r,id;
	bool operator < (const abcd &x) const;
}queries[M];
int n,m,b;
int a[M],belong[M],l[M],r[M];
int L=1,R=0,f[M],block_ans[M],ans[M];
bool abcd :: operator < (const abcd &x) const
{
	if(belong[l]!=belong[x.l])
		return l<x.l;
	return r<x.r;
}
void Update(int x)
{
	if(x>n) return ;
	if(!f[x]++)
		block_ans[belong[x]]++;
}
void Downdate(int x)
{
	if(x>n) return ;
	if(!--f[x])
		block_ans[belong[x]]--;
}
int Query()
{
	int i;
	if(!f[0]) return 0;
	for(i=1;l[i];i++)
		if(block_ans[i]!=r[i]-l[i]+1)
			break;
	int temp=i;
	for(i=l[temp];i<=r[temp];i++)
		if(!f[i])
			return i;
	return n;
}
int main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	int i;
	cin>>n>>m;
	b=int(sqrt(n)+1e-7);
	for(i=1;i<=n;i++)
		belong[i]=(i-1)/b+1;
	for(i=1;(i-1)*b+1<=n;i++)
		l[i]=(i-1)*b+1,r[i]=min(i*b,n);
 
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d%d",&queries[i].l,&queries[i].r),queries[i].id=i;
	sort(queries+1,queries+n+1);
	for(i=1;i<=m;i++)
	{
		while(R<queries[i].r)
			Update(a[++R]);
		while(L>queries[i].l)
			Update(a[--L]);
		while(R>queries[i].r)
			Downdate(a[R--]);
		while(L<queries[i].l)
			Downdate(a[L++]);
		ans[queries[i].id]=Query();
		L=queries[i].l;
		R=queries[i].r;
	}
	for(i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
