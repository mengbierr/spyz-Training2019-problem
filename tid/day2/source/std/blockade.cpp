#include <cstdio>
#include <algorithm>
 
using namespace std;
 
typedef long long LL;
 
const int maxn = 100005, maxm = 500005;
 
int n, m, head[maxn], cnt, size[maxn], dfn[maxn], low[maxn], clo;
LL ans[maxn];
 
struct _edge {
    int v, next;
} g[maxm << 1];
 
inline int iread() {
    int f = 1, x = 0; char ch = getchar();
    for(; ch < '0' || ch > '9'; ch = getchar()) f = ch == '-' ? -1 : 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
    return f * x;
}
 
inline void add(int u, int v) {
    g[cnt] = (_edge){v, head[u]};
    head[u] = cnt++;
}
 
inline void tarjan(int x) {
    int sum = 0;
    dfn[x] = low[x] = ++clo;
    size[x] = 1;
    for(int i = head[x]; ~i; i = g[i].next) {
        int v = g[i].v;
        if(!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
            size[x] += size[v];
            if(low[v] >= dfn[x]) {
                ans[x] += (LL)sum * size[v];
                sum += size[v];
            }
        }
        else low[x] = min(low[x], dfn[v]);
    }
    ans[x] += (LL)sum * (n - sum - 1);
    ans[x] <<= 1;
}
 
int main() {
	freopen("blockade.in","r",stdin);
	freopen("blockade.out","w",stdout);
    n = iread(); m = iread();
    for(int i = 1; i <= n; i++) head[i] = -1; cnt = 0;
 
    for(int i = 1; i <= m; i++) {
        int u = iread(), v = iread();
        add(u, v); add(v, u);
    }
    
    tarjan(1);
 
    for(int i = 1; i <= n; i++) printf("%lld\n", ans[i] + (n - 1) * 2);
    return 0;
}
