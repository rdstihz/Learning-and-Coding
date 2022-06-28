#include <bits/stdc++.h>
using namespace std;
int read() {
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
int len[105];
char s[105][105];
char tmp[6000005];
int all = 0, vis[20000];
int cnt[20000], sum = 0;
void add(int x) {
    x = tmp[x];
    if (cnt[x] == 0) ++sum;
    ++cnt[x];
}
void sub(int x) {
    x = tmp[x];
    --cnt[x];
    if (cnt[x] == 0) --sum;
}
int main() {
    freopen("in", "r", stdin);
    freopen("ans", "w", stdout);
    int T = read();
    while (T--) {
        all = 0;
        for (char c = 'a'; c <= 'z'; c++)
            vis[c] = 0;
        int n = read();
        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i]);
            len[i] = strlen(s[i]);
            for (int j = 0; j < len[i]; j++) {
                if (!vis[s[i][j]]) {
                    vis[s[i][j]] = 1;
                    ++all;
                }
            }
        }
        int now = 1;
        for (int i = 1; i <= n; i++)
            now = now / __gcd(now, len[i]) * len[i];
        int tot = 0;
        for (int i = 0; i < now * 2; i++) {
            for (int j = 1; j <= n; j++) {
                tmp[++tot] = s[j][i % len[j]];
            }
        }
        sum = 0;
        for (char c = 'a'; c <= 'z'; c++)
            cnt[c] = 0;
        int l = 0, ans = tot;
        int r = 0;
        while (sum < all)
            add(++r);
        for (; r <= tot;) {
            while (sum == all)
                sub(++l);
            ans = min(ans, r - l + 1);
            add(++r);
        }
        printf("%d\n", ans);
    }
    return 0;
}
