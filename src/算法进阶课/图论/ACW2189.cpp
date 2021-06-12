//有源汇上下界最大流

#include <bits/stdc++.h>

using namespace std;

const int maxn = 210;
const int maxm = 30000 + 100;
const int INF = 0x3f3f3f3f;

int to[maxm], cap[maxm], nxt[maxm];
int fir[maxn], cur[maxn], tot;
int A[maxn];

void add_edge(int a, int b, int c) {
    tot++;
    to[tot] = b, cap[tot] = c, nxt[tot] = fir[a], fir[a] = tot;
    tot++;
    to[tot] = a, cap[tot] = 0, nxt[tot] = fir[b], fir[b] = tot;
}

int n, m, s, t;

int dep[maxn], q[maxn], l, r;
bool bfs() {
    memset(dep, 0x3f, sizeof(dep));
    dep[s] = 1;
    l = r = 0;
    q[++r] = s;

    while (l < r) {
        int u = q[++l];
        for (int e = fir[u]; e; e = nxt[e])
            if (cap[e]) {
                int v = to[e];
                if (dep[v] > dep[u] + 1) {
                    dep[v] = dep[u] + 1;
                    q[++r] = v;

                    if (v == t) return true;
                }
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

            if (!k) dep[v] = -1;
        }
    }
    return fl;
}

int Dinic() {
    int res = 0;
    while (bfs()) {
        for (int i = 1; i <= n + 2; i++)
            cur[i] = fir[i];
        res += dfs(s, INF);
    }
    return res;
}

int main() {
    int S, T;
    scanf("%d%d%d%d", &n, &m, &S, &T);
    int a, b, c, d;
    tot = 1;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add_edge(a, b, d - c);
        A[a] -= c, A[b] += c;
    }

    int fullflow = 0;
    s = n + 1, t = n + 2;

    for (int i = 1; i <= n; i++) {
        if (A[i] > 0) {
            add_edge(s, i, A[i]);
            fullflow += A[i];
        } else if (A[i] < 0) {
            add_edge(i, t, -A[i]);
        }
    }

    add_edge(T, S, INF);

    if(Dinic() != fullflow) puts("No Solution");
    else{
        s = S, t = T;
        int res = cap[tot];
        cap[tot] = cap[tot - 1] = 0;
        printf("%d\n", res + Dinic());
    }
    return 0;
}