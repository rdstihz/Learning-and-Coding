#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
const int INF = 0x7fffffff;

struct Treap {
    int l, r;
    int val, h;
    int cnt, size;
} node[maxn];
int tot;
int root;

void maintain(int o) {
    node[o].size = node[node[o].l].size + node[node[o].r].size + node[o].cnt;
}

int newnode(int val) {
    tot++;
    node[tot].val = val;
    node[tot].h = rand();
    node[tot].cnt = node[tot].size = 1;
    return tot;
}

void zig(int& p) { //右旋
    int q = node[p].l;
    node[p].l = node[q].r;
    node[q].r = p;

    p = q;
    maintain(node[p].r);
    maintain(p);
}

void zag(int& p) { //左旋
    int q = node[p].r;
    node[p].r = node[q].l;
    node[q].l = p;

    p = q;
    maintain(node[p].l);
    maintain(p);
}

void build() {
    root = newnode(-INF);
    node[root].r = newnode(INF);
    maintain(root);
}

int readIn() {
    int x = 0;
    char c = getchar();
    int flag = 1;
    while (c < '0' || c > '9') {
        if (c == '-') flag = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * flag;
}

void insert(int& p, int val) {
    if (p == 0) {
        p = newnode(val);
        return;
    } else if (node[p].val == val) {
        node[p].cnt++;
        maintain(p);
        return;
    }

    if (val < node[p].val) {
        insert(node[p].l, val);
        if (node[p].h < node[node[p].l].h)
            zig(p);
    } else {
        insert(node[p].r, val);
        if (node[p].h < node[node[p].r].h)
            zag(p);
    }
    maintain(p);
}

void remove(int& p, int val) {
    if (p == 0) return;

    if (node[p].val == val) {
        if (node[p].cnt > 1) {
            node[p].cnt--;
            return;
        }
        

        return;
    }
    if (val < node[p].val)
        remove(node[p].l, val);
    else
        remove(node[p].r, val);
    maintain(p);
}

int main() {
    int n = readIn();
    build();

    insert(root, 5);
    insert(root, 6);
    insert(root, 8);
    insert(root, 6);
    printf("%d\n", root);
    for (int i = 0; i <= n; i++) {
        printf("%d: %d %d %d %d %d %d\n", i, node[i].l, node[i].r, node[i].val, node[i].h, node[i].size, node[i].cnt);
    }

    return 0;
}