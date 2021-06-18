#include <bits/stdc++.h>

using namespace std;

const int maxn = 10100;
const int maxm = 4000000;
const int INF = 0x3f3f3f3f;

int N;
int n, m, k;
int s, t;
int p[25], r[25];
int site[25][20];

int to[maxm], cap[maxm], nxt[maxm];
int fir[maxn], cur[maxn], tot;

void add_edge(int a, int b, int c) {
    tot++;
    to[tot] = b, cap[tot] = c, nxt[tot] = fir[a], fir[a] = tot;
    tot++;
    to[tot] = a, cap[tot] = 0, nxt[tot] = fir[b], fir[b] = tot;
}

void add_day(int d) {
    //飞船
    for (int i = 1; i <= m; i++) {
        int a = site[i][(d + r[i] - 1) % r[i]];
        int b = site[i][d % r[i]];
        add_edge((d - 1) * N + a, d * N + b, p[i]);
    }

    //停留
    for (int i = 0; i <= n + 1; i++)
        add_edge((d - 1) * N + i, d * N + i, INF);

    //到达终点
    add_edge(d * N + n + 1, t, INF);
}

int dep[maxn], q[maxn];
bool bfs() {
    memset(dep, 0x3f, sizeof(dep));
    int l = 0, r = 0;
    dep[s] = 1;
    q[++r] = s;
    cur[s] = fir[s];
    while (l < r) {
        int u = q[++l];
        for (int e = fir[u]; e; e = nxt[e])
            if (cap[e]) {
                int v = to[e];
                if (dep[v] > dep[u] + 1) {
                    cur[v] = fir[v];
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
    int flow = 0;
    for (int e = cur[u]; e && rest; e = nxt[e]) {
        cur[u] = e;
        int v = to[e];
        if (dep[v] == dep[u] + 1 && cap[e]) {
            int k = dfs(v, min(rest, cap[e]));
            flow += k, rest -= k;
            cap[e] -= k, cap[e ^ 1] += k;

            if (!k) dep[v] = -1;
        }
    }
    return flow;
}

int Dinic() {
    int res = 0;
    while (bfs()) {
        res += dfs(s, INF);
    }
    return res;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= m; i++) {
        scanf("%d%d", p + i, r + i);
        for (int j = 0; j < r[i]; j++) {
            scanf("%d", &site[i][j]);
            if (site[i][j] < 0)
                site[i][j] = n + 1;
        }
    }

    tot = 1;
    N = n + 2;

    //第i天j号点  i * N + j
    s = 999, t = 1000;
    add_edge(s, 0, k);
    add_edge(n + 1, t, INF);
    int day = 0;
    while (k) {

		if(day > 700) {
			day = 0;
			break;
		}

        add_day(++day);
        k -= Dinic();
    }
    printf("%d\n", day);
    return 0;
}
