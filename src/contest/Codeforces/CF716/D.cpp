//莫队求区间众数

#include <bits/stdc++.h>

using namespace std;

const int maxn = 300000 + 100;

int color[maxn];
int cnt[maxn];

int readIn() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int len;

int get(int x) {
    return x / len;
}

struct Query {
    int id, l, r;
    bool operator<(const Query& phs) const {
        int la = get(l);
        int lb = get(phs.l);
        if (la != lb) return la < lb;
        return r < phs.r;
    }
} query[maxn];

void add(int x, int& res) {
    cnt[x]++;
    res = max(res, cnt[x]);
}
int ans[maxn];

int main() {

    int n, m;
    n = readIn();
    m = readIn();

    for (int i = 1; i <= n; i++)
        color[i] = readIn();

    len = sqrt(n) + 1;

    for (int i = 1; i <= m; i++) {
        query[i].id = i;
        query[i].l = readIn();
        query[i].r = readIn();
    }

    sort(query + 1, query + 1 + m);

    for (int x = 1; x <= m;) {
        int y = x;
        int block = get(query[x].l);
        int right = len - 1 + block * len;

        while (y <= m && query[y].l <= right)
            y++;

        //块内，暴力求解
        while (x < y && query[x].r <= right) {
            int res = 0;
            for (int i = query[x].l; i <= query[x].r; i++) {
                add(color[i], res);
            }
            for (int i = query[x].l; i <= query[x].r; i++) {
                cnt[color[i]]--;
            }
            int t = query[x].r - query[x].l + 1;
            ans[query[x].id] = max(1, 2 * res - t);

            x++;
        }

        //块间
        int r = right;
        int res = 0;
        while (x < y) {

            while (r < query[x].r)
                add(color[++r], res);

            int backup = res;

            for (int i = right; i >= query[x].l; i--)
                add(color[i], res);

            int t = query[x].r - query[x].l + 1;
            ans[query[x].id] = max(1, 2 * res - t);

            res = backup;
            for (int i = right; i >= query[x].l; i--)
                cnt[color[i]]--;

            x++;
        }

        memset(cnt, 0, sizeof(cnt));
    }

    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}