#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
int a[maxn], maxv[maxn];
int q[maxn];

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    maxv[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
        maxv[i] = max(maxv[i + 1], a[i]);

    for (int i = 1; i <= n; i++) {
        q[i] = i;
    }
    sort(q + 1, q + 1 + n, cmp);

    while (m--) {
        int k;
        scanf("%d", &k);

        int i, j = n;
        long long ans = 0;
        for (int e = 1; e <= n; e++) {
            i = q[e];
            while (j > i && maxv[j] <= a[i] + k)
                j--;
            if (maxv[j] > a[i] + k) ans += n - j + 1;
        }
        printf("%lld\n", ans);
    }

    return 0;
}