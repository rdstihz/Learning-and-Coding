/*
    Created by godlei at 2022-06-16 23:18:31
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 200000 + 100;
vector<int> G[maxn];
int p[maxn];
LL a[maxn], l[maxn], r[maxn];
int ans;


void dfs(int u) {
    a[u] = 0;
    for(int v : G[u]) {
        dfs(v);
        a[u] += a[v];
    }

    if(a[u] < l[u]) {
        ans ++;
        a[u] = r[u];
    }else if(a[u] > r[u]) {
        a[u] = r[u];
    }
}


void solve() {
    
    int n;
    scanf("%d", &n);
    
    ans = 0;
    for(int i = 1; i <= n; i++)  {
        G[i].clear();
        a[i] = 0;
    }
    for(int i = 2; i <= n; i++) {
        scanf("%d", p + i);
        G[p[i]].push_back(i);
    } 
    for(int i = 1; i <= n; i++) {
        scanf("%lld%lld", l + i, r + i);
    }

    dfs(1);


    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        
        solve();
    }
    return 0;
}