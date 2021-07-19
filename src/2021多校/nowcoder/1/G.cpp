#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int maxn = 500000 + 100;

PII a[maxn], b[maxn];

bool cmp1(const PII& a, const PII& b) {
    return min(a.first, a.second) < min(b.first, b.second);
}
bool cmp2(const PII& a, const PII& b) {
    return max(a.first, a.second) < max(b.first, b.second);
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].first);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].second);

    if (n == 2) {
        if (k & 1)
            swap(a[1].first, a[2].first);
        printf("%d\n", abs(a[1].first - a[1].second) + abs(a[2].first - a[2].second));
        return 0;
    }

    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(a[i].first - a[i].second);
    }

    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    sort(a + 1, a + 1 + n, cmp1);
    sort(b + 1, b + 1 + n, cmp2);
    int i = n, j = 1;

    while (k--) {
        int d = 2 * min(a[i].first, a[i].second) - 2 * max(b[j].first, b[j].second);
        i--, j++;
        if (d <= 0) break;
        ans += d;
    }
    printf("%lld\n", ans);

    return 0;
}