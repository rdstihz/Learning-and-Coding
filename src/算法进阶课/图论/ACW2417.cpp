#include <bits/stdc++.h>

using namespace std;

const int maxn = 120;
const double INF = 1e10;
int n, m;

bool g[maxn][maxn], bg[maxn][maxn];
double d[maxn][maxn], bd[maxn][maxn];
int pre[maxn];
int x[maxn], y[maxn];
bool vis[maxn];
double dist(int a, int b) {
    return sqrt((double)(x[a] - x[b]) * (x[a] - x[b]) + (double)(y[a] - y[b]) * (y[a] - y[b]));
}

void dfs(int u) {
    vis[u] = true;
    for (int i = 1; i <= n; i++)
        if (g[u][i] && !vis[i])
            dfs(i);
}

bool check() {
    memset(vis, 0, sizeof(vis));
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            
            return false;
        }
    return true;
}

int dfn[maxn], low[maxn], ts, st[maxn], top, num, color[maxn];
bool ins[maxn];

void tarjan(int u) {
    dfn[u] = low[u] = ++ts;
    st[++top] = u, ins[u] = true;
    int v = pre[u];
    if (!dfn[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
    } else if (ins[v])
        low[u] = min(low[u], dfn[v]);
    if (dfn[u] == low[u]) {
        int x;
        num++;
        do {
            x = st[top--], ins[x] = false;
            color[x] = num;
        } while (x != u);
    }
}

double solve() {
    double res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j])
                d[i][j] = dist(i, j);
            else
                d[i][j] = INF;

    while (true) {
        for (int i = 1; i <= n; i++) {
            pre[i] = i;
            for (int j = 1; j <= n; j++)
                if (d[pre[i]][i] > d[j][i])
                    pre[i] = j;
        }

        memset(dfn, 0, sizeof(dfn));
        ts = num = 0;
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i);
        if (num == n) {
            for (int i = 2; i <= n; i++)
                res += d[pre[i]][i];
            break;
        }

        //缩点
        for (int i = 2; i <= n; i++)
            if (color[pre[i]] == color[i])
                res += d[pre[i]][i];

        for (int i = 1; i <= num; i++)
            for (int j = 1; j <= num; j++)
                bd[i][j] = INF;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (d[i][j] < INF && color[i] != color[j]) {
                    int a = color[i], b = color[j];
                    if (color[j] == color[pre[j]])
                        bd[a][b] = min(bd[a][b], d[i][j] - d[pre[j]][j]);
                    else
                        bd[a][b] = min(bd[a][b], d[i][j]);
                }
            }

        n = num;
        memcpy(d, bd, sizeof(d));
    }
    return res;
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {

        for (int i = 1; i <= n; i++)
            scanf("%d%d", x + i, y + i);

        memset(g, 0, sizeof(g));
        int a, b;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &a, &b);
            if (a != b && b != 1) g[a][b] = true;
        }
        
        if (!check())
            printf("poor snoopy\n");
        else
            printf("%.2f\n", solve());
    }
    return 0;
}