#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 100000 + 10;
const LL INF = 1e18;
int a[maxn], b[maxn];
LL sa, sb;
LL ans;

int n, s, t, h;
LL check(int x, int y) {
    /*
    x表示a, y表示b
    =0: 低分排除
    =1: 有效分数
    =2: 高分排除
    */

    if (x == 0) {
        if (t == 0) return INF;
        LL A = sa + a[t], an = 1;
        LL B, bn;

        if (y == 0) {
            B = sb + b[t], bn = b[t];
            return A > B ? an - bn : INF;
        } else if (y == 1) {
            B = max(sb + b[t], min(A - 1, sb + b[n - s]));
            bn = B - sb;
            return A > B ? an - bn : INF;
        } else {
            if (s == 0) return INF;
            B = sb + b[n - s], bn = h;
            return A > B ? an - bn : INF;
        }
    } else if (x == 1) {

        if (y == 0) {
            if (t == 0) return INF;
            LL B = sb + b[t], bn = b[t];
            LL A = min(sa + a[n - s], max(B + 1, sa + a[t]));
            LL an = A - sa;
            return A > B ? an - bn : INF;
        } else if (y == 1) {
            //A = sa + an, B = sb + bn
            LL d = sb - sa + 1;
            if (d > a[n - s] - b[t])
                return INF;
            else if (d < a[t] - b[n - s])
                return a[t] - b[n - s];
            else
                return d;
          
        } else {
            if (s == 0) return INF;
            LL B = sb + b[n - s], bn = h;
            LL A = min(sa + a[n - s], max(B + 1, sa + a[t]));
            LL an = A - sa;
            return A > B ? an - bn : INF;
        }

    } else {
        if (s == 0) return INF;
        LL A = sa + a[n - s], an = a[n - s];
        LL B, bn;
        if (y == 0) {
            if (t == 0) return INF;
            B = sb + b[t], bn = b[t];
            return A > B ? an - bn : INF;
        } else if (y == 1) {
            B = max(sb + b[t], min(A - 1, sb + b[n - s]));
            bn = B - sb;
            return A > B ? an - bn : INF;
        } else {
            B = sb + b[n - s], bn = h;
            return A > B ? an - bn : INF;
        }
    }
}

void solve() {

    scanf("%d%d%d%d", &n, &s, &t, &h);
    a[0] = b[0] = 1;
    a[n] = b[n] = h;
    for (int i = 1; i < n; i++)
        scanf("%d", a + i);
    for (int i = 1; i < n; i++)
        scanf("%d", b + i);
    sort(a + 1, a + n);
    sort(b + 1, b + n);
    sa = sb = 0;
    for (int i = t + 1; i < n - s; i++)
        sa += a[i], sb += b[i];

    ans = INF;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ans = min(ans, check(i, j));

    if (ans == INF)
        printf("IMPOSSIBLE\n");
    else
        printf("%d\n", ans);
}

int main() {
    //freopen("/home/rdstihz/HDU9/2021“MINIEYE杯”中国大学生算法设计超级联赛（9）/10/input.txt", "r", stdin);
    //freopen("/home/rdstihz/HDU9/2021“MINIEYE杯”中国大学生算法设计超级联赛（9）/10/input.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}