#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
int main() 
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout); 
	int n; scanf("%d", &n); 
	while(n--)
	{
		int a, b;
		a=read();b=read();
		int c = cbrt((long double) a * b);
		int x = a / c, y = b / c;
		bool flag = (x * x * y == a) && (y * y * x == b);
		puts(flag ? "Yes" : "No");
	}
}
