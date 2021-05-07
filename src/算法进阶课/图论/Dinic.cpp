#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10000 + 10;
const int maxm = 200000 + 100;
const int INF = 0x3f3f3f3f;

int to[maxm], cap[maxm];
int nxt[maxm], fir[maxn];
int tot;

int n, m, s, t;

int dep[maxn];
int q[maxn], l, r;

void add(int u, int v, int w) {
    tot++;
    to[tot] = v;
    cap[tot] = w;
    nxt[tot] = fir[u];
    fir[u] = tot;
}

//bfs建分层图
bool bfs() {
    memset(dep, 0, sizeof(dep));
    dep[s] = 1;
    l = r = 0;
    q[++r] = s;

    while (l < r) {
        int u = q[++l];

        if (u == t) return true;

        for (int e = fir[u]; e; e = nxt[e])
            if (cap[e]) {
                int v = to[e];
                if (!dep[v]) {
                    dep[v] = dep[u] + 1;
                    q[++r] = v;
                }
            }
    }
    return false;
}

int dfs(int u, int rest) {
    if (u == t) return rest;

    int f = 0;

    for (int e = fir[u]; e; e = nxt[e])
        if (dep[to[e]] == dep[u] + 1 && cap[e] > 0) {
            int v = to[e];
            int k = dfs(v, min(rest, cap[e]));

            f += k;
            cap[e] -= k;
            cap[e ^ 1] += k;
            rest -= k;

            if (!k) dep[v] = -1; //v不可能拓展
        }

    if (rest) dep[u] = -1; //u不可能拓展
    return f;
}

int Dinic() {
    int res = 0;
    while (bfs()) {
        res += dfs(s, INF);
    }
    return res;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);

    int u, v, w;
    tot = 1; //边从2开始编号
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, 0);
    }

    printf("%d\n", Dinic());

    return 0;
}