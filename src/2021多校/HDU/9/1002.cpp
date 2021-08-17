#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
const int INF = 0x3f3f3f3f;
int a[maxn];
int n, m;
long long k;
int id(int i, int j) {
    return (i - 1) * m + j;
}
int main() {

    //freopen("/home/rdstihz/HDU9/2021“MINIEYE杯”中国大学生算法设计超级联赛（9）/02/input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%lld", &n, &m, &k);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[(id(i, j))]);
            }
        }
        int ans;
        if (k == 1) {
            ans = a[id(1, 1)];
            for (int j = 1; j <= m; j++)
                ans = max(ans, a[id(1, j)]);
        } else if (k % 2 == 1) {
            ans = INF;
            for (int i = 1; i <= n; i++) {
                int t = 0;
                for (int j = 1; j <= m; j++)
                    t = max(t, a[id(i, j)]);
                ans = min(ans, t);
            }
        } else {
            ans = 0;
            for (int j = 1; j <= m; j++) {
                int t = INF;
                for (int i = 1; i <= n; i++)
                    t = min(t, a[id(i, j)]);
                ans = max(ans, t);
            }
        }
        ans = max(ans, a[id(1, 1)]);
        printf("%d\n", ans);
    }

    return 0;
}