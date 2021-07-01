#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 10;
const int maxm = 22000000 + 100;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, PII> PIII;

const LL INF = 0x3f3f3f3f3f3f3f3f;

int u[maxn * 2], v[maxn * 2], w[maxn * 2];

PII to[maxm];
int val[maxm];
int fir[maxn][55], nxt[maxm];
int tot;
bool vis[maxn][55];

void add(int u, int w1, int v, int w2, int w) {
    tot++;
    to[tot] = make_pair(v, w2);
    val[tot] = w;

    nxt[tot] = fir[u][w1];
    fir[u][w1] = tot;
}

LL d[maxn][55];
priority_queue<PIII, vector<PIII>, greater<PIII>> Q;
void Dijkstra() {
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    d[1][0] = 0;
    Q.push(make_pair(0, make_pair(1, 0)));

    while (Q.size()) {
        PII node = Q.top().second;
        Q.pop();
        int u = node.first;
        int was = node.second;
        if (vis[u][was]) continue;
        vis[u][was] = true;

        for (int e = fir[u][was]; e; e = nxt[e]) {
            PII v = to[e];
            if (d[v.first][v.second] > d[u][was] + val[e]) {
                d[v.first][v.second] = d[u][was] + val[e];
                Q.push(make_pair(d[v.first][v.second], v));
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        add(u[i], 0, v[i], w[i], 0);
        add(v[i], 0, u[i], w[i], 0);
        vis[u[i]][w[i]] = vis[v[i]][w[i]] = true;
    }
    for (int i = 1; i <= m; i++) {
        for (int k = 1; k <= 50; k++) {
            if (vis[u[i]][k]) {
                add(u[i], k, v[i], 0, (k + w[i]) * (k + w[i]));
            }
            if (vis[v[i]][k]) {
                add(v[i], k, u[i], 0, (k + w[i]) * (k + w[i]));
            }
        }
    }

    Dijkstra();

    for (int i = 1; i <= n; i++) {
        if (d[i][0] == INF)
            cout << -1 << " ";
        else
            cout << d[i][0] << " ";
    }

    return 0;
}