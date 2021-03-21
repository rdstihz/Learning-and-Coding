#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000 + 10;

vector<int> G[maxn];
bool vis[maxn];

int n, m;
//true :山谷
//false:山顶
bool dfs(int u) {
    vis[u] = true;

    int ts = 0, fs = 0;
    for (int v : G[u])
        if (!vis[v]) {
            if (dfs(v))
                ts++;
            else
                fs++;
        }

    vis[u] = false;

    if (!(ts || fs)) { //无法再动
        if (u <= n)
            return false;
        else
            return true;
    }

    if (u <= n && ts || u > n && !fs) { //当前在山顶，可以到达山谷
        return true;
    }
    if (u > n && fs || u <= n && !ts) { //当前在山谷，可以到达山顶
        return false;
    }
}

int main() {

    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        v += n;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));

        bool ans = dfs(i);

        if (ans) {
            cout << "Ni" << endl;
        } else {
            cout << "Cong" << endl;
        }
    }

    return 0;
}