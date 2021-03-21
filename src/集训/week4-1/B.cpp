#include <cstdio>

const int maxn = 100000000 + 10;
bool flag[maxn];
int prime[6000000];
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int tot = 0;
    for (register int i = 2; i <= n; i++) {
        if (!flag[i]) {
            prime[++tot] = i;
        }
        for (register int j = 1; j <= tot && i * prime[j] <= n; j++) {
            flag[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    
    int x;
    while (q--) {
        scanf("%d", &x);
        printf("%d\n", prime[x]);
    }
    return 0;
}