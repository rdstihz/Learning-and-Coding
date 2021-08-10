#include <bits/stdc++.h>
#define lc (o << 1)
#define rc (o << 1 | 1)
using namespace std;

const int maxn = 300000 + 100;

vector<int> G1[maxn], G2[maxn];

int st[maxn], ed[maxn];
int ts, ans;
int seq[maxn], l, r;
int n;
struct SegmentTree {
    int addv[maxn * 8], maxv[maxn * 8];

    void maintain(int o) {
        maxv[o] = max(maxv[lc], maxv[rc]);
    }

    void pushdown(int o) {
        if (addv[o]) {
            maxv[lc] += addv[o], addv[lc] += addv[o];
            maxv[rc] += addv[o], addv[rc] += addv[o];
            addv[o] = 0;
        }
    }

    void update(int o, int L, int R, int l, int r, int v) {
        if (l <= L && r >= R) {
            maxv[o] += v;
            addv[o] += v;
            return;
        }
        pushdown(o);
        int M = L + R >> 1;
        if (l <= M) update(lc, L, M, l, r, v);
        if (r > M) update(rc, M + 1, R, l, r, v);
        maintain(o);
    }

    int query(int o, int L, int R, int l, int r) {
        if (l <= L && r >= R) {
            return maxv[o];
        }
        pushdown(o);
        int res = 0, M = L + R >> 1;
        if (l <= M) res = max(res, query(lc, L, M, l, r));
        if (r > M) res = max(res, query(rc, M + 1, R, l, r));
    }
    void init(int o, int L, int R) {
        addv[o] = maxv[o] = 0;
        if (L == R) return;
        int M = L + R >> 1;
        init(lc, L, M);
        init(rc, M + 1, R);
        maintain(o);
    }

} T;

void dfs1(int u) {
    st[u] = ++ts;
    for (int v : G2[u])
        if (!st[v])
            dfs1(v);
    ed[u] = ++ts;
}

bool vis[maxn];
void dfs2(int u) {
    seq[++r] = u;
    vis[u] = true;
    int bl = l;
    T.update(1, 1, 2 * n, st[u], ed[u], 1);
    while (l <= r && T.query(1, 1, 2 * n, 1, 2 * n) > 1) {
        T.update(1, 1, 2 * n, st[seq[l]], ed[seq[l]], -1);
        l++;
    }
    ans = max(ans, r - l + 1);

    for (int v : G1[u])
        if (!vis[v])
            dfs2(v);
    while (l > bl) {
        l--;
        T.update(1, 1, 2 * n, st[seq[l]], ed[seq[l]], 1);
    }
    T.update(1, 1, 2 * n, st[u], ed[u], -1);
    r--;
}

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            G1[i].clear(), G2[i].clear();
            vis[i] = false;
            st[i] = ed[i] = 0;
        }
        int x, y;
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &x, &y);
            G1[x].push_back(y), G1[y].push_back(x);
        }
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &x, &y);
            G2[x].push_back(y), G2[y].push_back(x);
        }

        ts = 0;
        dfs1(1);
        ans = 0;
        l = 1, r = 0;
        T.init(1, 1, 2 * n);
        dfs2(1);

        printf("%d\n", ans);
    }

    return 0;
}

/*
1
5
5 3
3 1
5 4
3 2
5 3
5 1
3 4
3 2

*/