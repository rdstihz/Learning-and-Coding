/*
    Created by rdstihz at 2021-08-29 22:40:40
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 100000 + 100;
int a[maxn];
void solve() {
    int n;
    scanf("%d", &n);
    int tot = 0;
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        a[i] %= 2;
        tot += a[i];
        if (a[i])
            nums.push_back(i);
    }

    if (n % 2 == 0) {
        if (tot != n / 2) {
            printf("-1\n");
            return;
        }

        LL res = 0;
        for (int i = 1; i <= n; i += 2)
            res += abs(nums[i / 2] - i);
        LL ans = res;
        res = 0;
        for (int i = 2; i <= n; i += 2)
            res += abs(nums[i / 2 - 1] - i);
        ans = min(ans, res);
        printf("%lld\n", ans);
    } else {
        if (tot == n / 2) { //奇数放偶数位
            LL res = 0;
            for (int i = 2; i <= n; i += 2)
                res += abs(nums[i / 2 - 1] - i);
            printf("%lld\n", res);
        } else {
            LL res = 0;
            for (int i = 1; i <= n; i += 2)
                res += abs(nums[i / 2] - i);
            printf("%lld\n", res);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}