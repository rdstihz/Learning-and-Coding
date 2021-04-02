#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int maxn = 100000 + 100;
typedef pair<int, double> Edge;

vector<Edge> G[maxn];

double d[maxn];
bool vis[maxn];

double dfs(int u) {

    if (vis[u])
        return d[u];

    d[u] = 0;
    vis[u] = true;

    for (auto e : G[u]) {
        double t = dfs(e.first) + e.second;
        d[u] += t / G[u].size();
    }
    return d[u];
}

int main() {

    int n, m;

    cin >> n >> m;
    int u, v;
    double w;

    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
    }

    dfs(1);
    cout << fixed;
    cout << setprecision(2);
    cout << d[1] << endl;
    
    
    return 0;
}