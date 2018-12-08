#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[2][100005],mod=1000000007;
int main()
{
    int n,k;
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<2;i++)
    {
        f[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(j-i>=0)
            f[i%2][j]=((f[i%2^1][j]+f[i%2][j-1]-f[i%2^1][j-i])%mod+mod)%mod;
            else
            f[i%2][j]=(f[i%2^1][j]+f[i%2][j-1])%mod;
        }
    }
    printf("%d",f[n%2][k]);
}
