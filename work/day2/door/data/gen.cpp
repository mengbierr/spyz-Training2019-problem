#include<bits/stdc++.h>
using namespace std;
vector<int> v[100005];
bool vis[100005];
int x[100005],y[100005];
int main()
{
    srand(time(0));
    int T=5;
    freopen("10.in","w",stdout);
    int n=100000,m=99998;
    cout<<T<<endl;
    while(T--)
    {
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            x[i]=rand()%m+1,y[i]=rand()%m+1;
            while(x[i]==y[i])
            {
                y[i]=rand()%m+1;
            }
            v[x[i]].push_back(i);
            v[y[i]].push_back(i);
        }
        for(int tt=1;tt<=500000;tt++)
        {
            int num=rand()%m+1;
            for(int j=0;j<v[num].size();j++)
            {
                vis[v[num][j]]^=1;
            }
        }
        if(rand()%2==0)
        {
            cerr<<"No"<<endl;
            for(int tt=1;tt<=10;tt++)
            {
                vis[rand()%n+1]^=1;
            }
        }
        else cerr<<"Yes"<<endl;
        cout<<n<<" "<<m<<endl;
        for(int i=1;i<=n;i++)
        cout<<(vis[i]^1)<<" ";
        cout<<endl;
        for(int i=1;i<=m;i++)
        {
            printf("%d ",v[i].size());
            for(int j=0;j<v[i].size();j++)
            printf("%d ",v[i][j]);
            cout<<endl;
        }
    }
}