#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1000000 + 100;
const int P = 998244353;
char s[maxn];
int fail[maxn];
int n, k;

vector<int> G[maxn];

int cnt[maxn];
int ans[maxn];
int q[maxn], l, r;


void dfs(int i) {
    cnt[2 * i % k] ++;
    q[++r] = i;

    int bl = l;
    while(l < r && q[l + 1] * 2 <= i) {
        cnt[2 * q[l + 1] % k] --;
        l++;
    }
    
    ans[i] += cnt[i % k];

    for(int v : G[i]) {
        dfs(v);
    }

    while(l > bl) {
        l--;
        cnt[2 * q[l + 1] % k]++;
    }

    r--;
    cnt[2 * i % k]--;
}


void solve() {
    scanf("%s", s + 1);
    scanf("%d", &k);
    n = strlen(s + 1);
    fail[1] = 0;
    for(int i = 2; i <= n; i++) {
        int j = fail[i - 1];
        while(j && s[j + 1] != s[i]) j = fail[j];
        if(s[j + 1] == s[i]) fail[i] = j + 1;
        else fail[i] = 0;
    }

    for(int i = 0; i <= n; i++) {
        cnt[i] = 0;
        ans[i] = 1;
        G[i].clear();
    }

    for(int i = 1; i <= n; i++) {
        G[fail[i]].push_back(i);
    }
    l = r = 0;
    dfs(0);

    int res = 1;
    for(int i = 1; i <= n; i++) {
        res = 1ll * res * ans[i] % P;
    }
    printf("%d\n", res);
}


int main() {
    int T;
    scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}