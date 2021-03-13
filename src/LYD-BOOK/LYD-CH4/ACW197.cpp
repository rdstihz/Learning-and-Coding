#include <cstdio>

const int maxn = 1000000 + 10;

int prime[maxn], flag[maxn], tot;
int c[maxn];

int main() {
    int x;
    scanf("%d", &x);
    int k = 0;

    for (int i = 2; i <= x; i++) {
        if (!flag[i]) {
            prime[++tot] = i;
        }
        for (int j = 1; j <= tot && i * prime[j] <= x; j++) {
            flag[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i <= tot; i++) {
        int t = x;
        while (t) {
            c[i] += t / prime[i];
            t /= prime[i];
        }
        printf("%d %d\n", prime[i], c[i]);
    }

    return 0;
}