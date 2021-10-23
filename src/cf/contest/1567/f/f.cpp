/*
    Created by rdstihz at 2021-10-20 21:52:16
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 510;
char s[maxn][maxn];
int a[maxn][maxn];
int color[maxn][maxn];
int n, m;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

void dfs(int x, int y, int c) {
    color[x][y] = c;
    for (int k = 0; k < 8; k++) {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (s[xx][yy] == '.' && !color[xx][yy])
            dfs(xx, yy, c);
    }
}

int to[50000], nxt[50000], fir[50000], tot;

void add_edge(int a, int b) {
    tot++;
    to[tot] = b, nxt[tot] = fir[a], fir[a] = tot;
}

int vis[maxn * maxn];

void dfs1(int u, int f, int c) {
    vis[u] = c;
    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        if (v == f || vis[v]) continue;
        dfs1(v, u, 3 - c);
    }
}

int main() {

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '.') continue;
            int k = (s[i - 1][j] == '.') + (s[i + 1][j] == '.') + (s[i][j - 1] == '.') + (s[i][j + 1] == '.');
            if (k % 2) {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (!color[i][j] && s[i][j] == '.')
                dfs(i, j, ++cnt);
        }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'X' && s[i - 1][j] == '.' && s[i + 1][j] == '.' && color[i - 1][j] != color[i + 1][j])
                add_edge(color[i - 1][j], color[i + 1][j]);
            if (s[i][j] == 'X' && s[i][j - 1] == '.' && s[i][j + 1] == '.' && color[i][j - 1] != color[i][j + 1])
                add_edge(color[i][j - 1], color[i][j + 1]);
        }
    }

    for (int i = 1; i <= cnt; i++)
        if (!vis[i])
            dfs1(i, -1, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '.')
                a[i][j] = (j + vis[color[i][j]]) % 2 ? 1 : 4;
        }
    }

    bool flag = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'X') {
                int v = 0;
                for (int k = 0; k < 4; k++)
                    if (s[i + dx[k]][j + dy[k]] == '.')
                        v += a[i + dx[k]][j + dy[k]];
                a[i][j] = v;
                if (v % 5) {
                    flag = true;
                }
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}

/*
12 23
.......................
...XXXXX..XXXXXXX.XX...
...X...X..X.....X.XXX..
...XXXXX..XXXXXXX..XXX.
........XX..........XX.
........XX.............
.X.X.X.X..XXXXX.XXXXX..
..X.X.X...X...X.X...X..
.X.X.X.X..X.XXXXXXX.X..
..X.X.X...X.X.X.X.X.X..
.X.X.X.X..XXXXX.XXXXX..
............X.....X....

7 6
......
.X.X..
..X.X.
.X.X..
..X.X.
.X.X..
......
*/
