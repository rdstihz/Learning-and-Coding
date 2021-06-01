#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

#define lc ch[x][0]
#define rc ch[x][1]

using namespace std;

const int maxn = 500000 + 100;
int w[maxn];
struct Splay {
    int ch[maxn][2], p[maxn];
    int val[maxn], sumv[maxn];
    int maxsum[maxn], presum[maxn], sufsum[maxn];
    bool rev[maxn], setd[maxn];
    int size[maxn];
    int root, tot;
    queue<int> buff;

    void flip(int x) {
        rev[x] ^= 1;
        swap(lc, rc);
        swap(presum[x], sufsum[x]);
    }
    void setto(int x, int v) {
        setd[x] = true;
        val[x] = v;
        sumv[x] = v * size[x];
        if (v > 0) {
            maxsum[x] = presum[x] = sufsum[x] = v * size[x];
        } else {
            maxsum[x] = v;
            presum[x] = sufsum[x] = 0;
        }
    }

    void maintain(int x) {
        size[x] = 1 + size[lc] + size[rc];
        sumv[x] = sumv[lc] + sumv[rc] + val[x];
        presum[x] = max(presum[lc], sumv[lc] + val[x] + presum[rc]);
        sufsum[x] = max(sufsum[rc], sumv[rc] + val[x] + sufsum[lc]);
        maxsum[x] = max(max(maxsum[lc], maxsum[rc]), sufsum[lc] + val[x] + presum[rc]);
    }

    void pushdown(int x) {
        if (setd[x]) {
            setd[x] = rev[x] = false;
            if (lc) setto(lc, val[x]);
            if (rc) setto(rc, val[x]);
        }

        if (rev[x]) {
            rev[x] = false;
            if (lc) flip(lc);
            if (rc) flip(rc);
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

    int newnode(int v, int _p) {
        int x;
        if (buff.size())
            x = buff.front(), buff.pop();
        else
            x = ++tot;

        lc = rc = 0;
        p[x] = _p;

        size[x] = 1;
        val[x] = sumv[x] = maxsum[x] = v;
        presum[x] = sufsum[x] = v > 0 ? v : 0;
        rev[x] = setd[x] = false;
        return x;
    }

    int get_k(int k) {
        int x = root;
        while (x) {
            pushdown(x);
            if (k <= size[lc])
                x = lc;
            else if (k == size[lc] + 1)
                return x;
            else
                k -= size[lc] + 1, x = rc;
        }
        return -1;
    }

    int build(int l, int r, int _p) {
        int m = l + r >> 1;
        int x = newnode(w[m], _p);
        if (l < m) lc = build(l, m - 1, x);
        if (r > m) rc = build(m + 1, r, x);
        maintain(x);
        return x;
    }

    // void print(int x) {
    //     pushdown(x);
    //     if (lc) print(lc);
    //     if (val[x] > -10000) cout << val[x] << " ";
    //     if (rc) print(rc);
    // }
} T;

void dfs(int x) { //回收节点
    if (T.lc) dfs(T.lc);
    if (T.rc) dfs(T.rc);
    T.buff.push(x);
}

int readIn() {
    int x = 0;
    int flag = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            flag = -flag;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * flag;
}

int main() {
    int n, m;
    n = readIn(), m = readIn();
    for (int i = 1; i <= n; i++)
        w[i] = readIn();
    w[0] = w[n + 1] = -1e8;
    T.maxsum[0] = -1e8;

    T.root = T.build(0, n + 1, 0);

    char op[20];
    int pos, k, v;
    while (m--) {
        scanf("%s", op);
        if (!strcmp(op, "INSERT")) {
            pos = readIn(), k = readIn();
            for (int i = 1; i <= k; i++)
                w[i] = readIn();
            int l = T.get_k(pos + 1), r = T.get_k(pos + 2);
            T.splay(l, 0), T.splay(r, l);
            T.ch[r][0] = T.build(1, k, r);
            T.maintain(r), T.maintain(l);
        } else if (!strcmp(op, "DELETE")) {
            pos = readIn(), k = readIn();
            int l = T.get_k(pos), r = T.get_k(pos + k + 1);
            T.splay(l, 0), T.splay(r, l);
            dfs(T.ch[r][0]);
            T.ch[r][0] = 0;
            T.maintain(r), T.maintain(l);
        } else if (!strcmp(op, "MAKE-SAME")) {
            pos = readIn(), k = readIn(), v = readIn();
            int l = T.get_k(pos), r = T.get_k(pos + k + 1);
            T.splay(l, 0), T.splay(r, l);
            T.setto(T.ch[r][0], v);
            T.maintain(r), T.maintain(l);
        } else if (!strcmp(op, "REVERSE")) {
            pos = readIn(), k = readIn();
            int l = T.get_k(pos), r = T.get_k(pos + k + 1);
            T.splay(l, 0), T.splay(r, l);
            T.flip(T.ch[r][0]);
            T.maintain(r), T.maintain(l);
        } else if (!strcmp(op, "GET-SUM")) {
            pos = readIn(), k = readIn();
            int l = T.get_k(pos), r = T.get_k(pos + k + 1);
            T.splay(l, 0), T.splay(r, l);
            printf("%d\n", T.sumv[T.ch[r][0]]);
        } else if (!strcmp(op, "MAX-SUM")) {
            printf("%d\n", T.maxsum[T.root]);
        }
    }

    return 0;
}