#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 150;
int a[maxn];
int ans[maxn];
int n;

bool dfs(int d, int maxd) {
    if (d == maxd) return a[d] == n;

    bool vis[maxn];
    memset(vis, 0, sizeof(vis));

    for (int i = d; i >= 1; i--)
        for (int j = i; j >= 1; j--)
            if (!vis[a[i] + a[j]] && a[i] + a[j] > a[d] && a[i] + a[j] <= n) {
                vis[a[i] + a[j]] = true;
                a[d + 1] = a[i] + a[j];
                if (dfs(d + 1, maxd)) return true;
            }
    return false;
}

int main() {
    while (scanf("%d", &n), n) {

        a[1] = 1;
        for (int d = 1;; d++) {
            
            if (dfs(1, d)) {
                for (int i = 1; i <= d; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;
            }
        }
    }

    return 0;
}