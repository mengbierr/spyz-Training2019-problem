#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
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
int n,m;
int main()
{
	srand(time(0));
	cin>>n>>m;
	freopen("magic10.in","w",stdout);
	
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",rando()%1000000000+1);
	}
	cout<<endl;
	for(int i=1;i<=m;i++)
	{
		int l=rando()%n+1,r=rando()%n+1;
		while(l>r)
		{
			l=rando()%n+1,r=rando()%n+1;
		}
		int op=rand()%2+1;
		cout<<op<<" ";
		if(op==1)
		{
			int x=rando()%1000000000+1;printf("%d %d %d\n",l,r,x);
		}
		else printf("%d %d\n",l,r);
	}
	
}

