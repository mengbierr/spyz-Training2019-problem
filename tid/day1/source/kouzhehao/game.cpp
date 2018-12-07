#include<iostream>
#include<cstdio>
using namespace std;
bool d[200][200][200];
int t,q1[100001],q2[100001],q3[100001],h1[100001],w,h2[100001],h3[100001],n,k[200][200][200];
int ans=-1e9-7,a[101],b[101],c[101];
void bfs(int num,int jd)
{
	if(jd==1&&num==n/2+1) 
	{
		for(int i=1;i<=t;i++)
		{
			if(q1[i]<=q2[i]&&q1[i]<=q3[i]) 
			{
			    d[0][q2[i]-q1[i]][q3[i]-q1[i]]=1;	
			    k[0][q2[i]-q1[i]][q3[i]-q1[i]]=max(k[0][q2[i]-q1[i]][q3[i]-q1[i]],q1[i]);
			}
			else if(q2[i]<=q1[i]&&q2[i]<=q3[i]) 
			{
				d[q1[i]-q2[i]][0][q3[i]-q2[i]]=1;
			    k[q1[i]-q2[i]][0][q3[i]-q2[i]]=max(k[q1[i]-q2[i]][0][q3[i]-q2[i]],q2[i]);
			}
			else 
			{
				d[q1[i]-q3[i]][q2[i]-q3[i]][0]=1;
			    k[q1[i]-q3[i]][q2[i]-q3[i]][0]=max(k[q1[i]-q3[i]][q2[i]-q3[i]][0],q3[i]);
			}
		}
		return;
	}
	if(num==n+1)
	{
		for(int i=1;i<=t;i++)
		{
			if(q1[i]>=q2[i]&&q1[i]>=q3[i])
			{
				if(d[0][q1[i]-q2[i]][q1[i]-q3[i]])
				{
					ans=max(ans,k[0][q1[i]-q2[i]][q1[i]-q3[i]]+q1[i]);
					
					w=1;
				}
			}
			else if(q2[i]>=q1[i]&&q2[i]>=q3[i])
			{
				if(d[q2[i]-q1[i]][0][q2[i]-q3[i]])
				{
					ans=max(ans,k[q2[i]-q1[i]][0][q2[i]-q3[i]]+q2[i]);
					w=1;
				}
			}
			else if(q3[i]>=q2[i]&&q3[i]>=q1[i])
			{
				if(d[q3[i]-q1[i]][q3[i]-q2[i]][0])
				{
					ans=max(ans,k[q3[i]-q1[i]][q3[i]-q2[i]][0]+q3[i]);
					w=1;
				}
			}
		}
		return;
	}
	int t1=t;
	t=0;
	for(int i=1;i<=t1;i++)
	{
		t++;
		h1[t]=q1[i]+a[num];
		h2[t]=q2[i]+b[num];
		h3[t]=q3[i];
		t++;
		h1[t]=q1[i]+a[num];
		h2[t]=q2[i];
		h3[t]=q3[i]+c[num];
		t++;
		h1[t]=q1[i];
		h2[t]=q2[i]+b[num];
		h3[t]=q3[i]+c[num];
	}
	for(int i=1;i<=t;i++) 
	{
		q1[i]=h1[i],q2[i]=h2[i],q3[i]=h3[i];
	}
	bfs(num+1,jd);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	t=1;
	bfs(1,1);
	t=1;
	q1[1]=0;
	q2[1]=0;
	q3[1]=0;
	bfs(n/2+1,2);
	if(w==1)
	cout<<ans;
	else cout<<"Impossible";
}
