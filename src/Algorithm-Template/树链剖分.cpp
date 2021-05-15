#include <algorithm>
#include <cstdio>
#include <cstring>

#define lc (o << 1)
#define rc (o << 1 | 1)

using namespace std;
typedef long long LL;

const int maxn = 100000 + 10;
const int maxm = 2 * maxn;

int a[maxn];
int to[maxm], nxt[maxm], fir[maxn], tot;

int sz[maxn], son[maxn], dep[maxn], father[maxn];

int top[maxn], pos[maxn], b[maxn]; // 所在重链的顶节点， 在新序列中的位置， 新序列中的值
int cnt;
int n;
void add_edge(int u, int v) {
    tot++;
    to[tot] = v, nxt[tot] = fir[u], fir[u] = tot;
}
/*
dfs1:计算子树大小sz, 重儿子son, 深度dep, 父节点father
*/
void dfs1(int u, int f) {
    sz[u] = 1;
    father[u] = f;
    dep[u] = dep[f] + 1;
    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        if (v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v]) son[u] = v;
    }
}
/*
dfs2: 计算节点所在重链的顶端节点 top, 节点在序列中的位置pos, 序列中的值b
*/
void dfs2(int u, int t) {
    top[u] = t;
    pos[u] = ++cnt;
    b[cnt] = a[u];

    if (!son[u]) return;
    dfs2(son[u], t); //重儿子

    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        if (v == son[u] || v == father[u]) continue;
        dfs2(v, v);
    }
}

//线段树
struct SegmentTree {
    LL sumv[maxn * 4], addv[maxn * 4];

    void maintain(int o) {
        sumv[o] = sumv[lc] + sumv[rc];
    }

    void pushdown(int o, int L, int R) {
        if (addv[o]) {
            int M = L + R >> 1;
            addv[lc] += addv[o], sumv[lc] += addv[o] * (M - L + 1);
            addv[rc] += addv[o], sumv[rc] += addv[o] * (R - M);
            addv[o] = 0;
        }
    }

    void build(int o, int L, int R) {
        if (L == R) {
            sumv[o] = b[L];
            addv[o] = 0;
            return;
        }
        int M = L + R >> 1;
        build(lc, L, M);
        build(rc, M + 1, R);
        maintain(o);
    }

    void update(int o, int L, int R, int l, int r, LL v) {
        if (l <= L && r >= R) {
            sumv[o] += v * (R - L + 1);
            addv[o] += v;
            return;
        }
        pushdown(o, L, R);
        int M = L + R >> 1;
        if (l <= M) update(lc, L, M, l, r, v);
        if (r > M) update(rc, M + 1, R, l, r, v);
        maintain(o);
    }

    LL query(int o, int L, int R, int l, int r) {
        if (l <= L && r >= R) return sumv[o];
        pushdown(o, L, R);
        int M = L + R >> 1;
        LL res = 0;
        if (l <= M) res += query(lc, L, M, l, r);
        if (r > M) res += query(rc, M + 1, R, l, r);
        return res;
    }

} T;
/*
    将路径转化为O(log(n))个区间
    u -> v
    将u和v中top[i]深的向上跳，直到u和v在同一条重链
*/
void update_path(int u, int v, int k) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        T.update(1, 1, n, pos[top[u]], pos[u], k);
        u = father[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    T.update(1, 1, n, pos[v], pos[u], k);
}

LL query_path(int u, int v) {
    LL res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        res += T.query(1, 1, n, pos[top[u]], pos[u]);
        u = father[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    res += T.query(1, 1, n, pos[v], pos[u]);
    return res;
}

void update_tree(int u, int k) {
    T.update(1, 1, n, pos[u], pos[u] + sz[u] - 1, k);
}
LL query_tree(int u) {
    return T.query(1, 1, n, pos[u], pos[u] + sz[u] - 1);
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int op, u, v, k;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    dfs1(1, 0); // sz, son, dep， father
    dfs2(1, 1); // top, pos, b

    T.build(1, 1, n);

    int q;
    scanf("%d", &q);
    
    while (q--) {

        scanf("%d", &op);

        if (op == 1) {
            scanf("%d%d%d", &u, &v, &k);
            update_path(u, v, k);
        } else if (op == 2) {
            scanf("%d%d", &u, &k);
            update_tree(u, k);
        } else if (op == 3) {
            scanf("%d%d", &u, &v);
            LL res = query_path(u, v);
            printf("%lld\n", res);
        } else if (op == 4) {
            scanf("%d", &u);
            LL res = query_tree(u);
            printf("%lld\n", res);
        }
    }
    return 0;
}