#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define M 50000+5
#define ll long long
bool vis[M],DDF[M];
ll n,m,tat,top,col_num,dfn_num,ans;
ll dfn[M],low[M],stack[M],head[M],color[M],point[M];
struct e
{
    ll to;
    ll next;
}
e[M];
void add(ll x,ll y)
{
    tat++;
    e[tat].to=y;
    e[tat].next=head[x];
    head[x]=tat;
}
void tarjan(ll x)
{
    dfn[x]=low[x]=++dfn_num;
    vis[x]=true;
    stack[++top]=x;
    for(ll i=head[x];i!=0;i=e[i].next)
    {
        ll temp=e[i].to;
        if(!dfn[temp])
        {
            tarjan(temp);
            low[x]=min(low[x],low[temp]);
        }
        else if(vis[temp])
        low[x]=min(low[x],dfn[temp]);
    }
    if(dfn[x]==low[x])
    {
        vis[x]=false;
        color[x]=++col_num;
        point[color[x]]++;
        while(stack[top]!=x)
        {
            color[stack[top]]=col_num;
            vis[stack[top--]]=false;
            point[color[x]]++;
        }
        top--;
    }
    return;
}
int main()
{
	freopen("cow.in","r",stdin);
	freopen("cow.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=m;i++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        add(x,y);
    }
    for(ll i=1;i<=n;i++)
    {
        if(!dfn[i])
        tarjan(i);
    }
    for(int i=1;i<=n;i++)
    {
        //if(DDF[color[i]]==1) continue;
        for(int j=head[i];j!=0;j=e[j].next)
        {
            int temp=e[j].to;
            if(color[i]!=color[temp])
            {
                DDF[color[i]]=1;
                //break;
            }
        }
    }
    for(int i=1;i<=col_num;i++)
    {
        if(DDF[i]==0)
        {
            if(ans)
            {
                cout<<0;
                return 0;
            }
            else ans=point[i];
        }
    }
    cout<<ans;
    return 0;
}
