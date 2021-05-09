#include <bits/stdc++.h>

using namespace std;

const int maxn = 210;

vector<int> G[maxn];

int n, m;
int match[maxn];
bool vis[maxn];

bool dfs(int u) {

    for (int v : G[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        if (!match[v] || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {

    scanf("%d%d", &n, &m);

    int u, v;
    while (scanf("%d%d", &u, &v) == 2 && u > 0 && v > 0) {
        G[u].push_back(v);
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        memset(vis, false, sizeof(vis));
        if (dfs(i))
            cnt++;
    }
    printf("%d\n", cnt);

    for(int i = m + 1; i <= m + n; i++)
        if(match[i]) {
            printf("%d %d\n", match[i], i);
        }

    return 0;
}