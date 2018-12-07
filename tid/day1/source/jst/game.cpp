#include<bits/stdc++.h>
using namespace std;
int h=0,a[30],b[30],c[30],n,kk=0,f[30][5][5],x=1,y=2,z=3,zz=0;
long long sum1,sum2,sum3,ma,aaa;
void enter()
{
	if(h==1&&zz==1&&f[h][x][y]==1&&f[h][x][z]==1&&f[h][y][z]==1)return;
	if(h==1&&zz==0)zz=1;
	if(h<n)h++;
	if(f[h][x][y]==0)
	{
		f[h][x][y]=1;
		sum1+=a[h];
		sum2+=b[h];
		enter();
	}
	else if(f[h][x][z]==0)
	{
		f[h][x][z]=1;
		sum1+=a[h];
		sum3+=c[h];
		enter();
	}
	else if(f[h][y][z]==0)
	{
		f[h][y][z]=1;
		sum2+=b[h];
		sum3+=c[h];
		if(h==n)
		{
			if(sum1==sum2==sum3)
			{
				kk=1;
				if(sum1>ma)ma=sum1;
			}
		}
	}
	f[h+1][x][y]=0;
	f[h+1][x][z]=0;
	f[h+1][y][z]=0;
}
int main()
{
	int i,j,k;
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	enter();
	if(kk==0)cout<<"Impossible";
	if(kk==1)cout<<ma;
	return 0;
}
