/*
    Created by rdstihz at 2022-08-17 14:43:09
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int maxn = 100;
LL f[maxn], s[maxn];
map<LL, int> mp;

void init() {
    f[0] = f[1] = 1;
    s[0] = 1;
    s[1] = 2;
    for (int i = 2; i <= 50; i++) {
        f[i] = f[i - 1] + f[i - 2];
        s[i] = s[i - 1] + f[i];
    }

    for (int i = 0; i <= 50; i++) {
        mp[s[i]] = i;
    }
}

set<PII> Q;

bool dfs(int i, int lst) {
    if (i == 0) {
        auto node = *Q.rbegin();
        if (node.first == 1 && node.second != lst)
            return true;
        else
            return false;
    }

    // 1. 堆顶
    if (Q.size()) {
        auto u = *Q.rbegin();
        if (u.second != lst) {
            Q.erase(u);

            if (u.first < f[i]) {
                return false;
            } else if (u.first == f[i]) {
                if (dfs(i - 1, u.second)) return true;
            } else if (u.first > f[i]) {
                auto v = make_pair(u.first - f[i], u.second);
                Q.insert(v);
                if (dfs(i - 1, u.second)) return true;
                Q.erase(v);
            }
            Q.insert(u);
        }
    }

    if (Q.size() >= 2) {
        auto it = Q.rbegin();
        it++;

        auto u = *it;
        if (u.second != lst) {
            Q.erase(u);

            if (u.first < f[i]) {
                return false;
            } else if (u.first == f[i]) {
                if (dfs(i - 1, u.second)) return true;
            } else if (u.first > f[i]) {
                auto v = make_pair(u.first - f[i], u.second);
                Q.insert(v);
                if (dfs(i - 1, u.second)) return true;
                Q.erase(v);
            }
            Q.insert(u);
        }
    }

    return false;
}

void solve() {
    LL S = 0;
    int n, k;
    scanf("%d", &k);

    Q.clear();
    for (int i = 1; i <= k; i++) {
        int x;
        scanf("%d", &x);
        S += x;
        Q.insert(make_pair(x, i));
    }

    if (!mp.count(S)) {
        printf("NO\n");
        return;
    }

    n = mp[S];

    bool ans = dfs(n, -1);
    if (ans) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}