#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int a[maxn];
int n, m;

bool check(LL x) {
    int cnt = 1;
    LL cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += a[i];
        if (cur > x) {
            cur -= x;
            cnt++;
        }
    }
    return cnt <= m;
}

int main() {

    scanf("%d%d", &n, &m);

    LL l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        r += a[i];
        l = max(l, (LL)a[i]);
    }

    LL m;
    while (l < r) {
        m = l + r >> 1;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }

    int cnt = 1;
    LL cur = 0;
    for (int i = 1; i <= n; i++) {
        if (cur + a[i] <= l) {
            printf("1 %d %lld %lld\n", cnt, cur, cur + a[i]);
        } else {
            printf("2 %d %lld %lld %d %lld %lld\n", cnt + 1, 0, a[i] - (l - cur), cnt, cur, l);
        }
        cur += a[i];
        if (cur >= l) {
            cnt++;
            cur -= l;
        }
    }

    return 0;
}