#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 5010;
const int maxm = 100000 + 100;
const int INF = 0x3f3f3f3f;

int from[maxm], to[maxm], flow[maxm], len[maxm];
int fir[maxn], nxt[maxm];
int tot;


void add(int u, int v, int c, int l) {
    tot++;
    from[tot] = u;
    to[tot] = v;
    flow[tot] = c;
    len[tot] = l;

    nxt[tot] = fir[u];
    fir[u] = tot;

}


LL maxFlow, cost;

bool inq[maxn];
int d[maxn];
int p[maxn];

bool SPFA(int s, int t) {
    memset(d, 0x3f, sizeof(d));
    memset(inq, 0, sizeof(inq));
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    inq[s] = true;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        inq[u] = false;

        for (int e = fir[u]; e; e = nxt[e])
            if (flow[e] > 0) {
                int v = to[e];
                if (d[v] > d[u] + len[e]) {
                    d[v] = d[u] + len[e];
                    p[v] = e;
                    if (!inq[v]) {
                        inq[v] = true;
                        Q.push(v);
                    }
                }
            }

    }

    return d[t] < INF;
}

void update(int s, int t) {
    int a = INF;
    for (int u = t; u != s; u = from[p[u]]) {
        a = min(a, flow[p[u]]);
    }

    for (int u = t; u != s; u = from[p[u]]) {
        flow[p[u]] -= a;
        flow[p[u] ^ 1] += a;
    }

    maxFlow += a;
    cost += a * d[t];

}

void MCMF(int s, int t) {
    while (SPFA(s, t)) {
        update(s, t);
    }
}

int main() {
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);

    int u, v, c, l;
    tot = 1;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &u, &v, &c, &l);
        add(u, v, c, l);
        add(v, u, 0, -l);
    }

    maxFlow = cost = 0;

    MCMF(s, t);

    printf("%lld %lld\n", maxFlow, cost);

    return 0;
}

//4 5 4 3
//4 2 30 2
//4 3 20 3
//2 3 20 1
//2 1 30 9
//1 3 40 5

//50 280