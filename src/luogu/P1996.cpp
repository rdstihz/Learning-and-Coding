#include <cstdio>

const int maxn = 300;

int del[maxn];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    int t = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            t = (t + 1) % n;
            while(del[t]) t = (t + 1) % n;
        }
        del[t] = 1;
        printf("%d ",t + 1);
    }

    return 0;
}