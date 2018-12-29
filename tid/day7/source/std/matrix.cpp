#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define mod 1000000007
#define int long long
using namespace std;
inline int read(){
    int f=1,ans=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
    return f*ans;
}
const int MAXN=501;
int a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN],n,p,m;
bool st;
signed main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read(),p=read(),m=read();
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=p;j++) a[i][j]=read(),a[i][j]=(a[i][j]%mod+mod)%mod;
	for(int i=1;i<=p;i++)
	    for(int j=1;j<=m;j++) b[i][j]=read(),b[i][j]=(b[i][j]%mod+mod)%mod;
	for(int i=1;i<=n;i++)for(int k=1;k<=p;k++)for(int j=1;j<=m;j++)
	    
	         c[i][j]+=(a[i][k]*b[k][j]),c[i][j]%=mod;
	for(int i=1;i<=n;i++){
		if(st) printf("\n");
		for(int j=1;j<m;j++) printf("%lld ",c[i][j]%mod);
		printf("%lld",c[i][m]%mod);
		st=1;
	}
}
