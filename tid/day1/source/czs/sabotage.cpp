#include<cstdio>
using namespace std;
const int inf=2e9;
int n,f,e,k[111111];
double a,sf,se,as,asf,ase,aaf,aae,anf,ane;
int main(void)
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",k+i),as+=k[i];
	asf=ase=as/n,anf=1,ane=n;
	for(double i=2;i<n;i++)
	{
		sf+=k[int(i)];
		if(sf/(i-1)<asf)
		anf=i,aaf=sf,asf=sf/(i-1);
	}
	for(int i=n-1;i>anf+1;i--)
	{
		se+=k[int(i)];
		if(se/(n-i)<ase)
		ane=i,aae=se,ase=se/(i-1);
	}
	a=(aaf+aae+k[1]+k[n])/(n-ane+anf+1);
	printf("%.3lf",a);
	return 0;
}
