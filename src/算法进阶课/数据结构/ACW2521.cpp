#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000 + 10;

int color[maxn];
int cnt[1000000 + 100];

int len;

int get(int x) {
    return x / len;
}

struct Query {
    int id, l, r, t;

    bool operator<(const Query& phs) const {
        int la = get(l);
        int ra = get(r);
        int lb = get(phs.l);
        int rb = get(phs.r);

        if (la != lb) return la < lb;
        if (ra != rb) return ra < rb;
        return t < phs.t;
    }

} query[maxn];

struct Replace {
    int pos;
    int col;
} rp[1010];

void add(int v, int& res) {
    if (cnt[v] == 0)
        res++;
    cnt[v]++;
}
void del(int v, int& res) {
    if (cnt[v] == 1)
        res--;
    cnt[v]--;
}

int ans[maxn];

int main() {

    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1;i <= n; i++)
        scanf("%d", color + i);

    char op[2];
    int l, r;

    int cq = 0;
    int ct = 0;

    for (int i = 1; i <= m; i++) {
        scanf("%s%d%d", op, &l, &r);
        if (*op == 'Q') {
            cq++;
            query[cq] = {cq, l, r, ct};
        } else {
            rp[++ct] = {l, r};
        }
    }
    len = pow(n * ct, 1.f / 3);
    sort(query + 1, query + cq + 1);

    int res = 0;
    int i = 1, j = 0;
    int t = 0;
    for (int k = 1; k <= cq; k++) {

        int id = query[k].id;
        int l = query[k].l;
        int r = query[k].r;

        while (i > l)
            add(color[--i], res);
        while (i < l)
            del(color[i++], res);
        while (j < r)
            add(color[++j], res);
        while (j > r)
            del(color[j--], res);

        while (t < query[k].t) {
            t++;
            if (rp[t].pos >= l && rp[t].pos <= r) {
                del(color[rp[t].pos], res);
                add(rp[t].col, res);
            }
            swap(rp[t].col, color[rp[t].pos]);
        }
        while (t > query[k].t) {
            if (rp[t].pos >= l && rp[t].pos <= r) {
                del(color[rp[t].pos], res);
                add(rp[t].col, res);
            }
            swap(rp[t].col, color[rp[t].pos]);
            t--;
        }
        ans[id] = res;
    }

    for (int i = 1; i <= cq; i++)
        printf("%d\n", ans[i]);

    return 0;
}