#include <bits/stdc++.h>

using namespace std;

map<string, int> M;

char s[100];
int cnt[10];

int main() {
    int n;
    scanf("%d", &n);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        if (!strcmp(s, "c")) {
            cnt[1]++;
        } else if (!strcmp(s, "a")) {
            cnt[2]++;
        } else if (!strcmp(s, "t")) {
            cnt[3]++;
        } else if (!strcmp(s, "ca")) {
            cnt[4]++;
        } else if (!strcmp(s, "at")) {
            cnt[5]++;
        } else if (!strcmp(s, "cat")) {
            ans++;
        }
    }

    int k = min(cnt[1], cnt[5]);
    ans += k;
    cnt[1] -= k, cnt[5] -= k;

    k = min(cnt[3], cnt[4]);
    ans += k;
    cnt[3] -= k, cnt[4] -= k;

    ans += min(min(cnt[1], cnt[2]), cnt[3]);

    printf("%d\n", ans);

    return 0;
}