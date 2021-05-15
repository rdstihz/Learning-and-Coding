#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>

#define lc (o << 1)
#define rc (o << 1 | 1)

using namespace std;

const int maxn = 100000 + 100;
const int maxm = 2 * maxn;

int n;

int sumv[maxn * 4], setv[maxn * 4];

void maintain(int o) {
    sumv[o] = sumv[lc] + sumv[rc];
}

void build() {
    memset(setv, -1, sizeof(setv));
}

void pushdown(int o, int L, int R) {
    if (setv[o] == 0 || setv[o] == 1) {
        int M = L + R >> 1;
        setv[lc] = setv[o], sumv[lc] = setv[o] * (M - L + 1);
        setv[rc] = setv[o], sumv[rc] = setv[o] * (R - M);
        setv[o] = -1;
    }
}

int query(int o, int L, int R, int l, int r) {
    if (l <= L && r >= R) return sumv[o];
    pushdown(o, L, R);
    int res = 0;
    int M = L + R >> 1;
    if (l <= M) res += query(lc, L, M, l, r);
    if (r > M) res += query(rc, M + 1, R, l, r);
    maintain(o);
    return res;
}

void update(int o, int L, int R, int l, int r, int v) {
    assert(l <= r);
    if (l <= L && r >= R) {
        setv[o] = v;
        sumv[o] = v * (R - L + 1);
        return;
    }
    pushdown(o, L, R);
    int M = L + R >> 1;
    if (l <= M) update(lc, L, M, l, r, v);
    if (r > M) update(rc, M + 1, R, l, r, v);
    maintain(o);
}

int to[maxm], nxt[maxm], fir[maxn], tot;

int dep[maxn], son[maxn], sz[maxn], father[maxn];
int top[maxn], pos[maxn], b[maxn], cnt;

void add_edge(int a, int b) {
    tot++;
    to[tot] = b, nxt[tot] = fir[a], fir[a] = tot;
}

void dfs1(int u, int f) {
    dep[u] = dep[f] + 1;
    father[u] = f;
    sz[u] = 1;

    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        if (v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int t) {
    top[u] = t;
    pos[u] = ++cnt;
    b[cnt] = 0;

    if (!son[u]) return;

    dfs2(son[u], t);

    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        if (v == father[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

int query_tree(int x) {
    return query(1, 1, n, pos[x], pos[x] + sz[x] - 1);
}
void update_tree(int x, int k) {
    update(1, 1, n, pos[x], pos[x] + sz[x] - 1, k);
}

int query_path(int u, int v) {
    int res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        res += query(1, 1, n, pos[top[u]], pos[u]);
        u = father[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    res += query(1, 1, n, pos[v], pos[u]);
    return res;
}

void update_path(int u, int v, int k) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        update(1, 1, n, pos[top[u]], pos[u], k);
        u = father[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    update(1, 1, n, pos[v], pos[u], k);
}

int main() {
    freopen("P2146_1.in", "r", stdin);
    scanf("%d", &n);
    int u;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &u);
        u++;
        add_edge(u, i);
        //add_edge(i, u);
    }

    dfs1(1, 0);
    dfs2(1, 1);

    build();
    printf("%d\n", cnt);
    assert(cnt == n);
    int m;
    char op[15];
    int x;

    scanf("%d", &m);
    while (m--) {
        scanf("%s%d", op, &x);
        x++;

        if (*op == 'i') {
            int t = query(1, 1, n, 1, n);
            update_path(x, 1, 1);
            printf("%d\n", query(1, 1, n, 1, n) - t);
        } else if (*op == 'u') {
            int t = query(1, 1, n, 1, n);
            update_tree(x, 0);
            printf("%d\n", t - query(1, 1, n, 1, n));
        }
    }

    return 0;
}