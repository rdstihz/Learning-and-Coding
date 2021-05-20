#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;

int n, m;

struct Splay {
    int val[maxn], size[maxn];
    bool rev[maxn];
    int ch[maxn][2], p[maxn];
    int root, tot;

    int newnode(int v) {
        tot++;
        val[tot] = v, size[tot] = 1;
        return tot;
    }

    void maintain(int x) {
        size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
    }

    void pushdown(int x) {
        if (rev[x]) {
            swap(ch[x][0], ch[x][1]);
            rev[ch[x][0]] ^= 1;
            rev[ch[x][1]] ^= 1;

            rev[x] ^= 1;
        }
    }
    int chk(int x) {
        return ch[p[x]][1] == x;
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

    void insert(int v) {
        int cur = root, pa = 0;
        while (cur)
            pa = cur, cur = ch[cur][v > val[cur]];
        cur = newnode(v);
        if (pa) ch[pa][v > val[pa]] = cur, p[cur] = pa;
        splay(cur, 0);
    }

    int find_k(int k) {
        int cur = root;
        while (true) {
            pushdown(cur);
            if (k <= size[ch[cur][0]])
                cur = ch[cur][0];
            else if (k <= size[ch[cur][0]] + 1)
                return cur;
            else
                k -= size[ch[cur][0]] + 1, cur = ch[cur][1];
        }
    }

    void print(int x) {
        pushdown(x);
        if (ch[x][0]) print(ch[x][0]);
        if (val[x] >= 1 && val[x] <= n) printf("%d ", val[x]);
        if (ch[x][1]) print(ch[x][1]);
    }

} T;
// int main() {
//     T.insert(1);
//     cout << T.root << endl;
//     T.print(T.root);
// }
int main() {

    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 1; i++)
        T.insert(i);

    int l, r;
    while (m--) {
        scanf("%d%d", &l, &r);
        l = T.find_k(l);
        r = T.find_k(r + 2);
        T.splay(l, 0);
        T.splay(r, l);
        T.rev[T.ch[r][0]] ^= 1;

        //T.print(T.root);
    }
    T.print(T.root);
    printf("\n");

    return 0;
}