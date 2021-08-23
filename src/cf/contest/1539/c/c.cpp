/*
    Created by rdstihz at 2021-06-20 18:30:42
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 200000 + 100;

LL a[maxn];
int n;
LL k, x;

int main() {

    scanf("%d%lld%lld", &n, &k, &x);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    sort(a + 1, a + 1 + n);

    vector<long long> cut;

    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] > x)
            cut.push_back(a[i] - a[i - 1]);
    }

    sort(cut.begin(), cut.end());
    
    long long ans = cut.size() + 1;
    for (long long cur : cut) {
        if (k < (cur - 1) / x) break;
        k -= (cur - 1) / x;
        ans--;
    }
    printf("%lld\n", ans);
    return 0;
}