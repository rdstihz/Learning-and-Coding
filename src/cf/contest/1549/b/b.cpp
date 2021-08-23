/*
    Created by rdstihz at 2021-08-18 14:36:46
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 200000 + 100;
bool used[maxn];
char s1[maxn], sn[maxn];
void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        used[i] = 0;

    scanf("%s", s1 + 1);
    scanf("%s", sn + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (sn[i] == '1') {
            if (i > 1 && s1[i - 1] == '1' && !used[i - 1]) {
                ans++;
                used[i - 1] = true;
            } else if (s1[i] == '0' && !used[i]) {
                ans++;
                used[i] = true;
            } else if (i < n && s1[i + 1] == '1' && !used[i + 1]) {
                ans++;
                used[i + 1] = true;
            }
        }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}