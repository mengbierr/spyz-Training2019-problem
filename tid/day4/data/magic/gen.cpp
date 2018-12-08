#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#include<ctime>
#define ll long long
using namespace std;
#define pii pair<int,int>
map<pii,int> mp;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int rando()
{
	return (rand()<<15)|rand();
}
int main()
{
	srand(time(0));
	int n=read(),m=read();
	freopen("magic10.in","w",stdout);
	cout<<n<<' '<<m<<endl;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",rando()%1000000000+1);
	}
	cout<<endl;
	for(int i=1;i<=m;i++)
	{
		int x=rando()%n+1,y=rando()%n+1;
		while(x==y||mp[pii(x,y)]||mp[pii(y,x)])
		{
			x=rando()%n+1;y=rando()%n+1;
		}
		mp[pii(x,y)]=1;
		printf("%d %d %d\n",x,y,rando()%1000000000+1);
	}
}

