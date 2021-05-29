#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;

int p[maxn];
int d[maxn];
bool vis[maxn];

int dfs(int u, int dep) {
    vis[u] = true;

    if (vis[p[u]]) {
        d[u] = dep;
        return dep;
    }

    d[u] = dfs(p[u], dep + 1);
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        memset(vis, 0, sizeof(vis));

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i, 1);
        }

        for (int i = 1; i <= n; i++)
            cout << d[i] << " ";
        cout << endl;
    }

    return 0;
}