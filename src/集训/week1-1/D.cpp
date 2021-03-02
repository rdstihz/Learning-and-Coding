#include <iostream>
#include <vector>

using namespace std;

const int maxn = 200000 + 100;
const int P = 10007;
vector<int> G[maxn];
int w[maxn];

int suma[maxn], maxa[maxn]; //孙子节点的权之和和最大子
int sumb[maxn], maxb[maxn]; //儿子节点

int maxv, sumv;

void dfs(int u, int f) {

    for (int v : G[u])
        if (v != f) {

            if (u) {
                sumv = (sumv + w[v] * sumb[u] % P) % P;
                maxv = max(maxv, w[v] * maxb[u]);

                sumb[u] = (sumb[u] + w[v]) % P;
                maxb[u] = max(maxb[u], w[v]);
            }
            if (f) {
                suma[f] = (suma[f] + w[v]) % P;
                maxa[f] = max(maxa[f], w[v]);
            }
            dfs(v, u);
        }
    sumv = (sumv + w[u] * suma[u] % P) % P;
    maxv = max(maxv, w[u] * maxa[u]);
}

int main() {

    int n;
    cin >> n;
    int a, b;

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    dfs(1, 0);
    cout << maxv << " " << 2 * sumv % P << endl;
    return 0;
}