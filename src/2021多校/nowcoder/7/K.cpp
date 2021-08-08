#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 200000 + 100;
int a[maxn], b[maxn];
LL Sp[maxn], Sn[maxn];

typedef long long ll;

const int N = 2e5 + 5;
struct node {
    int val, l, r;
    ll sum;
} tree[N * 20];
int root[N];
int tot;
int w[N];
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

int m;
vector<int> nums;
LL sum_min_k(int l, int r, int k) {
    /*
    if (k <= 0) return 0ll;
    if (l == r && k == 1) {
        return a[l];
    }
    if (r - l + 1 == k) {
        return a[l] + Sp[r] - Sp[l] - (Sn[r] - Sn[l]);
    }
    int kth = w[query(root[l], root[r], 1, m, k)];
    LL ksum = query_sum(root[l], root[r], 1, m, k);
    //printf("[l+1, r]: %d %lld\n", kth, ksum);
    if (a[l] < kth) ksum += a[l] - kth;
    return ksum; */

    nums.clear();
    for (int i = l + 1; i <= r; i++) {
        nums.push_back(b[i]);
    }
    nums.push_back(a[l]);
    sort(nums.begin(), nums.end());
    LL res = 0;
    for (int i = 0; i < k; i++)
        res += nums[i];
    return res;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i), b[i] = a[i] - a[i - 1];

    for (int i = 1; i <= n; i++) {
        Sp[i] = Sp[i - 1];
        Sn[i] = Sn[i - 1];
        if (b[i] > 0)
            Sp[i] += b[i];
        else
            Sn[i] -= b[i];
    }

    
    // for (int i = 1; i <= n; i++)
    //     w[i] = b[i];
    // sort(w + 1, w + n + 1);
    // m = unique(w + 1, w + n + 1) - w - 1;
    // build(root[0], 1, m);
    // for (int i = 1; i <= n; i++) {
    //     int t = lower_bound(w + 1, w + m + 1, b[i]) - w;
    //     update(root[i], t, 1, m, root[i - 1]);
    // }

    int l, r, k;
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", b[i]);
    // printf("\n");
    // while (q--) {
    //     scanf("%d%d%d", &l, &r, &k);
    //     printf("%lld\n", sum_min_k(l, r, k));
    // }

    while (q--) {
        scanf("%d%d%d", &l, &r, &k);
        LL sp = Sp[r] - Sp[l], sn = Sn[r] - Sn[l];
        sp += a[l];
        LL ans = max(sp, sn);
        //修改b[l] -> a[l]
        //swap(a[l], b[l]);

        if (sp > sn) {
            LL delta = sp - sn;
            int t1 = delta / k;
            int t2 = (delta + k - 1) / k;

            LL s1, s2; // s1为区间[l, r]前t1大的和, s2为区间[l, r]前t2大的和
            //s1 = sum_max_k(l, r, t1), s2 = sum_max_k(l, r, t2);
            s1 = sp - sn - sum_min_k(l, r, r - l + 1 - t1);
            s2 = sp - sn - sum_min_k(l, r, r - l + 1 - t2);
            ans = min(ans, max(sp - s1, sn + t1 * k - s1));
            ans = min(ans, max(sp - s2, sn + t2 * k - s2));
        } else if (sn > sp) {
            LL delta = sn - sp;
            int t1 = delta / k;
            int t2 = (delta + k - 1) / k;

            LL s1, s2; // s1为区间[l, r]前t1小的和, s2为区间[l, r]前t2小的和  (绝对值)
            s1 = sum_min_k(l, r, t1), s2 = sum_min_k(l, r, t2);
            s1 = -s1, s2 = -s2;
            ans = min(ans, max(sn - s1, sp + t1 * k - s1));
            ans = min(ans, max(sn - s2, sp + t2 * k - s2));
        }

        //修改a[l] -> b[l]
        //swap(a[l], b[l]);

        printf("%lld\n", ans);
    }

    return 0;
}

/*
4 1
154376203 796925591 750050718 538329124 
1 4 977068593

593115672
*/

/*
6 4
1 1 4 5 1 4
3 5 10
1 4 11
1 6 998244252
1 6 6


5
5
8
7
*/