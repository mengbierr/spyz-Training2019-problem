#include<cstdio>
#include<algorithm>
using namespace std;double ans;
int A,B,C,n,m,a[100005],i;
int main()
{
    freopen("magic2.in","r",stdin);
    freopen("magic2.ans","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) scanf("%d",&a[i]);
    for (i=1; i<=m; i++)
    {
        scanf("%d%d%d",&A,&B,&C);
        ans=max(ans,(a[A]+a[B])/(C+0.0));
    }
    printf("%.2f\n",ans);
    return 0;
}
