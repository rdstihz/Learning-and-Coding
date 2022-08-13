#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;

struct Node {
    int l, r;
    bool operator<(const Node& phs) {
        if(l == phs.l) return r < phs.r;
        return l < phs.l;
    }
} a[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].l, &a[i].r);
    
    sort(a + 1, a + 1 + n);

    int ans = 0;
    for(int i = 2; i <= n; i++) {
        if(a[i].l <= a[i - 1].r) {
            printf("%d\n", i - 2);
            return;
        }
    }
    printf("%d\n", n);
}


int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}