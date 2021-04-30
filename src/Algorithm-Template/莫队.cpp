//HH的项链

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 50000 + 100;
const int maxm = 200000 + 100;
const int maxs = 1000000 + 100;

int color[maxn];
int cnt[maxs];
int n, m, len;

int ans[maxm];

inline void add(int i, int& res) {
    if (cnt[color[i]] == 0)
        res++;
    cnt[color[i]]++;
}

inline void del(int i, int& res) {
    if (cnt[color[i]] == 1)
        res--;
    cnt[color[i]]--;
}

inline int get(int i) {
    return i / len;
}

struct Query {
    int id, l, r;

    bool operator<(const Query& phs) {
        if (get(l) == get(phs.l)) {
            return r < phs.r;
        }
        return get(l) < get(phs.l);
    }

} q[maxm];

int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x;
}

int main() {

    n = read();
    for (int i = 1; i <= n; i++)
        color[i] = read();

    m = read();
    for (int i = 1; i <= m; i++) {
        q[i].id = i;
        q[i].l = read();
        q[i].r = read();
    }

    len = sqrt((double) n * n / m);

    sort(q + 1, q + 1 + m);

    int i = 1, j = 0;
    int res = 0;
    for (int k = 1; k <= m; k++) {
        while (i < q[k].l)
            del(i++, res);
        while (i > q[k].l)
            add(--i, res);
        while (j < q[k].r)
            add(++j, res);
        while (j > q[k].r)
            del(j--, res);
        ans[q[k].id] = res;
    }

    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);

    return 0;
}