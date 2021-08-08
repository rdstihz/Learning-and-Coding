#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
struct node {
    int val, l, r;
    ll sum;
} tree[N * 20];
int root[N];
int tot;
int a[N], w[N];
int n;
void build(int& p, int l, int r) {
    p = ++tot;
    if (l == r) {
        tree[p].l = tree[p].r = 0;
        tree[p].val = 0;
        tree[p].sum = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(tree[p].l, l, mid);
    build(tree[p].r, mid + 1, r);
    tree[p].val = tree[tree[p].l].val + tree[tree[p].r].val;
    tree[p].sum = tree[tree[p].l].sum + tree[tree[p].r].sum;
}
void update(int& p, int x, int l, int r, int rt) {
    p = ++tot;
    tree[p] = tree[rt];
    tree[p].val++;
    if (l == r) {
        tree[p].sum = w[l] * tree[p].val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update(tree[p].l, x, l, mid, tree[rt].l);
    if (x > mid) update(tree[p].r, x, mid + 1, r, tree[rt].r);
    tree[p].sum = tree[tree[p].l].sum + tree[tree[p].r].sum;
}
int query(int u, int v, int l, int r, int k) {
    if (l == r) return l;
    int x = tree[tree[v].l].val - tree[tree[u].l].val;
    int mid = (l + r) >> 1;
    if (k <= x) return query(tree[u].l, tree[v].l, l, mid, k);
    return query(tree[u].r, tree[v].r, mid + 1, r, k - x);
}
ll query_sum(int u, int v, int l, int r, int k) {
    if (l == r) {
        return 1ll * k * w[l];
    }
    int x = tree[tree[v].l].val - tree[tree[u].l].val;
    int mid = (l + r) >> 1;
    if (k <= x) return query_sum(tree[u].l, tree[v].l, l, mid, k);
    return tree[tree[v].l].sum - tree[tree[u].l].sum + query_sum(tree[u].r, tree[v].r, mid + 1, r, k - x);
}
int main() {
    int q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        w[i] = a[i];
    }
    sort(w + 1, w + n + 1);
    int m = unique(w + 1, w + n + 1) - w - 1;
    build(root[0], 1, m);
    for (int i = 1; i <= n; i++) {
        int t = lower_bound(w + 1, w + m + 1, a[i]) - w;
        update(root[i], t, 1, m, root[i - 1]);
    }
    while (q--) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int t = query(root[l - 1], root[r], 1, m, k);
        int t2 = query_sum(root[l - 1], root[r], 1, m, k);
        printf("kth=%d ksum=%d\n", w[t], t2);
    }
    return 0;
}

/*
6 4
1 1 4 5 1 4
1 0 3 1 -4 3 
1 6 3
[l+1, r]: 3 -3
-5

*/