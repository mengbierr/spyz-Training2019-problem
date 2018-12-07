#include<bits/stdc++.h>
#define maxn 100005
#define eps 0.001
#define dd double
using namespace std;
dd resum(int st,int end);
void erfen();
int check(dd k);
dd n, a[maxn], ans=9999999, sum, he[maxn];
dd le=0,ri;
//int v=2;
void erfen(){
	  le=0.00;ri=sum/n;
	  while(le+eps<ri){
			dd mid=(le+ri)/2;
			if(check(mid)) {ri=mid;ans=min(ans,mid);}
			else{le=mid;}
			//cout<<le<<"  "<<ri<<"**"<<endl;
	  }
	  return;
}
int check(dd k){
	  for(int v=2;v<n;v++){
			for(int w=v;w<n;w++){
				  if((resum(v,w)/(n-(dd)(abs(w-v)+1)))<=k) {
				  	ri=(resum(v,w)/(n-(dd)(abs(w-v)+1)));
				  	return 1;
				  }
			}
	  }
	  return 0;
}
dd resum(int st,int end){
	  dd ret=0.0000;
	  ret=he[end]-he[st]+a[st];
	  return (sum-ret);
}
int main(){
	  freopen("sabotage.in","r",stdin);
	  freopen("sabotage.out","w",stdout);
	  cin>>n;
	  for(int i=1; i<=n; i++){
			cin>>a[i];
			sum+=a[i];
			he[i]=he[i-1]+a[i];
	  }
	  erfen();
	  printf("%.3f\n",ans);
	  return 0;
}
