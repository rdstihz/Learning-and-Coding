#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

const int maxn = 100000 + 100;

int w[maxn];

struct Query {
    int id, l, r;
    LL res;
} query[maxn];

struct Range {
    int id, l, r, t;
};

vector<Range> range[maxn];

int n, m, k, len;

//f[i] 1 ~ i 中与 w[i + 1] 配对的个数
//g[x]前i个数中， 与x配对的个数
//f[i] = g[w[i + 1]]
int f[maxn], g[maxn];
vector<int> nums;

inline int readIn() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x;
}

int get(int x) {
    return x / len;
}

bool cmp(const Query& a, const Query& b) {
    int la = get(a.l);
    int lb = get(b.l);
    if (la != lb) return la < lb;
    return a.r < b.r;
}

int get_count(int x) { //x二进制表示中1的个数
    int res = 0;
    while (x)
        res += (x & 1), x >>= 1;
    return res;
}

int ans[maxn];

int main() {
    n = readIn();
    m = readIn();
    k = readIn();

    for (int i = 1; i <= n; i++)
        w[i] = readIn();

    for (int i = 1; i <= m; i++) {
        query[i].id = i;
        query[i].l = readIn();
        query[i].r = readIn();
    }

    len = sqrt(n) + 1;

    sort(query + 1, query + 1 + m, cmp);

    for (int i = 0; i < (1 << 14); i++)
        if (get_count(i) == k)
            nums.push_back(i);

    for (int i = 1; i < n; i++) {

        for (int t : nums)
            g[w[i] ^ t]++;

        f[i] = g[w[i + 1]];
    }

    for (int i = 1, L = 1, R = 0; i <= m; i++) {
        int l = query[i].l, r = query[i].r;

        if (R < r)
            range[L - 1].push_back({i, R + 1, r, -1});
        while (R < r)
            query[i].res += f[R], R++;

        if (R > r)
            range[L - 1].push_back({i, r + 1, R, 1});
        while (R > r)
            query[i].res -= f[R - 1], R--;
        if (L < l)
            range[R].push_back({i, L, l - 1, -1});
        while (L < l)
            query[i].res += f[L - 1] + !k, L++;

        if (L > l)
            range[R].push_back({i, l, L - 1, 1});
        while (L > l)
            query[i].res -= f[L - 2] + !k, L--;
    }

    memset(g, 0, sizeof(g));

    for (int i = 1; i <= n; i++) {

        for (int t : nums)
            g[w[i] ^ t]++;

        for (Range& rg : range[i]) {
            int id = rg.id, l = rg.l, r = rg.r;
            for (int x = l; x <= r; x++)
                query[id].res += (LL)rg.t * g[w[x]];
        }
    }

    for (int i = 2; i <= m; i++)
        query[i].res += query[i - 1].res;

    for (int i = 1; i <= m; i++)
        ans[query[i].id] = query[i].res;
    
    for(int i = 1; i <= m; i++)
        printf("%lld\n", ans[i]);
    return 0;
}