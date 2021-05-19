#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
const int INF = 0x3f3f3f3f;

//二叉搜索树 + 大根椎
struct Treap {

    int lc[maxn], rc[maxn];
    int val[maxn], rnd[maxn];
    int size[maxn], cnt[maxn];
    int tot, root;

    void maintain(int o) {
        size[o] = cnt[o] + size[lc[o]] + size[rc[o]];
    }

    int newnode(int v) {
        tot++;
        val[tot] = v, rnd[tot] = rand();
        size[tot] = cnt[tot] = 1;
        return tot;
    }

    void zig(int& p) { //右旋
        int q = lc[p];
        lc[p] = rc[q];
        rc[q] = p;
        p = q;
        maintain(rc[p]);
        maintain(p);
    }

    void zag(int& p) { //左旋
        int q = rc[p];
        rc[p] = lc[q];
        lc[q] = p;
        p = q;
        maintain(lc[p]);
        maintain(p);
    }

    void build() {
        root = newnode(-INF);
        insert(root, INF);
    }

    void insert(int& p, int v) {
        if (!p) {
            p = newnode(v);
            return;
        }
        if (val[p] == v) {
            cnt[p]++;
            size[p]++;
            return;
        }

        if (v < val[p]) {
            insert(lc[p], v);
            if (rnd[lc[p]] > rnd[p])
                zig(p);
        } else {
            insert(rc[p], v);
            if (rnd[rc[p]] > rnd[p])
                zag(p);
        }
        maintain(p);
    }

    void remove(int& p, int v) {
        if (!p) return;
        if (v == val[p]) {
            if (cnt[p] > 1) {
                cnt[p]--;
                size[p]--;
                return;
            }
            if (lc[p] && rc[p]) { //有两个儿子: 将p旋到下层
                if (rnd[lc[p]] > rnd[rc[p]]) {
                    zig(p);
                    remove(rc[p], v);
                } else {
                    zag(p);
                    remove(lc[p], v);
                }
            } else { //只有一个儿子（或没有儿子） ， 直接用儿子替代p
                p = lc[p] | rc[p];
            }
            maintain(p);
            return;
        }

        if (v < val[p]) {
            remove(lc[p], v);
        } else {
            remove(rc[p], v);
        }
        maintain(p);
    }

    int getRankByVal(int& p, int v) {
        if (!p) return 1;
        if (v == val[p])
            return size[lc[p]] + 1;
        else if (v < val[p])
            return getRankByVal(lc[p], v);
        else
            return getRankByVal(rc[p], v) + size[lc[p]] + cnt[p];
    }

    int getValByRank(int& p, int k) {
        if (k <= size[lc[p]])
            return getValByRank(lc[p], k);
        else if (k <= size[lc[p]] + cnt[p])
            return val[p];
        else
            return getValByRank(rc[p], k - size[lc[p]] - cnt[p]);
    }

    int getPre(int v) { //查询前驱
        int cur = root;
        int res = 1; // val[1] = -INF
        while (cur) {
            if (val[cur] < v && val[cur] > val[res]) res = cur;
            cur = val[cur] < v ? rc[cur] : lc[cur];
        }
        return val[res];
    }

    int getNxt(int v) {
        int cur = root;
        int res = 2; // val[2] = INF
        while (cur) {
            if (val[cur] > v && val[cur] < val[res]) res = cur;
            cur = val[cur] > v ? lc[cur] : rc[cur];
        }
        return val[res];
    }

    //------------
    void print(int p) {
        if (lc[p]) print(lc[p]);
        //cout << "( " << p << " " << val[p] << " " << rnd[p] << " " << lc[p] << " " << rc[p] << " " << size[p] << " " << cnt[p] << " )" << endl;
        cout << val[p] << " " << cnt[p] << endl;
        if (rc[p]) print(rc[p]);
    }
    //------------

} T;

int main1() {
    T.build();

    int x;
    for (int i = 1; i <= 5; i++) {
        cin >> x;
        T.insert(T.root, x);
        T.print(T.root);
        cout << T.size[T.root] << endl;
        cout << "--------------" << endl;
    }
    for (int i = 1; i <= 5; i++) {
        cin >> x;
        T.remove(T.root, x);
        T.print(T.root);
        cout << T.size[T.root] << endl;
        cout << "--------------" << endl;
    }
    return 0;
}

int main() {
    int m;
    cin >> m;
    int op, x;
    T.build();
    while (m--) {
        cin >> op >> x;
        if (op == 1) {
            T.insert(T.root, x);
        } else if (op == 2) {
            T.remove(T.root, x);
        } else if (op == 3) {
            cout << T.getRankByVal(T.root, x) - 1 << endl;
        } else if (op == 4) {
            cout << T.getValByRank(T.root, x + 1) << endl;
        } else if (op == 5) {
            cout << T.getPre(x) << endl;
        } else if (op == 6) {
            cout << T.getNxt(x) << endl;
        }
    }

    return 0;
}