#include <bits/stdc++.h>

using namespace std;

const int maxn = 500;
const int maxm = 30000 + 100;
const int INF = 0x3f3f3f3f;

int from[maxm], to[maxm], cap[maxm], len[maxm];
int fir[maxn], nxt[maxm], tot;

void add(int a, int b, int c, int l) {
    tot++;
    from[tot] = a, to[tot] = b, cap[tot] = c, len[tot] = l;
    nxt[tot] = fir[a], fir[a] = tot;

    tot++;
    from[tot] = b, to[tot] = a, cap[tot] = 0, len[tot] = -l;
    nxt[tot] = fir[b], fir[b] = tot;
}
int n, m, s, t;

long long maxflow, cost;

int d[maxn], pre[maxn];
bool inq[maxn];
bool spfa() {
    memset(d, 0x3f, sizeof(d));
    memset(inq, 0, sizeof(inq));

    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    inq[s] = true;

    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        inq[u] = false;

        for (int e = fir[u]; e; e = nxt[e])
            if (cap[e]) {
                int v = to[e];
                if (d[v] > d[u] + len[e]) {
                    d[v] = d[u] + len[e];
                    pre[v] = e;

                    if (!inq[v]) {
                        Q.push(v);
                        inq[v] = false;
                    }
                }
            }
    }
    return d[t] < INF;
}

void mcmf() {
    maxflow = cost = 0;
    while (spfa()) {
        int f = INF;
        for (int u = t; u != s; u = from[pre[u]])
            f = min(f, cap[pre[u]]);

        maxflow += f;
        cost += (long long)f * d[t];
        for (int u = t; u != s; u = from[pre[u]]) {
            cap[pre[u]] -= f;
            cap[pre[u] ^ 1] += f;
        }
    }
}

int main() {

    scanf("%d%d", &n, &m);
    s = 1, t = n;

    int a, b, c, l;
    tot = 1;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &l);
        add(a, b, c, l);
    }

    mcmf();
    printf("%lld %lld\n", maxflow, cost);

    return 0;
}