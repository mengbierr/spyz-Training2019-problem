#include<bits/stdc++.h>
using namespace std;
int mx[4]={0,1,1,2};
int my[4]={0,2,3,3};
int n,scor[4],a[100][4];
bool ok=false;
int dp=-1;
int vis[150];
int now;
void dfs(int cnt){
	if(cnt==now+1){
		if(scor[2]==scor[3]&&scor[2]==scor[1]&&scor[2]!=0){
			ok=true;
		}
		return;
	}
	if(scor[2]==scor[3]&&scor[2]==scor[1]&&scor[2]!=0){
			dp=max(dp,cnt);
	}
	for(int v=1;v<=n;v++){
		if(!vis[v]){
			vis[v]=1;
			for(int w=1;w<=3;w++){
				int aa=a[v][mx[w]];
				int bb=a[v][my[w]];
			    scor[mx[w]]+=aa;	
				scor[my[w]]+=bb;
				dfs(cnt+1);
				if(ok) return;
				scor[mx[w]]-=aa;
				scor[my[w]]-=bb;
		    }
		    vis[v]=0;
		}
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=3;j++)
	cin>>a[i][j];
	for(int i=n;i>=1;i--){
		if(i==dp){cout<<i<<endl;return 0;}
		now=i;
		dfs(1);
		if(ok==true){cout<<i<<endl; return 0;}
	}
	cout<<"Impossible"<<endl;
	return 0;
}
