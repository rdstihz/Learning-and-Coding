#include <bits/stdc++.h>

using namespace std;

const int maxn = 210;
const int maxm = 10500 * 2;
const int INF = 0x3f3f3f3f;

int to[maxm], cap[maxm];
int nxt[maxm], fir[maxn], cur[maxn], tot;

int low[maxm];
int A[maxm];

int n, m, s, t;

void add_edge(int a, int b, int c) {
    tot++;
    to[tot] = b, cap[tot] = c, nxt[tot] = fir[a], fir[a] = tot;
    tot++;
    to[tot] = a, cap[tot] = 0, nxt[tot] = fir[b], fir[b] = tot;
}

int dep[maxn];
bool bfs() {
    memset(dep, 0x3f, sizeof(dep));
    dep[s] = 1;
    queue<int> Q;
    Q.push(s);

    while (Q.size()) {
        int u = Q.front();
        Q.pop();

        for (int e = fir[u]; e; e = nxt[e])
            if (cap[e]) {
                int v = to[e];
                if (dep[v] > dep[u] + 1) {
                    dep[v] = dep[u] + 1;
                    Q.push(v);

                    if (v == t) return true;
                }
            }
    }
    return false;
}

int dfs(int u, int rest) {
    if (u == t) return rest;

    int flow = 0;
    for (int e = cur[u]; e && rest; e = nxt[e]) {
        cur[u] = e;

        int v = to[e];
        if (cap[e] && dep[v] == dep[u] + 1) {
            int k = dfs(v, min(rest, cap[e]));
            flow += k, rest -= k;
            cap[e] -= k, cap[e ^ 1] += k;

            if (!k) dep[v] = -1;
        }
    }
    return flow;
}

int Dinic() {

    int flow = 0;
    while (bfs()) {
        for (int i = 1; i <= n; i++)
            cur[i] = fir[i];
        flow += dfs(s, INF);
    }
    return flow;
}

int main() {

    scanf("%d%d", &n, &m);

    tot = 1; //边从2开始编号
    int a, b, c, d;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add_edge(a, b, d - c);
        low[i] = c;
        A[a] -= c, A[b] += c;
    }

    s = n + 1, t = n + 2;
    n += 2;

    int fullflow = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] > 0) {
            fullflow += A[i];
            add_edge(s, i, A[i]);
        } else if (A[i] < 0) {
            add_edge(i, t, -A[i]);
        }
    }

    if (Dinic() == fullflow) {
        printf("YES\n");
        for (int i = 1; i <= m; i++)
            printf("%d\n", cap[2 * i + 1] + low[i]);
        printf("\n");
    } else {
        printf("NO\n");
    }

    return 0;
}