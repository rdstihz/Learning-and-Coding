#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long LL;
const int N = 100010;
int n, m;
char s[N];
int sa[N], x[N], y[N], c[N], rk[N], height[N];

void get_sa() {
    for (int i = 1; i <= n; i++)
        c[x[i] = s[i]]++;
    for (int i = 2; i <= m; i++)
        c[i] += c[i - 1];
    for (int i = n; i; i--)
        sa[c[x[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int num = 0;
        for (int i = n - k + 1; i <= n; i++)
            y[++num] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > k)
                y[++num] = sa[i] - k;
        for (int i = 1; i <= m; i++)
            c[i] = 0;
        for (int i = 1; i <= n; i++)
            c[x[i]]++;
        for (int i = 2; i <= m; i++)
            c[i] += c[i - 1];
        for (int i = n; i; i--)
            sa[c[x[y[i]]]--] = y[i], y[i] = 0;
        swap(x, y);
        x[sa[1]] = 1, num = 1;
        for (int i = 2; i <= n; i++)
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++num;
        if (num == n) break;
        m = num;
    }
}

void get_height() {
    for (int i = 1; i <= n; i++)
        rk[sa[i]] = i;
    for (int i = 1, k = 0; i <= n; i++) {
        if (rk[i] == 1) continue;
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (i + k <= n && j + k <= n && s[i + k] == s[j + k])
            k++;
        height[rk[i]] = k;
    }
}

void init() {
    //scanf("%s", s + 1);
    m = 122;
    for (int i = 0; i <= m; i++) {
        c[i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        sa[i] = height[i] = x[i] = y[i] = rk[i] = 0;
    }
    get_sa();
    get_height();

    //    for (int i = 1; i <= n; i++)
    //        printf("%d ", sa[i]);
    //    puts("");
    //    for (int i = 1; i <= n; i++)
    //        printf("%d ", height[i]);
    //    puts("");
}

int val[27];
int S[N];
LL k;

bool check(LL mid) {
    long long res = 0;
    for (int e = 1; e <= n; e++) {
        int i = sa[e];
        int l = i, r = n + 1;
        int m;
        while (l < r) {
            m = l + r >> 1;
            //            printf("%d\n",m);
            if (S[m] - S[i - 1] > mid)
                r = m;
            else
                l = m + 1;
        }
        l--;
        res += (l - i + 1) - min(height[e], l - i + 1);
    }
    return res >= k;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%lld", &n, &k);

        scanf("%s", s + 1);
        for (int i = 0; i < 26; i++)
            scanf("%d", val + i);
        for (int i = 1; i <= n; i++)
            S[i] = S[i - 1] + val[s[i] - 'a'];
        S[n + 1] = 1 << 30;
        init();

        LL l = 0, r = 110 * n;
        LL m;
        while (l < r) {
            m = l + r >> 1;
            //            printf("%lld\n",m);
            if (check(m))
                r = m;
            else
                l = m + 1;
        }
        if (l >= 110 * n)
            printf("-1\n");
        else
            printf("%lld\n", l);
    }

    return 0;
}