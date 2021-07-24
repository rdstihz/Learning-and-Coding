#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int maxn = 5010;
int n, m, a, b, c, d, p;
long long V;

int w[maxn][maxn];
int dis[maxn * 2];
bool vis[maxn * 2];
int nxt() {
    V = (V * V * b + V * c + d) % p;
    return V;
}

int main() {
    scanf("%d%d%d%d%d%d%d", &n, &m, &a, &b, &c, &d, &p);
    V = a;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            w[i][j] = nxt();

    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> Q;
    Q.push(make_pair(0, 1));
    int mst = 0;
    while (Q.size()) {
        int u = Q.top().second;
        Q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        mst += dis[u];
        if (u <= n) {
            for (int v = 1; v <= m; v++)
                if (!vis[n + v] && dis[n + v] > w[u][v]) {
                    dis[n + v] = w[u][v];
                    Q.push(make_pair(dis[n + v], n + v));
                }
        } else {
            for (int v = 1; v <= n; v++)
                if (!vis[v] && dis[v] > w[v][u - n]) {
                    dis[v] = w[v][u - n];
                    Q.push(make_pair(dis[v], v));
                }
        }
    }
    printf("%d\n", mst);
    return 0;
}