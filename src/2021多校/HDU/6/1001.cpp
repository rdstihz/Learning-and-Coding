#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e7 + 10;
int primes[5000000 + 100], tot;
bool flag[maxn];

void init() {
    int N = 20000000;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            primes[++tot] = i;
        }
        for (int j = 1; j <= tot && i * primes[j] <= N; j++) {
            flag[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        int x;
        scanf("%d", &x);

        int ans = 1e9;

        if (x > 1 && !flag[x]) { //x是质数
            printf("%d\n", 1);
            continue;
        }

        // r - l + 1 = 2
        if (2 * x + 1 > 1 && !flag[2 * x + 1] || 2 * x - 1 > 1 && !flag[2 * x - 1]) {
            printf("2\n");
            continue;
        }

        int l, r;

        // l + r = 1
        int t = max(x, 1 - x);
        r = lower_bound(primes + 1, primes + 1 + tot, t) - primes;
        r = primes[r];
        ans = min(ans, 2 * r);

        // l + r = 2
        t = max(x, 2 - x);
        r = lower_bound(primes + 1, primes + 1 + tot, 2 * t - 1) - primes;
        r = primes[r];
        ans = min(ans, r);

        if (ans >= 1e9)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}