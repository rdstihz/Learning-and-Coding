#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
const int INF = 0x3f3f3f3f;

struct Splay {
    int val[maxn];
    int ch[maxn][2], p[maxn];
    int size[maxn], cnt[maxn];
    int tot, root;

    int
    chk(int x) {
        return ch[p[x]][1] == x;
    }

    void maintain(int x) {
        size[x] = cnt[x] + size[ch[x][0]] + size[ch[x][1]];
    }

    int newnode(int v, int pa) {
        tot++;
        val[tot] = v, size[tot] = cnt[tot] = 1;
        p[tot] = pa;
        return tot;
    }

    void rotate(int x) {
        int y = p[x], z = p[y];
        int k = chk(x);
        ch[z][chk(y)] = x, p[x] = z;
        ch[y][k] = ch[x][!k], p[ch[y][k]] = y;
        ch[x][!k] = y, p[y] = x;
        maintain(y), maintain(x);
    }

    void splay(int x, int k) {
        while (p[x] != k) {
            int y = p[x], z = p[y];
            if (z != k)
                if (chk(x) == chk(y))
                    rotate(y);
                else
                    rotate(x);
            rotate(x);
        }
        if (!k) root = x;
    }

    int insert(int v) {
        int cur = root;
        int pa = 0;
        while (cur && val[cur] != v)
            pa = cur, cur = ch[cur][v > val[cur]];

        if (cur)
            cnt[cur]++, size[cur]++;
        else {
            cur = newnode(v, pa);
            ch[pa][v > val[pa]] = cur;
        }
        splay(cur, 0);
    }

    int find(int v) {
        int cur = root;
        int res = 2; // val[2] == INF;
        while (cur) {
            if (val[cur] >= v && val[cur] < val[res])
                res = cur;
            cur = ch[cur][v >= val[cur]];
        }
        return res;
    }

    int get_k(int x, int k) {
        if (k <= size[ch[x][0]])
            return get_k(ch[x][0], k);
        else if (k <= size[ch[x][0]] + cnt[x])
            return val[x];
        else
            return get_k(ch[x][1], k - size[ch[x][0]] - cnt[x]);
    }
} T;

int main() {
    int n, m, delta = 0;
    scanf("%d%d", &n, &m);
    char op[2];
    int x;

    T.insert(-INF), T.insert(INF);
    int tot = 0;
    while (n--) {
        scanf("%s%d", op, &x);
        if (*op == 'I') {
            if (x < m) continue;
            T.insert(x - delta);
            tot++;
        } else if (*op == 'A') {
            delta += x;
        } else if (*op == 'S') {
            delta -= x;

            int R = T.find(m - delta);
            T.splay(1, 0);
            T.splay(R, 1);
            T.ch[R][0] = 0;
            T.maintain(R), T.maintain(1);
        } else if (*op == 'F') {
            if (x > T.size[T.root] - 2) {
                printf("-1\n");
            } else {
                int ans = T.get_k(T.root, T.size[T.root] - x) + delta;
                printf("%d\n", ans);
            }
        }
    }

    printf("%d\n", tot + 2 - T.size[T.root]);

    return 0;
}