#include <bits/stdc++.h>
#define lc (o << 1)
#define rc (o << 1 | 1)
using namespace std;

const int maxn = 50000 + 10;

int n, m;
int intersection(int a,int b,int c,int d) {
    return min(b, d) - max(a, c) + 1;
}

//内层线段树节点
struct Node{
    int lch, rch, sumv, addv;
} node[maxn * 17 * 17];
int tot;
//内层线段树函数
struct TreeIn{
    void update(int o,int L,int R,int l, int r,int v) {
        node[o].sumv += v * intersection(L, R, l, r);
        if(l <= L && r >= R) {
            node[o].addv += v;
            return;
        }
        int M = L + R >> 1;
        if(l <= M) {
            if(!node[o].lch) node[o].lch = ++tot;
            update(node[o].lch, L, M, l, r, v);
        }
        if(r > M) {
            if(!node[o].rch) node[o].rch = ++tot;
            update(node[o].rch, M + 1, R, l, r, v);
        }
    }
    
    int query(int o,int L,int R,int l, int r, int add) {
        if(l <= L && r >= R) {
            return node[o].sumv + add * (R - L + 1);
        }
        add += node[o].addv;
        int M = L + R >> 1, res = 0;
        if(l <= M) {
            if(!node[o].lch) res += add * intersection(L, M, l, r);
            else res += query(node[o].lch, L, M, l, r, add);
        }if(r > M) {
            if(!node[o].rch) res += add * intersection(M + 1, R, l, r);
            else res += query(node[o].rch, M + 1, R, l, r, add);
        }
        return res;
    }
    
} T2;

//外层线段树
struct TreeOut{
    int root[maxn * 4];
    
    void build(int o,int L,int R) {
        root[o] = ++tot;
        if(L == R) return ;
        int M = L + R >> 1;
        build(lc, L, M), build(rc, M + 1, R);
    }
    
    void update(int o,int L,int R,int a, int b,int c) {
        T2.update(root[o], 1, n, a, b, 1);
        if(L == R) return;
        int M = L + R >> 1;
        if(c <= M) update(lc, L, M, a, b, c);
        else update(rc, M + 1, R, a, b, c);
    }
    
    int query(int o,int L,int R,int a, int b,int c) {
        if(L == R) return L;
        int M = L + R >> 1;
        int k = T2.query(root[rc], 1, n, a, b, 0);
        if(k >= c) return query(rc, M + 1, R, a, b, c);
        else return query(lc, L, M, a, b, c - k);
    }
} T1;

struct Ops {
    int op, a, b, c;
} ops[maxn];
vector<int> nums;

int get(int v) {
    return lower_bound(nums.begin(), nums.end(), v) - nums.begin() + 1;
    
}

int main() {
    
    
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &ops[i].op, &ops[i].a, &ops[i].b, &ops[i].c);
        if(ops[i].op == 1) nums.push_back(ops[i].c);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    T1.build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        int op = ops[i].op, a = ops[i].a, b = ops[i].b, c = ops[i].c;
        if(op == 1) {
            T1.update(1, 1, n, a, b, get(c));
        }else if(op == 2) {
            printf("%d\n", nums[T1.query(1, 1, n, a, b, c) - 1]);
        }
    }
    return 0;
}