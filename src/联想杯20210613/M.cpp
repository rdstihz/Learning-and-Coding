#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> PIII;

vector<PIII> G[26];
bool vis[40][40][40];
char ans[100], top;
char ss[40][40][40];
bool used[40];

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m, h;
        scanf("%d%d%d", &n, &m, &h);

        for (int i = 0; i < 26; i++)
            G[i].clear();
        top = 0;
        memset(vis, 0, sizeof(vis));
        memset(used, 0, sizeof(used));

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= m; k++) {
                    char ch = getchar();
                    while (ch < 'A' || ch > 'Z')
                        ch = getchar();

                    ss[h - i + 1][j][k] = ch;
                    G[ch - 'A'].push_back(make_pair(h - i + 1, make_pair(j, k)));
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++)
            if (G[i].size()) cnt++;

        bool solve = true;

        while (cnt--) {
            int p = -1;

            for (int i = 25; i >= 0; i--) {
                if (!G[i].size()) continue;
                if (used[i]) continue;
                bool ok = true;
                for (auto& x : G[i]) {
                    if (x.first == 1) continue;
                    if (!vis[x.first - 1][x.second.first][x.second.second] && ss[x.first - 1][x.second.first][x.second.second] != 'A' + i) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {

                    for (auto& x : G[i]) {
                        vis[x.first][x.second.first][x.second.second] = true;
                    }

                    p = i;
                    used[p] = true;
                    break;
                }
            }

            if (p == -1) {
                solve = false;
                break;
            } else {
                ans[++top] = 'A' + p;
            }
        }

        if (!solve) {
            printf("-1\n");
        } else {
            for (int i = 1; i <= top; i++)
                printf("%c", ans[i]);
            printf("\n");
        }
    }

    return 0;
}