/*
    Created by rdstihz at 2021-06-20 18:50:10
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 100000 + 100;

typedef pair<LL, LL> PII;
PII a[maxn];

int main() {

    int n;
    scanf("%d", &n);


    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &a[i].second, &a[i].first);

    sort(a + 1, a + 1 + n);

    int i = 1, j = n;
    long long ans = 0;
    long long cnt = 0;
    while (i <= j) {
        while (i <= j && a[i].first <= cnt) {
            ans += a[i].second;
            cnt += a[i].second;
            i++;
        }
        while (i <= j && a[i].first > cnt) {
            LL k = min(a[j].second, a[i].first - cnt);
            ans += 2 * k;
            cnt += k;
            if (k == a[j].second) j--;
            else a[j].second -= k;
        }
    }

    printf("%lld\n", ans);

    return 0;
}