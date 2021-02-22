#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

const int maxn = 100000 + 10;

int a[maxn];
vector<int> G[maxn];
int n;

LL ans;

LL dfs(int u, int f) {
    LL val = a[u];

    for (auto v : G[u])
        if (v != f) {
            LL t = dfs(v, u);
            if (t >= 0) val += t;
        }
    ans = max(ans, val);
    return val;
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ans = 0;
    dfs(1, 0);

    cout << ans << endl;

    return 0;
}
