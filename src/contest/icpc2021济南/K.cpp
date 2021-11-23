#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
vector<int> G[maxn];
int ts;
double ans;
void dfs(int u, int f) {
    ans += 1.0 * ts;
    
    for(int v : G[u]) {
        if(v == f) continue;
        ts++;
        dfs(v, u);
        ts++;
    }


}

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        G[i].clear();
    int a, b;
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ans = 0, ts = 0;

    dfs(1, 0);
    printf("%.10f\n", ans / (n - 1));
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--)
        solve();

    return 0;
}