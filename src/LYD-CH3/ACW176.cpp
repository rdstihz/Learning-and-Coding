#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int maxn = 1010;
const int maxm = 20015;
const int INF = 0x3f3f3f3f;

int to[maxm], len[maxm];
int fir[maxn], nxt[maxm];
int tot;

void add(int u, int v, int l) {
    tot++;
    to[tot] = v, len[tot] = l;
    nxt[tot] = fir[u], fir[u] = tot;
}
int n, m;
int p[maxn];

int d[maxn][105];

struct Node {
    int u, c;
    int d;
    const bool operator<(const Node& phs) const {
        return d > phs.d;
    }
};

int Dijkstra(int C, int s, int e) {
    memset(d, 0x3f, sizeof d);

    d[s][0] = 0;
    priority_queue<Node> Q;
    Q.push({s, 0, 0});
    while (Q.size()) {
        Node t = Q.top();
        Q.pop();
        if (t.u == e) {
            return t.d;
        }
        if (d[t.u][t.c] < t.d) continue;
        int u = t.u;

        if (t.c < C) {
            d[u][t.c + 1] = d[u][t.c] + p[u];
            Q.push({u, t.c + 1, d[u][t.c + 1]});
        }

        for (int e = fir[u]; e; e = nxt[e]) {
            int v = to[e];
            if (t.c >= len[e] && d[v][t.c - len[e]] > d[u][t.c]) {
                d[v][t.c - len[e]] = d[u][t.c];
                Q.push({v, t.c - len[e], d[v][t.c - len[e]]});
            }
        }
    }
    return INF;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    int q;
    cin >> q;
    int C, s, e;
    while (q--) {
        cin >> C >> s >> e;
        int ans = Dijkstra(C, s, e);
        if (ans == INF) {
            cout << "impossible" << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}