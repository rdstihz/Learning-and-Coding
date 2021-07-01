#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 100000 + 100;

int pre[maxn];
int last[maxn];
int sum[maxn];

int main() {

    int n, q;
    scanf("%d%d", &n, &q);

    int x;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);

        for (int j = 2; j * j <= x; j++) {

            if (x % j == 0) {
                pre[i] = max(pre[i], last[j] + 1);
                last[j] = i;

                while (x % j == 0) {
                    x /= j;
                }
            }
        }
        if (x > 1) {
            pre[i] = max(pre[i], last[x] + 1);
            last[x] = i;
        }
    }

    for (int i = 2; i <= n; i++) {
        pre[i] = max(pre[i], pre[i - 1]);
    }

    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[pre[i] - 1] + 1;
    }

    int l, r;
    while (q--) {
        scanf("%d%d", &l, &r);

        if (pre[l] == l) {
            printf("%d\n", sum[r] - sum[l - 1]);
        } else {
            printf("%d\n", sum[r] - sum[pre[l]]);
        }
    }

    return 0;
}