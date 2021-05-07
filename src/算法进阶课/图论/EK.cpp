#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1010;
const int maxm = 20000;
const int INF = 0x3f3f3f3f;

int from[maxm], to[maxm], cap[maxm];
int fir[maxn], nxt[maxm];
int tot;

void add(int u, int v, int c) {
    tot++;
    from[tot] = u;
    to[tot] = v;
    cap[tot] = c;

    nxt[tot] = fir[u];
    fir[u] = tot;
}

int n, m, s, t;

int pre[maxn], flow[maxn];
bool vis[maxn];
int q[maxn], l, r;

bool bfs() {
    memset(vis, false, sizeof vis);

    flow[s] = INF;
    vis[s] = true;

    l = r = 0;
    q[++r] = s;

    while (l < r) {
        int u = q[++l];
        if (u == t) return true;
        for (int e = fir[u]; e; e = nxt[e])
            if (cap[e] > 0) {
                int v = to[e];
                if (!vis[v]) {
                    flow[v] = min(flow[u], cap[e]);
                    q[++r] = v;
                    vis[v] = true;
                    pre[v] = e;
                }
            }
    }
    return false;
}

int EK() {
    int res = 0;

    while (bfs()) {
        int k = flow[t];
        res += k;

        for (int u = t; u != s; u = from[pre[u]]) {
            cap[pre[u]] -= k;
            cap[pre[u] ^ 1] += k;
        }
    }
    return res;
}

int main() {

    scanf("%d%d%d%d", &n, &m, &s, &t);

    int u, v, w;
    tot = 1;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, 0);
    }

    printf("%d\n", EK());

    return 0;
}