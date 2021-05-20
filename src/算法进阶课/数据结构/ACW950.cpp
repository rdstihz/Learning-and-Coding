#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;

struct Splay {
    int val[maxn], addv[maxn];
    int ch[maxn][2], p[maxn];
    int size[maxn], cnt[maxn];
    int tot, root;

    void pushdown(int x) {
        if (ch[x][0])
            val[ch[x][0]] += addv[x], addv[ch[x][0]] += addv[x];
        if (ch[x][1])
            val[ch[x][1]] += addv[x], addv[ch[x][1]] += addv[x];
        addv[x] = 0;
    }

    void maintain(int x) {
        size[x] = cnt[x] + size[ch[x][0]] + size[ch[x][1]];
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

} T;

int main() {

    return 0;
}