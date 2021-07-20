#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 5000 + 10;
const int INF = 0x3f3f3f3f;
struct Interval {
    int l, r;
    bool operator<(const Interval& phs) const {
        if (l == phs.l) return r > phs.r;
        return l < phs.l;
    }
} a[maxn], b[maxn];
 
bool del[maxn];
 
int dp[maxn][maxn];
int sum[maxn];
int inter(int i, int j) {
    int x = b[j].l;
    int y = b[i].r;
    if (x >= y) return -INF;
    return y - x;
}
int q[maxn], hh, tt; // 单调队列
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].l, &a[i].r);
    }
 
    sort(a + 1, a + 1 + n);
 
    vector<int> t; // 被包的区间长度
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i].l <= a[j].l && a[i].r >= a[j].r) { //i包含j
                del[i] = true;
                t.push_back(a[i].r - a[i].l);
                break;
            }
        }
    }
 
    int nn = 0;
    for (int i = 1; i <= n; i++)
        if (!del[i])
            b[++nn] = a[i];
 
    for (int i = 0; i <= nn; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = -INF;
 
    dp[0][0] = 0;
    for (int j = 1; j <= k; j++) {
        hh = tt = 0;
        for (int i = 0; i < j; i++) {
            while (hh < tt && b[q[hh + 1] + 1].r <= b[i].l)
                hh++;
            while (hh < tt && dp[q[tt]][j - 1] + b[q[tt] + 1].r <= dp[i][j - 1] + b[i + 1].r)
                tt--;
            q[++tt] = i;
        }
        for (int i = j; i <= nn; i++) {
            while (hh < tt && b[q[hh + 1] + 1].r <= b[i].l)
                hh++;
            if (hh < tt)
                dp[i][j] = dp[q[hh + 1]][j - 1] + b[q[hh + 1] + 1].r - b[i].l;
            else
                dp[i][j] = -INF;
            while (hh < tt && dp[q[tt]][j - 1] + b[q[tt] + 1].r <= dp[i][j - 1] + b[i + 1].r)
                tt--;
            q[++tt] = i;
        }
    }
 
    // for(int i = 1; i <= nn; i++) {
    //     for(int j = 1; j <= k; j++)
    //         printf("%d ", dp[i][j]);
    //     printf("\n");
    // }
 
    int ans = -INF;
    sort(t.begin(), t.end(), greater<int>());
    sum[0] = 0;
    for (int i = 1; i <= t.size(); i++)
        sum[i] = sum[i - 1] + t[i - 1];
    for (int i = 0; i <= t.size() && i <= k; i++)
        if (dp[nn][k - i] >= 0) ans = max(ans, sum[i] + dp[nn][k - i]);
    printf("%d\n", ans >= 0 ? ans : 0);
    return 0;
}