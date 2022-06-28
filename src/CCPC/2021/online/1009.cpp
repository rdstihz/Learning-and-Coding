#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int maxn = 100000 + 100;
char s[maxn];

int S1[maxn], S2[maxn];
map<PII, int> cnt;

void solve() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    long long ans = 0;
    cnt.clear();
    cnt[make_pair(0, 0)] = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R')
            S1[i] = S1[i - 1] + 1;
        else if (s[i] == 'L')
            S1[i] = S1[i - 1] - 1;
        else
            S1[i] = S1[i - 1];

        if (s[i] == 'U')
            S2[i] = S2[i - 1] + 1;
        else if (s[i] == 'D')
            S2[i] = S2[i - 1] - 1;
        else
            S2[i] = S2[i - 1];

        ans += cnt[make_pair(S1[i], S2[i])];
        cnt[make_pair(S1[i], S2[i])]++;
    }

    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}