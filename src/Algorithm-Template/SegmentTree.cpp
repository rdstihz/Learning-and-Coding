#include <iostream>

#define lc (o<<1)
#define rc (o<<1|1)


using namespace std;

typedef long long  LL;
const int maxn = 400000 + 100;

LL v[maxn];

struct SegmentTree {
    LL sumv[maxn], addv[maxn];

    void pushdown(int o,int L,int R) {
        int M = L+R>>1;
        addv[lc] += addv[o];
        sumv[lc] += addv[o] *( M-L +1);

        addv[rc] += addv[o];
        sumv[rc] += addv[o] *(R-M);

        addv[o] = 0;

    }

    void maintain(int o) {
        sumv[o] = sumv[lc] + sumv[rc];
    }

    void build(int o, int L, int R) {
        if (L == R) {
            sumv[o] = v[L];
            return;
        }
        int M = L + R >> 1;
        build(lc, L, M);
        build(rc, M + 1, R);
        maintain(o);
    }

    LL query(int o, int L, int R, int l, int r) {
        if (l <= L && r >= R) return sumv[o];
        pushdown(o,L,R);
        int M = L + R >> 1;
        LL sum = 0;
        if(l <= M) sum += query(lc,L,M,l,r);
        if(r > M) sum += query(rc,M+1,R,l,r);
        return sum;
    }

    void update(int o,int L,int R,int l,int r,LL x){
        if(l <= L && r >= R){
            addv[o] += x;
            sumv[o] += (R-L+1) * x;
            return;
        }
        pushdown(o,L,R);
        int M = L+R>>1;
        if(l <= M) update(lc,L,M,l,r,x);
        if(r > M ) update(rc,M+1,R,l,r,x);
        maintain(o);
    }


} T;

int main() {
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++) cin >> v[i];
    T.build(1,1,n);

    int op,l,r;
    LL x;
    while(m--){
        cin >> op;
        if(op == 1){
            cin >> l >> r >> x;
            T.update(1,1,n,l,r,x);
        }else if(op == 2){
            cin >> l >> r;
            cout << T.query(1,1,n,l,r) << endl;
        }

    }


    return 0;
}
