/*
    Created by godlei at 2021-12-01 23:11:33
*/

#include <bits/stdc++.h>
#define lc (o << 1)
#define rc (o << 1 | 1)
using namespace std;
typedef long long LL;
const int maxn = 500000 + 100;
const int P = 998244353;
int a[maxn];
int cnt[maxn];
LL B[maxn];

struct SegmentTree{
    int sumv[maxn * 4];
    LL prodv[maxn * 4];

    void maintain(int o) {
        sumv[o] = sumv[lc] + sumv[rc];
        prodv[o] = prodv[lc] * prodv[rc] % P;
    }

    void build(int o,int L,int R ){
        if(L == R) {
            sumv[o] = 0;
            prodv[o] = 0;
            return;
        }
        int M = L + R >> 1;
        build(lc, L, M);
        build(rc, M + 1, R);
        maintain(o);
    }

    void add(int o,int L,int R,int p) {
        if(L == R ) {
            sumv[o]++;
            prodv[o]++;
            return;
        }
        int M = L + R >> 1;
        if(p <= M) add(lc, L, M, p);
        else add(rc, M + 1, R, p);
        maintain(o);
    }

    int query_sum(int o,int L,int R,int l,int r) {
        if(l <= L && r >= R) {
            return sumv[o];
        }
        int res = 0;
        int M = L + R >> 1;
        if(l <= M) res = (res + query_sum(lc, L, M + 1, l, r)) % P;
        if(r > M) res = (res + query_sum(rc, M + 1, R, l, r) ) % P;
        return res;
    }
    LL query_prod(int o,int L,int R,int l,int r) {
        if(l <= L && r >= R) {
            return prodv[o];
        }
        LL res = 1;
        int M = L + R >> 1;
        if(l <= M) res = (res * query_prod(lc, L, M + 1, l, r)) % P;
        if(r > M) res = (res * query_prod(rc, M + 1, R, l, r) ) % P;
        return res;
    }

} T;

void solve() {
    int n;
    scanf("%d", &n);
    LL res = 0;
    T.build(1, 1, n + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        a[i]++;
        
        // mex = a[i] - 1
        if(a[i] > 1) {
            LL x = (a[i] - 2 >= 1) ? T.query_prod(1, 1, n + 1, 1, a[i] - 2) : 1;
            int y = (a[i] - 2 >= 1) ? T.query_sum(1, 1, n + 1, 1, a[i] - 2) : 0;
            int f = y - a[i] + 2 + 
        }
        //mex = a[i] + 1
        LL x = T.query_prod(1, 1, n + 1, 1, a[i] - 1);
        LL y = T.query_sum(1, 1, n + 1, 1, a[i] - 1);
        res = (res + x * B[y - a[i] + 1 + cnt[a[i]] + cnt[a[i]] + 2] % P ) % P;
        
        cnt[a[i]]++;
    }
    
    
    printf("%lld\n", res);
    for(int i = 1; i <= n; i++) {
        cnt[a[i]]--;
    }
}

int main() {
    int T;
    B[0] = 1;
    for(int i = 1; i <= 500000; i++) {
        B[i] = 2 * B[i - 1] % P;
    }
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}