#include<cstdio>
#include<algorithm>
using namespace std;
typedef float F;
int a[10000];
F b[10000];
int main(){
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		a[i]+=a[i-1];
	}
	F ans=-1;
	for(int i=2;i<n;i++){
		for(int j=i;j<n;j++){
			if(ans==-1)ans=(F)(sum-a[j]+a[i-1])/(n-j+i-1);
			else ans=min(ans,(F)(sum-a[j]+a[i-1])/(n-j+i-1));
		}
	}
	printf("%.3f",ans);
	return 0;
}
