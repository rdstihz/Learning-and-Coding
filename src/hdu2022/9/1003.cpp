#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
int a[maxn];
int p[maxn];    //上一个>a[i]的数的位置
int n, q;
int len;
int ans[maxn];
inline int get(int i) {
    return i / len;
}

struct Query{
    int id;
    int l, r;
    bool operator<(const Query& phs) {
        if (get(l) == get(phs.l)) {
            if(get(l) % 2 == 0) return r < phs.r;
            else return r > phs.r;
        }
        return get(l) < get(phs.l);
    }
} query[maxn];


struct Tree{
    int C[maxn];

    int lowbit(int x) {
        return x & -x;
    }

    void add(int p, int v) {
        for(;p <= n; p += lowbit(p))
            C[p] += v;
    }

    int sum(int p) {
        int res = 0;
        for(;p;p -= lowbit(p))
            res += C[p];
        return res;
    }

}T;

multiset<int> S;

void add(int i) {
    if(p[i] == -1) return;
    T.add(p[i], 1);
}

void del(int i) {
    if(p[i] == -1) return;
    T.add(p[i], -1);
}

void solve() {
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    a[0] = 1e8;
    a[n + 1] = 0;

    for(int i = 1; i <= n; i++) {
        int j = i - 1;
        while(a[j] <= a[i]) j = p[j];
        p[i] = j;
    }

    for(int i = 1; i <= n; i++) {
        if(a[i] <= a[i + 1]) p[i] = -1;
        else p[i]++;
    }



    for(int i = 1; i <= q; i++) {
        query[i].id = i;
        scanf("%d%d", &query[i].l, &query[i].r);
    }
    len = sqrt((double) n * n / q);
    sort(query + 1, query + 1 + q);


    int i = 1, j = 0;
    int res = 0;
    for (int k = 1; k <= q; k++) {
        int l = query[k].l, r = query[k].r, id = query[k].id;
        while (i < l)
            del(i++);
        while (i > l)
            add(--i);
        while (j < r)
            add(++j);
        while (j > r)
            del(j--);
        
        ans[id] = T.sum(l);
        if(p[r] != -1 && p[r] <= l) ans[id]--;
    
    }


    for(int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
    

    for(int i = 0; i <= n; i++) {
        ans[i] = 0;
        p[i] = 0;
        T.C[i] = 0;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--)
        solve();
}
/*
2
10 5
3 7 9 2 6 4 5 8 10 1
1 10
2 6
7 9
4 9
3 3
10 5
3 7 9 2 6 4 5 8 10 1
1 10
2 6
7 9
4 9
3 3
*/