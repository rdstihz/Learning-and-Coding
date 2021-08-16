#include <bits/stdc++.h>

using namespace std;

const int maxn = 150000 + 100;
const int INF = 0x3f3f3f3f;
struct Edge {
    int x, y, a, b;
    bool operator<(const Edge& phs) {
        return a < phs.a;
    }
} edges[maxn];

struct LinkCutTree {
    int val[maxn], mx[maxn];
    int ch[maxn][2], p[maxn];
    int st[maxn], top;
    bool rev[maxn];
    int chk(int x) {
        return ch[p[x]][1] == x;
    }
    bool isRoot(int x) {
        return ch[p[x]][0] != x && ch[p[x]][1] != x;
    }
    void flip(int x) {
        swap(ch[x][0], ch[x][1]);
        rev[x] ^= 1;
    }
    void maintain(int x) {
        mx[x] = x;
        if (val[mx[ch[x][0]]] > val[mx[x]]) mx[x] = mx[ch[x][0]];
        if (val[mx[ch[x][1]]] > val[mx[x]]) mx[x] = mx[ch[x][1]];
    }
    void pushdown(int x) {
        if (rev[x]) {
            flip(ch[x][0]), flip(ch[x][1]);
            rev[x] = 0;
        }
    }

    void rotate(int x) {
        int y = p[x], z = p[y], k = chk(x);
        if (!isRoot(y)) ch[z][chk(y)] = x;
        p[x] = z;
        ch[y][k] = ch[x][!k], p[ch[y][k]] = y;
        ch[x][!k] = y, p[y] = x;
        maintain(y), maintain(x);
    }

    void splay(int x) {
        top = 0;
        int cur = x;
        st[++top] = cur;
        while (!isRoot(cur))
            st[++top] = cur = p[cur];
        while (top)
            pushdown(st[top--]);
        while (!isRoot(x)) {
            int y = p[x], z = p[y];
            if (!isRoot(y))
                if (chk(x) == chk(y))
                    rotate(y);
                else
                    rotate(x);
            rotate(x);
        }
    }

    void access(int x) {
        int z = x;
        for (int y = 0; x; y = x, x = p[x]) {
            splay(x), ch[x][1] = y, maintain(x);
        }
        splay(z);
    }

    void makeroot(int x) {
        access(x);
        flip(x);
    }

    void split(int x, int y) {
        makeroot(x);
        access(y);
    }

    int findroot(int x) {
        access(x);
        while (ch[x][0])
            pushdown(x), x = ch[x][0];
        splay(x);
        return x;
    }

    void link(int x, int y) {
        makeroot(x);
        //if (findroot(y) != x) 
        p[x] = y;
    }

    void cut(int x, int y) {
        makeroot(x);
        if (p[y] == x && !ch[y][0]) {
            ch[x][1] = p[y] = 0;
            maintain(x);
        }
    }
} T;

//并查集
int p[maxn];
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int n, m;
int main() {
    scanf("%d%d", &n, &m);
    int x, y, a, b;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &x, &y, &a, &b);
        edges[i] = {x, y, a, b};
    }
    sort(edges + 1, edges + 1 + m);
    for (int i = 1; i <= n + m; i++) {
        p[i] = i;
        T.mx[i] = i;
        if (i > n) T.val[i] = edges[i - n].b;
    }
    int res = INF;
    for (int i = 1; i <= m; i++) {
        x = edges[i].x, y = edges[i].y, a = edges[i].a, b = edges[i].b;
        if (find(x) == find(y)) {
            T.split(x, y);
            int t = T.mx[y];
            if (T.val[t] > b) {
                T.cut(edges[t - n].x, t), T.cut(t, edges[t - n].y);
                T.link(x, n + i), T.link(n + i, y);
            }
        } else {
            T.link(x, n + i), T.link(n + i, y);
            p[find(x)] = find(y);
        }

        if (find(1) == find(n)) {
            T.split(1, n);
            res = min(res, a + T.val[T.mx[n]]);
        }
    }
    if (res == INF) res = -1;
    printf("%d\n", res);
    return 0;
}