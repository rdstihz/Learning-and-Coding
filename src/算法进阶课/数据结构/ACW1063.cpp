#include <bits/stdc++.h>

using namespace std;

const int maxn = 1800000 + 100;

int a[100010];

struct Splay {

    int val[maxn], id[maxn];
    int ch[maxn][2], p[maxn];
    int size[maxn];
    int root[100010], tot;

    int newnode(int _val, int _id, int _p) {
        tot++;
        val[tot] = _val, id[tot] = _id, p[tot] = _p;
        size[tot] = 1;
        return tot;
    }

    int chk(int x) {
        return ch[p[x]][1] == x;
    }

    void maintain(int x) {
        size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
    }

    void rotate(int x) {
        int y = p[x], z = p[y];
        int k = chk(x);
        ch[z][chk(y)] = x, p[x] = z;
        ch[y][k] = ch[x][!k], p[ch[y][k]] = y;
        ch[x][!k] = y, p[y] = x;
        maintain(y), maintain(x);
    }

    void splay(int x, int k, int b) {
        while (p[x] != k) {
            int y = p[x], z = p[y];
            if (z != k)
                if (chk(x) == chk(y))
                    rotate(y);
                else
                    rotate(x);
            rotate(x);
        }
        if (!k) root[b] = x;
    }

    void insert(int _val, int _id, int b) {
        int cur = root[b], pa = 0;
        while (cur)
            pa = cur, cur = ch[cur][_val > val[cur]];
        cur = newnode(_val, _id, pa);
        ch[pa][_val > val[pa]] = cur;
        splay(cur, 0, b);
    }

    int get_k(int b, int k) {
        int cur = root[b];
        while (cur) {
            if (k <= size[ch[cur][0]])
                cur = ch[cur][0];
            else if (k == size[ch[cur][0]] + 1)
                return id[cur];
            else {
                k -= size[ch[cur][0]] + 1;
                cur = ch[cur][1];
            }
        }
        return -1;
    }

} T;

int p[100010];
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void dfs(int u, int b) {
    if (T.ch[u][0])
        dfs(T.ch[u][0], b);
    if (T.ch[u][1])
        dfs(T.ch[u][1], b);

    T.insert(T.val[u], T.id[u], b);
}

int main() {

    int n, m;
    scanf("%d%d", &n, &m);
    int v;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v);
        p[i] = i;
        T.root[i] = T.newnode(v, i, 0);
    }
    int a, b;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        a = find(a), b = find(b);
        if (a == b) continue;
        if (T.size[T.root[a]] > T.size[T.root[b]])
            swap(a, b);

        dfs(T.root[a], b);
        p[a] = b;
    }

    int q;
    scanf("%d", &q);
    char op[2];
    while (q--) {
        scanf("%s%d%d", op, &a, &b);
        if (*op == 'B') {
            a = find(a), b = find(b);
            if (a == b) continue;
            if (T.size[T.root[a]] > T.size[T.root[b]])
                swap(a, b);

            dfs(T.root[a], b);
            p[a] = b;
        } else {
            int res = T.get_k(find(a), b);
            printf("%d\n", res);
        }
    }

    return 0;
}