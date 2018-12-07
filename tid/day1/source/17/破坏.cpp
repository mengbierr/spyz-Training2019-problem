#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct nn{
	int l,next;
	bool t;
};
bool cmp(nn p,nn q){
	if(p.l>q.l) return false;
	return true;
}
int main(){
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	int i,k,no=0,mx=0,s=0;
	double maxn=1,n,non=0;
	nn a[100001];
	scanf("%d",&k);
	n=k*1.0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].l);
		a[i].next=i+1;
		a[i].t=true;
		s+=a[i].l;
	}
	sort(a+2,a+k,cmp);
	k--;
	while(k>=2){
		k--;
		if(a[k].t==false) continue;
		no=0;
		non=0;
    	for(i=k;;i=a[i].next){
      		non++;
      		no+=a[i].l;
       		if((s-no)/(n-non)>=(s-mx)/(n-maxn)){
       		    non--;
       		    no-=a[i].l;
       		    break;
       		}
			mx=no;
			maxn=non;
       	}
	}
	printf("%.3f",(s-mx)/(n-maxn));
}
