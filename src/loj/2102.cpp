#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 500000 + 10;
char s[maxn];
int sa[maxn], height[maxn], x[maxn], y[maxn], rk[maxn], c[maxn];
int n, m;

void get_sa() {
    //按第一个字母排序
    for (int i = 1; i <= n; i++)
        c[x[i] = s[i]]++;
    for (int i = 2; i <= m; i++)
        c[i] += c[i - 1];
    for (int i = n; i >= 1; i--)
        sa[c[x[i]]--] = i;
    //倍增
    for (int k = 1; k <= n; k <<= 1) {
        //按后k个字母排序，排序后存在y数组
        int num = 0;
        for (int i = n - k + 1; i <= n; i++)
            y[++num] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > k)
                y[++num] = sa[i] - k;

        //按前k个字母排序, 存到sa
        for (int i = 1; i <= m; i++)
            c[i] = 0;
        for (int i = 1; i <= n; i++)
            c[x[i]]++;
        for (int i = 1; i <= m; i++)
            c[i] += c[i - 1];
        for (int i = n; i >= 1; i--)
            sa[c[x[y[i]]]--] = y[i], y[i] = 0;

        //计算新的x
        num = 0;
        swap(x, y);
        x[sa[1]] = ++num;
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

int S[maxn];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1), m = 122;
    get_sa();
    get_height();
    
    for(int i = 1; i <= n; i++) {
        S[i] = S[i - 1] + (n - sa[i] + 1) - height[i];
    }

    int T;
    scanf("%d", &T);
    while(T--) {
        int k;
        scanf("%d", &k);
        int t = lower_bound(S + 1, S + 1 + n, k) - S;
        k -= S[t - 1];
        for(int i = sa[t]; i < sa[t] + height[t] + k; i++)
            putchar(s[i]);
        puts("");
    }

    return 0;
}