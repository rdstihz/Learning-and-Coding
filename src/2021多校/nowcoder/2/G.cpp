#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000 + 100;
const int INF = 1 << 30;
int n, m, k;
struct Node {
    int l, r;
    bool operator<(const Node& phs) const {
        if (l == phs.l)
            return r > phs.r;
        else
            return l < phs.l;
    }
} a[maxn], b[maxn];
int dp[maxn][maxn];

bool del[maxn];
vector<int> big; //被删除的区间
int sum[maxn];


int q[maxn], hh, tt;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].l, &a[i].r);

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i].l <= a[j].l && a[i].r >= a[j].r) {
                del[i] = true;
                big.push_back(a[i].r - a[i].l);
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (!del[i]) b[++m] = a[i];
    sort(big.begin(), big.end(), greater<int>());

    /*
    printf("\n\n");

    for (int i = 1; i <= m; i++)
        printf("%d %d\n", b[i].l, b[i].r);
    printf("\n\n");
    for(int v : big)
        printf("%d ", v);
    printf("\n");
    */

    for (int i = 1; i <= big.size(); i++)
        sum[i] = sum[i - 1] + big[i - 1];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = -INF;
    
    
    dp[0][0] = 0;
    for (int j = 1; j <= k; j++) {
        hh = tt = 0;
        /*
        for (int i = 0; i < j; i++) {
            while (hh < tt && b[q[hh + 1] + 1].r <= b[i].l)
                hh++;
            while (hh < tt && dp[q[tt]][j - 1] + b[q[tt] + 1].r <= dp[i][j - 1] + b[i + 1].r)
                tt--;
            q[++tt] = i;
        }
        */
        for (int i = 0; i <= m; i++) {
            while (hh < tt && b[q[hh + 1] + 1].r <= b[i].l)
                hh++;
            if (hh < tt && b[q[hh + 1] + 1].r > b[i].l)
                dp[i][j] = dp[q[hh + 1]][j - 1] + b[q[hh + 1] + 1].r - b[i].l;
            else
                dp[i][j] = -INF;
            while (hh < tt && dp[q[tt]][j - 1] + b[q[tt] + 1].r <= dp[i][j - 1] + b[i + 1].r)
                tt--;
            q[++tt] = i;
        }
    }
    

   

    int ans = -INF;
    for (int i = 0; i <= k && i <= big.size(); i++)
        ans = max(ans, sum[i] + dp[m][k - i]);
    printf("%d\n", ans >= 0 ? ans : 0);

    return 0;
}

/*
9 4
1 3
1 3
1 3
1 3
1 10
1 100
2 200
7 8
7 10
*/