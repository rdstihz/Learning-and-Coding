#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int maxn = 1000000 + 100;
char s[2 * maxn];
int cnt[maxn], p, tot;
int ans[maxn];
vector<int> G[maxn];
priority_queue<PII> Q;

void dfs(int u) {
    while (s[p] == '(') {
        p++;
        tot++;
        G[u].push_back(tot);
        dfs(tot);
    }
    p++;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int v;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v);
        cnt[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i]) {
            Q.push(make_pair(cnt[i], i));
        }
    }
    dfs(0);
    // for (int i = 0; i <= n; i++) {
    //     printf("%d: ", i);
    //     for (int v : G[i])
    //         printf("%d ", v);
    //     printf("\n");
    // }

    queue<PII> temp;
    for (int i = 0; i <= n; i++) {
        if (G[i].size()) {
            if (Q.size() < G[i].size()) {
                printf("NO\n");
                return 0;
            }

            for (int v : G[i]) {
                PII t = Q.top();
                Q.pop();
                ans[v] = t.second;
                t.first--;
                if (t.first > 0) temp.push(t);
            }

            while (temp.size()) {
                Q.push(temp.front());
                temp.pop();
            }
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}