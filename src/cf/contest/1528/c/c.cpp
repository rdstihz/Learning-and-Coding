/*
    Created by rdstihz at 2021-08-10 16:23:13
*/

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int maxn = 300000 + 100;

vector<int> G1[maxn], G2[maxn];

int ts, st[maxn], ed[maxn], ans;

void dfs1(int u) {
    st[u] = ++ts;
    for (int v : G2[u])
        dfs1(v);
    ed[u] = ++ts;
}
set<PII> S;

// -2: 存在u的儿子，不加入u
// -1: 不存在u的儿子，不存在v的父节点, 直接加入u
// 其它v: v是u的祖先，删除v再加入u
int add(int u) {
    auto it = S.lower_bound(make_pair(st[u], u));
    if (it != S.end() && ed[u] > ed[it->second]) return -2;
    if (it == S.begin()) return -1;
    it--;
    int res = it->second;
    if (ed[res] < ed[u]) return -1;
    S.erase(it);
    return res;
}

void dfs2(int u) {
    int t = add(u);
    if (t != -2) S.insert(make_pair(st[u], u));
    ans = max(ans, (int)S.size());
    for (int v : G1[u])
        dfs2(v);
    if (t != -2) {
        S.erase(make_pair(st[u], u));
        if (t > 0) S.insert(make_pair(st[t], t));
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    int v;
    for (int i = 1; i <= n; i++) {
        G1[i].clear(), G2[i].clear();
    }

    for (int i = 2; i <= n; i++) {
        scanf("%d", &v);
        G1[v].push_back(i);
    }
    for (int i = 2; i <= n; i++) {
        scanf("%d", &v);
        G2[v].push_back(i);
    }

    ts = 0;
    dfs1(1);
    ans = 0, S.clear();
    dfs2(1);
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}