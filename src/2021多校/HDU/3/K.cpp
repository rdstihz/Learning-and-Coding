#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL n, k;
unordered_map<LL, LL> mp;
LL dfs(LL n) {
    if (n <= k) return 1;
    if (mp.count(n)) return mp[n];
    return mp[n] = dfs(n / 2) + dfs(n - n / 2) + 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        mp.clear();
        scanf("%lld%lld", &n, &k);
        printf("%lld\n", dfs(n));
    }

    return 0;
}