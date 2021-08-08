#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 10;
int a[maxn], b[maxn];
long long ans;

void mergesort(int l, int r) {
    if (l == r) return;
    int m = l + r >> 1;
    mergesort(l, m);
    mergesort(m + 1, r);
    int i = l, j = m + 1;
    int k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else {
            b[k++] = a[j++];
            ans += m - i + 1;
        }
    }
    while (i <= m)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = b[i];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        ans = 0;
        mergesort(1, n);
        printf("%lld\n", ans);
    }

    return 0;
}