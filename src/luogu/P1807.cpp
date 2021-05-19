#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000;
const int maxm = 50000 + 100;
const int INF = 0x3f3f3f3f;

int ind[maxn];

int to[maxm], len[maxm], nxt[maxm], fir[maxn], tot;

int seq[maxn], cnt;
int d[maxn];

void add(int u, int v, int w) {
    tot++;
    to[tot] = v, len[tot] = w, nxt[tot] = fir[u], fir[u] = tot;
}

int main() {

    int n, m;
    cin >> n >> m;

    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        add(u, v, w);
        ind[v]++;
    }
    queue<int> Q;

    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            Q.push(i);
            seq[++cnt] = i;
        }
        d[i] = -INF;
    }

    while (Q.size()) {
        int u = Q.front();
        Q.pop();

        for (int e = fir[u]; e; e = nxt[e]) {
            int v = to[e];
            ind[v]--;
            if (ind[v] == 0) {
                Q.push(v);
                seq[++cnt] = v;
            }
        }
    }

    d[1] = 0;
    for (int i = 1; i <= cnt; i++) {
        int u = seq[i];
        for (int e = fir[u]; e; e = nxt[e]) {
            int v = to[e];
            d[v] = max(d[v], d[u] + len[e]);
        }
    }
    if (d[n] == -INF) {
        cout << -1 << endl;
    } else {
        cout << d[n] << endl;
    }
    return 0;
}