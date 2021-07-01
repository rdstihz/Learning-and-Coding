#include <bits/stdc++.h>

using namespace std;

const int maxn = 210;

vector<int> G[maxn];

int n, m;
int match[maxn];
bool vis[maxn];
int a[maxn], b[maxn];

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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", b + i);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (gcd(a[i], b[j]) > 1)
                G[i].push_back(j + n);
        }
    }
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        memset(vis, false, sizeof(vis));
        if (dfs(i))
            cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}