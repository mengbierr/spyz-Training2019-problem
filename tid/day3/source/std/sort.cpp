#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
int n,m,a[100005],pla;
bool now[100005];
struct data
{
	int l;
	int r;
	int op;
}q[100005];
struct segtree
{
	int ls;
	int rs;
	int sum;
	int mark;
}tree[400005];
int tot=1;
void build(int p,int l,int r)
{
	int mid=l+r>>1;
	if(l==r)
	{
		tree[p].sum=now[mid];
		tree[p].mark=-1;
		return;
	}
	tree[p].mark=-1;
	tree[p].ls=++tot;
	tree[p].rs=++tot;
	build(tree[p].ls,l,mid);
	build(tree[p].rs,mid+1,r);
	tree[p].sum=tree[tree[p].ls].sum+tree[tree[p].rs].sum;
}
int query(int p,int l,int r,int x,int y)
{
	int mid=l+r>>1;
	if(l==x&&r==y)
	{
		return tree[p].sum;
	}
	if(tree[p].mark!=-1)
	{
		tree[tree[p].ls].mark=tree[tree[p].rs].mark=tree[p].mark;
		tree[tree[p].ls].sum=(mid-l+1)*tree[p].mark;
		tree[tree[p].rs].sum=(r-mid)*tree[p].mark;
		tree[p].mark=-1;
	}
	if(y<=mid) return query(tree[p].ls,l,mid,x,y);
	else if(x>mid) return query(tree[p].rs,mid+1,r,x,y);
	else return query(tree[p].ls,l,mid,x,mid)+query(tree[p].rs,mid+1,r,mid+1,y);
}
void modify(int p,int l,int r,int x,int y,int k)
{
	if(y<x) return;
	int mid=l+r>>1;
	if(l==x&&r==y)
	{
		
		tree[p].sum=(r-l+1)*k;
		tree[p].mark=k;
		return;
	}
	if(tree[p].mark!=-1)
	{
		tree[tree[p].ls].mark=tree[tree[p].rs].mark=tree[p].mark;
		tree[tree[p].ls].sum=(mid-l+1)*tree[p].mark;
		tree[tree[p].rs].sum=(r-mid)*tree[p].mark;
		tree[p].mark=-1;
	}
	if(y<=mid) modify(tree[p].ls,l,mid,x,y,k);
	else if(x>mid) modify(tree[p].rs,mid+1,r,x,y,k);
	else
	{
		modify(tree[p].ls,l,mid,x,mid,k);
		modify(tree[p].rs,mid+1,r,mid+1,y,k);
	}
	tree[p].sum=tree[tree[p].ls].sum+tree[tree[p].rs].sum;
}
bool check(int x)
{
	for(int i=1;i<=n;i++)
	{
		now[i]=(a[i]>=x)?1:0;
	}tot=1;
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int temp=query(1,1,n,q[i].l,q[i].r);
		if(q[i].op==0)
		{
			modify(1,1,n,q[i].r-temp+1,q[i].r,1);
			modify(1,1,n,q[i].l,q[i].r-temp,0);
		}
		else
		{
			modify(1,1,n,q[i].l,q[i].l+temp-1,1);
			modify(1,1,n,q[i].l+temp,q[i].r,0);
		}
	}
	return query(1,1,n,pla,pla);
}
int main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++)
	{
		q[i].op=read();q[i].l=read();q[i].r=read();
	}
	int l=1,r=n,ans;
	pla=read();
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
}

