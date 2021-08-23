/*
    Created by rdstihz at 2021-08-16 22:37:55
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
int a[maxn];
vector<int> nums;

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    nums.clear();
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        nums.push_back(a[i]);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[i - 1] + 1)
            cnt++;
    }
    printf("%s\n", cnt <= k ? "Yes" : "No");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}