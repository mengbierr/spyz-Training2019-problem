#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
  
#define rep(i, n) for(int i = 0; i < n; i++)
#define clr(x, c) memset(x, c, sizeof(x))
  
using namespace std;
 
const int maxn = 100009;
const double eps = 1e-3;
 
int A[maxn], n, sum;
double B[maxn], T[maxn];
 
bool check(double m) {
    double p = 0, B, mx = -1e10;
    for(int i = 1; i < n - 1; i++) {
        B = A[i] - m;
        if(p >= 0) B += p;
        mx = max(mx, p = B);
    }
    return sum - n * m - mx <= 0;
}
 
int main() {
    
    freopen("sabotage.in","r",stdin);
    freopen("sabotage.out","w",stdout);
    cin >> n;
    sum = 0;
    rep(i, n) {
        scanf("%d", A + i);
        sum += A[i];
    }
    double L = 1, R = 10000;
    while(R - L >= eps) {
        double m = L + (R - L) / 2;
        check(m) ? R = m : L = m;
    }
    printf("%.3lf\n", (L + R) / 2);
    
    return 0;
}
