#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int T,x,y;
int prime[1000002],tot=0;bool check[60000002];
void pre()
{
	for(int i=2;i<=1000000;i++)
	{if(!check[i])
	prime[tot++]=i;
	for(int j=0;j<tot;j++)
		{if(i*prime[j]>1000000)
		break;
		check[i*prime[j]]=1;
		if(i%prime[j]==0)
		break;
		}
	}
}
int rando()
{
	return (rand()<<15)|rand();
}
void make_rand()
{
	printf("%d %d\n",rand()%x+1,rand()%y+1);
}
void make_ok()
{
	int x1=rand()%10+1,x2=rand()%10+1;
	printf("%d %d\n",x1*x2*x2,x2*x1*x1);
}
void make_spe1()
{
	int x1=rand()%10+1;
	printf("%d %d\n",x1*x1*x1,x1*x1*x1);
}
void make_fail()
{
	int x1=rand()%5+1;
	printf("%d %d\n",x1*x1*x1*x1,x1*x1*x1*x1);
}
void make_fail2()
{
	int x1=rand()%7+1,x2=rand()%7+1;
	printf("%d %d\n",x1*x2*x2*2,x2*x1*x1);
}
void make_same_prime()
{
	if(rand()&1) printf("998244353 998244353\n");
	else printf("999999937 999999937\n");
}
void make_d_prime()
{
	if(rand()&1) printf("998244353 999999937\n");
	else printf("999999937 998244353\n");
}
void make_cbr()
{
	int x=prime[rand()%150];
	printf("%d %d\n",x,x*x*x);
}
void make_sqr()
{
	int x=prime[rand()%3300];
	printf("%d %d\n",x,x*x);
}
int ppow(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1) ret=ret*x;
		y>>=1;
		x=x*x;
	}
	return ret;
}
void make_rando()
{
	printf("%d %d\n",rando()%x+1,rando()%y+1);
}
void make_spe2()
{
	int x=prime[rand()%11+160],y=prime[rand()%10+150];
	printf("%d %d\n",x*y*y,y*x*x);
}
void make_spe3()
{
	int x=prime[rand()%160],y=prime[rand()%160];
	printf("%d %d\n",x*y*y,y*x*x);
}
int main()
{
	srand(time(NULL));
	pre();
	//cout<<prime[160];
	T=read(),x=read(),y=read();
	freopen("game10.in","w",stdout);
	printf("%d\n",T);
	for(int i=1;i<=T;i++)
	{
		int op=rand()%10+1;
		if(op<=1) make_rand();
		else if(op<=4) make_ok();
		else if(op<=6) make_spe1();
		else if(op<=8) make_fail();
		else make_fail2();
		/*if(op<=1) make_d_prime();
		else if(op<=3) make_same_prime();
		else if(op<=4) make_rando();
		else if(op<=6) make_spe2();
		else if(op<=8) make_ok();
		else  make_spe3();*/
	}
}

