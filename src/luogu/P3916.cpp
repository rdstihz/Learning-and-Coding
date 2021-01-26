/*

#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100000 + 100;

vector<int> G[maxn];

int low[maxn];

void dfs(int u, int f) {
    low[u] = f;

    for (int v : G[u]) {
        if (!low[v])
            dfs(v, f);
    }

}

int main() {

    int n, m;
    cin >> n >> m;

    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        G[v].push_back(u);
    }

    for (int i = n; i >= 1; i--) {
        if (!low[i]) {
            dfs(i, i);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << low[i] << " ";
    cout << endl;

    return 0;
}

 */


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 100000 + 100;

vector<int> G[maxn];
stack<int> S;
int n, m;

int dfn[maxn], t;
int low[maxn];
int ans[maxn];

void dfs(int u) {
    dfn[u] = low[u] = ++t;
    ans[u] = u;
    S.push(u);
    for (int v: G[u]) {
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
        ans[u] = max(ans[u], ans[v]);
    }

    if (low[u] == dfn[u]) {
        while (S.top() != u) {
            ans[S.top()] = ans[u];
            S.pop();
        }
        S.pop();
    }

}

int main() {

    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!low[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}