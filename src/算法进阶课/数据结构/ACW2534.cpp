#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100000 + 100;

int color[maxn];
vector<int> nums;

//邻接表
int to[maxn], fir[maxn];
int nxt[maxn], idx;

int n, m, len;

//莫队
int cnt[maxn], vis[maxn];
int ans[maxn];

inline int get(int x) {
    return x / len;
}

struct Query {
    int id, l, r, p;

    bool operator<(const Query& phs) const {
        int la = get(l);
        int lb = get(phs.l);
        if (la != lb) return la < lb;
        return r < phs.r;
    }

} query[maxn];

inline void add_edge(int u, int v) {
    idx++;
    to[idx] = v;
    nxt[idx] = fir[u];
    fir[u] = idx;
}

//LCA
int dep[maxn], st[maxn][16];

//欧拉序列
int seq[maxn], top;
int first[maxn], last[maxn];

void dfs(int u, int father) {

    seq[++top] = u;
    first[u] = top;

    for (int e = fir[u], v = to[e]; e; e = nxt[e], v = to[e])
        if (v != father) {
            dep[v] = dep[u] + 1;
            st[v][0] = u;
            for (int k = 1; k <= 15; k++)
                st[v][k] = st[st[v][k - 1]][k - 1];
            dfs(v, u);
        }
    seq[++top] = u;
    last[u] = top;
}

inline int LCA(int a, int b) {
    if (dep[a] < dep[b])
        swap(a, b);

    for (int k = 15; k >= 0; k--)
        if (dep[st[a][k]] >= dep[b])
            a = st[a][k];

    if (a == b)
        return a;

    for (int k = 15; k >= 0; k--)
        if (st[a][k] != st[b][k]) {
            a = st[a][k];
            b = st[b][k];
        }

    return st[a][0];
}

inline void add(int x, int& res) {
    vis[x] ^= 1;

    if (vis[x]) {
        cnt[color[x]]++;
        if (cnt[color[x]] == 1)
            res++;
    } else {
        cnt[color[x]]--;
        if (cnt[color[x]] == 0)
            res--;
    }
}

int main() {

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", color + i);
        nums.push_back(color[i]);
    }
    //离散化
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (int i = 1; i <= n; i++)
        color[i] = lower_bound(nums.begin(), nums.end(), color[i]) - nums.begin();

    //读入树的边
    int a, b;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }

    //求欧拉序列并初始化st表
    dep[1] = 1;
    dfs(1, 0);

    //读入询问并排序
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        if (first[a] > first[b])
            swap(a, b);
        int lca = LCA(a, b);
        if (lca == a) {
            query[i] = {i, first[a], first[b], 0};
        } else {
            query[i] = {i, last[a], first[b], lca};
        }
    }

    len = sqrt(top) + 1;
    sort(query + 1, query + 1 + m);

    int res = 0;
    int i = 1, j = 0;
    for (int k = 1; k <= m; k++) {
        int id = query[k].id, l = query[k].l, r = query[k].r, p = query[k].p;

        while (j < r)
            add(seq[++j], res);
        while (j > r)
            add(seq[j--], res);
        while (i > l)
            add(seq[--i], res);
        while (i < l)
            add(seq[i++], res);

        if (p)
            add(p, res);
        ans[id] = res;
        if (p)
            add(p, res);
    }

    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);

    return 0;
}
