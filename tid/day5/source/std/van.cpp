#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int ch[4000005][2],w[4000005],n,m,rt,tot,size,sz;
void add(int &p,int l,int r,int x)
{
	if(!p) p=++sz;
	if(l==r)
	{
		if(!w[p]) w[p]++,size++;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) add(ch[p][0],l,mid,x);
	else add(ch[p][1],mid+1,r,x);
	w[p]=w[ch[p][1]]+w[ch[p][0]];
}
void del(int p,int l,int r,int x)
{
	if(l==r)
	{
		if(w[p]) w[p]--,size--;
		return;
	}
	if(!p) return;
	if(!w[p]) return;
	int mid=l+r>>1;
	if(x<=mid) del(ch[p][0],l,mid,x);
	else del(ch[p][1],mid+1,r,x);
	w[p]=w[ch[p][1]]+w[ch[p][0]];
}
int qmin(int p,int l,int r)
{
	int mid=l+r>>1;
	if(!w[p]) return -1;
	if(l==r)
	{
		return l;
	}
	if(w[ch[p][0]]) return qmin(ch[p][0],l,mid);
	else return qmin(ch[p][1],mid+1,r);
}
int qmax(int p,int l,int r)
{
	if(!w[p]) return -1;
	int mid=l+r>>1;
	if(l==r) return l;
	if(w[ch[p][1]]) return qmax(ch[p][1],mid+1,r);
	else return qmax(ch[p][0],l,mid);
}
int check(int p,int l,int r,int x)
{
	if(l==r)
	{
		//cout<<l<<" "<<w
		if(w[p]) return 1;
		else return -1;
	}
	if(!p) return -1;
	if(!w[p]) return -1;
	int mid=l+r>>1;
	//cout<<l<<" "<<r<<" "<<w[p]<<endl;
	if(x<=mid) return check(ch[p][0],l,mid,x);
	return check(ch[p][1],mid+1,r,x);
}
int before(int p,int l,int r,int x)
{
	if(x<0) return -1;
	if(!w[p]) return -1;
	if(l==r) return l;
	int mid=l+r>>1;
	if(x<=mid) return before(ch[p][0],l,mid,x);
	else
	{
		int tmp=before(ch[p][1],mid+1,r,x);
		if(tmp==-1) return qmax(ch[p][0],l,mid);
		return tmp;
	}
}
int last(int p,int l,int r,int x)
{
	if(x>n) return -1;
	if(!w[p]) return -1;
	if(l==r) return l;
	int mid=l+r>>1;
	if(x>mid) return last(ch[p][1],mid+1,r,x);
	else
	{
		int tmp=last(ch[p][0],l,mid,x);
		if(tmp==-1) return qmin(ch[p][1],mid+1,r);
		else return tmp;
	}
}
int main()
{
	freopen("van.in","r",stdin);
	freopen("van.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int op=read(),x;
		if(op==1)
		{
			x=read();
			add(rt,0,n,x);
		}
		else if(op==2)
		{
			x=read();
			del(rt,0,n,x);
		}
		else if(op==3)
		{
			printf("%d\n",qmin(1,0,n));
		}
		else if(op==4)
		{
			printf("%d\n",qmax(1,0,n));
		}
		else if(op==5)
		{
			x=read();
			printf("%d\n",before(1,0,n,x-1));
		}
		else if(op==6)
		{
			x=read();
			printf("%d\n",last(1,0,n,x+1));
		}
		else
		{
			x=read();
			printf("%d\n",check(1,0,n,x));
		}
	}
}

