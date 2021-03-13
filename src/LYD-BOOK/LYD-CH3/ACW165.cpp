#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 20;

int n;
int c[maxn], w;
int ans;

int cap[maxn];

void dfs(int cur, int cnt) {
    if (cur > n) {
        ans = min(ans, cnt);
    }
    if (cnt >= ans) return;

    for (int i = 1; i <= cnt; i++)
        if (cap[i] + c[cur] <= w) {
            cap[i] += c[cur];
            dfs(cur + 1, cnt);
            cap[i] -= c[cur];
        }

    cap[cnt + 1] = c[cur];
    dfs(cur + 1, cnt + 1);
}

int main() {
    scanf("%d%d", &n, &w);
    ans = n;

    for (int i = 1; i <= n; i++) {
        scanf("%d", c + i);
    }
    sort(c + 1, c + 1 + n,greater<int>() );

    dfs(1, 0);

    printf("%d\n",ans);

    return 0;
}