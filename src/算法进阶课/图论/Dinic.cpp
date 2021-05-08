#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10000 + 10;
const int maxm = 200000 + 20;
const int INF = 0x3f3f3f3f;

int fir[maxn], nxt[maxm], tot;
int to[maxm], cap[maxm];
int cur[maxn]; //用于当前弧优化

int q[maxn];
int dep[maxn];

int n, m, s, t;

void add(int u, int v, int c) {
    tot++;
    to[tot] = v, cap[tot] = c;
    nxt[tot] = fir[u], fir[u] = tot;
}

bool bfs() {
    memset(dep, 0, sizeof(dep));

    dep[s] = 1;
    int l, r;
    l = r = 0;
    q[++r] = s;

    while (l < r) {
        int u = q[++l];
        for (int e = fir[u], v = to[e]; e; e = nxt[e], v = to[e])
            if (cap[e] && !dep[v]) {
                dep[v] = dep[u] + 1;
                q[++r] = v;

                if (v == t) return true;
            }
    }
    return false;
}

int dfs(int u, int rest) {
    if (u == t) return rest;

    int fl = 0;
    for (int e = cur[u]; e && rest; e = nxt[e]) {
        cur[u] = e;

        int v = to[e];
        if (cap[e] && dep[v] == dep[u] + 1) {
            int k = dfs(v, min(rest, cap[e]));

            fl += k, rest -= k;
            cap[e] -= k, cap[e ^ 1] += k;

            if (!k) dep[v] = -1; // v不可能拓展， 删除v
        }
    }
    return fl;
}

int Dinic() {
    int res = 0;
    while (bfs()) {
        //重置当前弧
        for(int i = 1; i <= n; i++) 
            cur[i] = fir[i];
        
        res += dfs(s, INF);
    }
    return res;
}

int main() {

    scanf("%d%d%d%d", &n, &m, &s, &t);
    int u, v, c;

    tot = 1; //边从2开始编号
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c);
        add(v, u, 0);
    }

    printf("%d\n", Dinic());

    return 0;
}