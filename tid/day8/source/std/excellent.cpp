#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
typedef long long ll;
const int N=2e6+10;
char s[N];
int n,m,rk[N],height[N],sa[N],w[N],cas,dp[N][21],lg[N];
int f[N],g[N];
inline int qpow(int a)
{
    return 1<<a;
}
inline bool pan(int *x,int i,int j,int k)
{
    int ti=i+k<n?x[i+k]:-1;
    int tj=j+k<n?x[j+k]:-1;
    return ti==tj&&x[i]==x[j];
}
void SA_init()
{
    int *x=rk,*y=height,r=256;
    for(int i=0; i<r; i++)w[i]=0;
    for(int i=0; i<n; i++)w[s[i]]++;
    for(int i=1; i<r; i++)w[i]+=w[i-1];
    for(int i=n-1; i>=0; i--)sa[--w[s[i]]]=i;
    r=1;
    x[sa[0]]=0;
    for(int i=1; i<n; i++)
        x[sa[i]]=s[sa[i]]==s[sa[i-1]]?r-1:r++;
    for(int k=1; r<n; k<<=1)
    {
        int yn=0;
        for(int i=n-k; i<n; i++)y[yn++]=i;
        for(int i=0; i<n; i++)
            if(sa[i]>=k)y[yn++]=sa[i]-k;
        for(int i=0; i<r; i++)w[i]=0;
        for(int i=0; i<n; i++)w[x[y[i]]]++;
        for(int i=1; i<r; i++)w[i]+=w[i-1];
        for(int i=n-1; i>=0; i--)sa[--w[x[y[i]]]]=y[i];
        swap(x,y);
        r=1;
        x[sa[0]]=0;
        for(int i=1; i<n; i++)
            x[sa[i]]=pan(y,sa[i],sa[i-1],k)?r-1:r++;
    }
}
inline void height_init()
{
    int i,j,k=0;
    for(int i=1; i<=n; i++)rk[sa[i]]=i;
    for(int i=0; i<n; i++)
    {
        if(k)k--;
        j=sa[rk[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[rk[i]]=k;
    }
}
void st_init()
{
    for(int i=1; i<=n; i++)
    {
        dp[i-1][0]=height[i];
        lg[i]=lg[i-1];
        if((1<<lg[i]+1)==i)lg[i]++;
    }
    for(int j=1; j<=lg[n]; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(i+qpow(j)-1>=n)break;
            dp[i][j]=min(dp[i][j-1],dp[i+qpow(j-1)][j-1]);
        }
    }
}
int lcp(int a,int b)
{
    int l=rk[a],r=rk[b];
    if(r<l)swap(l,r);
    l--;
    r--;
    if(r<0)return 0;
    l++;
    int len=r-l+1;
    int k=lg[len];
    int h=qpow(k);
    return min(dp[l][k],dp[r-h+1][k]);
}
int main()
{
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
    scanf("%d",&cas);
    while(cas--)
    {
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        cin>>s;
        m=strlen(s),n=2*m+1;
        s[m]='$';
        for(int i=m+1; i<n; i++)
        {
            s[i]=s[n-i-1];
        }
        s[n++]=0;
        SA_init();
        n--;
        height_init();
        st_init();
        for(int l=1; l<=m/2; l++)
        {
            for(int i=0,j=l; j<m; i+=l,j+=l)
            {
                int p=min(l,lcp(i,j));
                int s=min(l,lcp(n-i-1,n-j-1));
                if(p+s-1>=l)
                {
                    f[j-s+l]++;
                    f[j+p]--;
                    g[i-s+1]++;
                    g[i+p-l+1]--;
                }
            }
        }
        ll ans=0;
        for(int i=1; i<m; i++)
        {
            f[i]+=f[i-1];
            g[i]+=g[i-1];
        }
        for(int i=0; i<m-1; i++)
        {
            ans+=(ll)f[i]*g[i+1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
