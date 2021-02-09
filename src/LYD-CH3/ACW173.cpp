#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1005;
const int INF = 0x3f3f3f3f;

int d[maxn][maxn];
char str[maxn][maxn];

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%s", str[i]);

    memset(d, 0x3f, sizeof(d));

    queue<pair<int, int>> Q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (str[i][j] == '1') {
                d[i][j] = 0;
                Q.push(make_pair(i, j));
            }

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && d[xx][yy] == INF) {
                d[xx][yy] = d[x][y] + 1;
                Q.push(make_pair(xx, yy));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", d[i][j]);
        printf("\n");
    }

    return 0;
}