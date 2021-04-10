#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 2147483647;
const int maxn = 210;
const int maxm = 10000 + 10;

int from[maxm], to[maxm], cap[maxm], flow[maxm];
int fir[maxn], nxt[maxm];
int tot;

void add(int u, int v, int c, int f) {
    tot++;
    from[tot] = u;
    to[tot] = v;
    cap[tot] = c;
    flow[tot] = f;

    nxt[tot] = fir[u];
    fir[u] = tot;

}


int a[maxn], p[maxn];
long long maxFlow;

void EK(int s, int t) {
    while (true) {
        memset(a, 0, sizeof(a));
        a[s] = INF;
        queue<int> Q;
        Q.push(s);

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int e = fir[u]; e; e = nxt[e]) {
                int v = to[e];
                if (!a[v] && cap[e] > flow[e]) {
                    a[v] = min(a[u], cap[e] - flow[e]);
                    p[v] = e;
                    Q.push(v);
                }
            }
            if (a[t]) break;
        }
        if (!a[t]) break;

        for (int u = t; u != s; u = from[p[u]]) {
            flow[p[u]] += a[t];
            flow[p[u] ^ 1] -= a[t];
        }
        maxFlow = maxFlow + a[t];
    }


}

int main() {
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    tot = 1;
    int u, v, c;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c, 0);
        add(v, u, 0, 0);
    }

    maxFlow = 0;
    EK(s, t);
    printf("%lld\n", maxFlow);

    return 0;
}