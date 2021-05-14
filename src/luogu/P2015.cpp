#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int maxn = 110;
vector<PII> G[maxn];
int n, m;

int f[maxn][maxn];

void dfs(int u, int fa, int d) {

    f[u][1] = d;

    for (auto e : G[u]) {
        int v = e.first;
        if (v == fa) continue;
        dfs(v, u, e.second);

        for (int j = m; j >= 2; j--) {
            for (int k = 0; k < j; k++)
                f[u][j] = max(f[u][j], f[u][j - k] + f[v][k]);
        }
    }
}

int main() {
    cin >> n >> m;
    m++;
    int a, b, c;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    dfs(1, -1, 0);

    cout << f[1][m] << endl;

    return 0;
}