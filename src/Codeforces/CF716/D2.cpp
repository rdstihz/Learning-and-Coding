#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 300000 + 100;

struct Node {
    int v;
    int L, R;
    int lc, rc;
    int maxv;
} node[2 * maxn];
int tot;

void update(int p, int q, int l, int r, int pos) {
    node[q] = node[p];
    if (l == r) {
        node[q].v++;
        node[q].maxv++;
        return;
    }
    int m = l + r >> 1;

    if (pos <= m) {
        node[q].lc = ++tot;
        node[tot].L = l;
        node[tot].R = m;
        update(node[p].lc, node[q].lc, l, m, pos);
    } else {
        node[q].rc = ++tot;
        node[tot].L = m + 1;
        node[tot].R = r;
        update(node[p].rc, node[q].rc, m + 1, r, pos);
    }

    node[q].v = node[node[q].lc].v + node[node[q].rc].v;
    node[q].maxv = max(node[node[q].lc].maxv, node[node[q].rc].maxv);
}

int ask(int p, int q, int l, int r, int k) {
    if (l == r) {
        return l;
    }

    int m = l + r >> 1;
    int lcnt = node[node[q].lc].v - node[node[p].lc].v;
    if (k <= lcnt) {
        return ask(node[p].lc, node[q].lc, l, m, k);
    } else {
        return ask(node[p].rc, node[q].rc, m + 1, r, k - lcnt);
    }
}

int get_max(int p, int q, int l, int r, int k) {
    if (l == r) {
        return node[p].maxv;
    }
}

int build(int L, int R) {
    int u = ++tot;
    node[u].L = L;
    node[u].R = R;
    node[u].maxv = 0;
    node[u].maxv = 1;

    if (L == R) {

    } else {
        int M = L + R >> 1;
        node[u].lc = build(L, M);
        node[u].rc = build(M + 1, R);
    }
    return u;
}

int A[maxn], temp[maxn];
int rt[maxn];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", A + i), temp[i] = A[i];
    tot = 0;
    sort(temp + 1, temp + 1 + n);
    int cnt = unique(temp + 1, temp + 1 + n) - temp - 1;

    rt[0] = build(1, cnt);

    for (int i = 1; i <= n; i++) {
        A[i] = lower_bound(temp + 1, temp + 1 + cnt, A[i]) - temp;
        rt[i] = ++tot;
        update(rt[i - 1], rt[i], 1, cnt, A[i]);
    }

    for (int i = 1; i <= m; i++) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", temp[ask(rt[l - 1], rt[r], 1, cnt, k)]); //区间第k小
    }

    return 0;
}