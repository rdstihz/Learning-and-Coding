/*
    Created by rdstihz at 2021-07-26 21:38:41
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
const int maxm = 600000 + 100;
const int INF = 0x3f3f3f3f;

int to[maxm], cap[maxm], len[maxm], nxt[maxm];
int fir[maxn], tot = 1;
int dis[maxn], incf[maxn], inq[maxn], pre[maxn];
int n, m, s, t;
int S, T;

void add_edge(int a, int b, int c, int d) {
    tot++;
    to[tot] = b, cap[tot] = c, len[tot] = d, nxt[tot] = fir[a], fir[a] = tot;
    tot++;
    to[tot] = a, cap[tot] = 0, len[tot] = -d, nxt[tot] = fir[b], fir[b] = tot;
}

bool spfa() {
    queue<int> Q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0, incf[s] = INF, incf[t] = 0;
    Q.push(s), inq[s] = true;
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for (int e = fir[u]; e; e = nxt[e]) {
            int v = to[e];
            if (cap[e] && dis[v] > dis[u] + len[e]) {
                dis[v] = dis[u] + len[e];
                incf[v] = min(incf[u], cap[e]);
                pre[v] = e;
                if (!inq[v]) {
                    Q.push(v);
                    inq[v] = false;
                }
            }
        }
    }
    return incf[t] > 0;
}

void MCMF(int& flow, int& cost) {
    flow = cost = 0;
    while (spfa()) {
        flow += incf[t], cost += incf[t] * dis[t];
        for (int u = t; u != s; u = to[pre[u] ^ 1]) {
            cap[pre[u]] -= incf[t];
            cap[pre[u] ^ 1] += incf[t];
        }
    }
}

int edge[100000];

int main() {
    scanf("%d%d", &n, &m);
    S = 2 * n + 1, T = 2 * n + 2;
    s = 2 * n + 3, t = 2 * n + 4;

    //原图中的边
    for (int i = 1; i <= n; i++)
        add_edge(S, i, INF, 0);
    for (int i = 1; i <= n; i++)
        add_edge(n + i, T, INF, 0);
    add_edge(T, S, INF, 0);

    int u, v, w;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        edge[i] = tot + 1;
        add_edge(u, n + v, 1, w);
    }

    //下界
    for (int i = 1; i <= n; i++)
        add_edge(s, i, 1, 0);
    for (int i = 1; i <= n; i++)
        add_edge(n + i, t, 1, 0);

    int cost, flow;
    MCMF(flow, cost);
    //printf("%d\n", flow);
    if (flow < n) {
        printf("-1\n");
    } else {
        printf("%d\n", cost);
        vector<int> ans;
        for (int i = 1; i <= m; i++) {
            if (cap[edge[i]] == 0) {
                ans.push_back(i);
            }
        }
        printf("%d ", ans.size());
        for (int v : ans)
            printf("%d ", v);
    }
    return 0;
}