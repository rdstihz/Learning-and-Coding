#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;

int a[2][maxn], b[maxn];

int n;
bool check() {
    int ep = n;
    double totk = 0;
    int tot = 0;
    while (ep--) {
        int x = rand() % n + 1, y = rand() % n + 1;
        if (a[0][x] == a[0][y]) continue;
        totk += 1.0 * (b[y] - b[x]) / (a[0][y] - a[0][x]);
        tot++;
    }
    LL mk = (LL)(totk / tot);
    //printf("%lld\n", mk);
    for (LL k = mk - 200; k <= mk + 200; k++) {

        LL minb = -1e9, maxb = 1e9;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            minb = max(minb, b[i] - k * a[0][i] - 10);
            maxb = min(maxb, b[i] - k * a[0][i] + 10);
            if (minb > maxb) {
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }

    return false;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[0][i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[1][i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    if (check())
        printf("1\n");
    else
        printf("2\n");
}

int main() {
    srand((unsigned)time(NULL));
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}

/*
2
10
37510 58209 74944 59230 781640 6286 20899 86280 34825 34211
3 14159 26535 89793 23846 26433 83279 50288 41971 69399
37520 58200 74934 59240 781650 6276 20889 86276 34820 34220
10
3 14159 26535 89793 23846 26433 83279 50288 41971 69399
37510 58209 74944 59230 781640 6286 20899 86280 34825 34211
37520 58200 74934 59240 781650 6276 20889 86276 34820 34220
*/