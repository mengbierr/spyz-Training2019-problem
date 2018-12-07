/*有N 台机器，第i 台机器的工作能力为Ai。破坏一些机器，使得工作效率变低。任意选取一段编号连续的机器，使它们停止工作。
这样的破坏一次，而且无法破坏第一台或最后一台机器。请问让剩下机器的工作效率的平均数最小？至少必须破坏一台机器。
【输入格式】
从文件sabotage. in 中读入数据。输入数据第一行是1 个整数N第二行N 个整数，第i 个数Ai
【输出格式】
输出到文件sabotage. out 中。输出数据为一行，最小平均效率，保留到小数点后3 位
【样例1 输入】
5
5 1 7 8 2
【样例1 输出】
2.667
Ps:对于40% 的数据，N<=1000,对于100% 数据，N<=100000 Ai <= 10000*/
#include<bits/stdc++.h>
#define rg register
using namespace std;
int n,a[100001];
double ba(int x,int y)
{
	double sum=0;
	for(rg int i=1;i<x;i++) sum+=a[i];
	for(rg int i=y+1;i<=n;i++) sum+=a[i];
	return sum/(n-(y-x+1));
}
int main()
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	double ans=10001;
	scanf("%d",&n);
	for(rg int i=1;i<=n;i++) scanf("&d",&a[i]);
	for(rg int i=2;i<n;i++)
	for(rg int j=i;j<n;j++) if(ba(i,j)<ans) ans=ba(i,j);
	printf("%.3lf\n",ans);
}
