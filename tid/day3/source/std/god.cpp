#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long read()
{
	char ch=getchar();long long f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=f*10*1LL+(long long)(ch-'0');ch=getchar();}
	return f;
}
int rd()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
long long mx(long long x,long long y)
{
	return x>y?x:y;
}
struct segtree
{
	int ls;
	int rs;
	long long sum;
	long long maxx;
	int mark;
}tree[400005];
long long a[100005];int n,m,tot=1;
void build(int p,int l,int r)
{
	int mid=l+r>>1;
	if(l==r)
	{
		tree[p].sum=a[mid];
		tree[p].maxx=a[mid];
		return;
	}
	tree[p].ls=++tot;
	tree[p].rs=++tot;
	build(tree[p].ls,l,mid);
	build(tree[p].rs,mid+1,r);
	tree[p].sum=tree[tree[p].ls].sum+tree[tree[p].rs].sum;
	tree[p].maxx=mx(tree[tree[p].ls].maxx,tree[tree[p].rs].maxx);
}
void modify(int p,int x,int y,int l,int r)
{
	int mid=l+r>>1;
	if(l==r)
	{
		tree[p].sum=tree[p].maxx=a[mid]=(long long)sqrt(a[mid]);
		return;
	}
	else if(x==l&&y==r)
	{
		if(tree[p].maxx>1)
		{
			modify(tree[p].ls,x,mid,l,mid);
			modify(tree[p].rs,mid+1,y,mid+1,r);
		}
	}
	else if(x>mid)
	{
		modify(tree[p].rs,x,y,mid+1,r);
	}
	else if(y<=mid)
	{
		modify(tree[p].ls,x,y,l,mid);
	}
	else
	{
		modify(tree[p].ls,x,mid,l,mid);
		modify(tree[p].rs,mid+1,y,mid+1,r);
	}
	tree[p].sum=tree[tree[p].ls].sum+tree[tree[p].rs].sum;
	tree[p].maxx=mx(tree[tree[p].ls].maxx,tree[tree[p].rs].maxx);
}
long long query(int p,int x,int y,int l,int r)
{
	int mid=l+r>>1;
	if(x==l&&y==r)
	{
		return tree[p].sum;
	}
	if(x>mid)
	return query(tree[p].rs,x,y,mid+1,r);
	else if(y<=mid)
	return query(tree[p].ls,x,y,l,mid);
	else
	return query(tree[p].ls,x,mid,l,mid)+query(tree[p].rs,mid+1,y,mid+1,r);
}
int main()
{
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	build(1,1,n);
	m=rd();
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		x=rd(),y=rd(),z=rd();
		if(y>z)
		{
			int temp=y;
			y=z;
			z=temp;
		}
		if(!x)
		{
			modify(1,y,z,1,n);
		}
		else
		{
			printf("%lld\n",query(1,y,z,1,n));
		}
	}
}

