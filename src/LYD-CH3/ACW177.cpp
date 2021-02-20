#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> PII;

const int maxn = 810;
const int INF = 0x3f3f3f3f;

char G[maxn][maxn];

int n, m;

queue<PII> qM, qG, qZ;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int dZ[maxn][maxn]; //鬼到达每点的时间
int dM[maxn][maxn];
int dG[maxn][maxn];

void bfsZ() {
    while (qZ.size()) {
        int x = qZ.front().first, y = qZ.front().second;
        qZ.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
                if (dZ[xx][yy] > dZ[x][y] + 1) {
                    dZ[xx][yy] = dZ[x][y] + 1;
                    qZ.push({xx, yy});
                }
            }
        }
    }
}

bool legal(int x, int y, int t) {
    return x >= 1 && x <= n && y >= 1 && y <= m && dZ[x][y] > 2 * t && G[x][y] != 'X';
}

int solve() {
    bfsZ();

    int t = 0;
    while (qM.size() || qG.size()) {
        //M更新三层
        t++;
        int x, y;
        int xx, yy;
        while (qM.size() && dM[x = qM.front().first][y = qM.front().second] < 3 * t) {
            qM.pop();
            if (dZ[x][y] <= 2 * t) continue;
            for (int i = 0; i < 4; i++) {
                xx = x + dx[i], yy = y + dy[i];

                if (legal(xx, yy, t) && dM[xx][yy] > dM[x][y] + 1) {
                    dM[xx][yy] = dM[x][y] + 1;
                    if (dG[xx][yy] < INF) {
                        return t;
                    }
                    qM.push({xx, yy});
                }
            }
        }
        //G更新一层
        while (qG.size() && dG[x = qG.front().first][y = qG.front().second] < t) {
            qG.pop();
            if (dZ[x][y] <= 2 * t) continue;
            for (int i = 0; i < 4; i++) {
                xx = x + dx[i], yy = y + dy[i];
                if (legal(xx, yy, t) && dG[xx][yy] > dG[x][y] + 1) {
                    dG[xx][yy] = dG[x][y] + 1;
                    if (dM[xx][yy] < INF) {
                        return t;
                    }

                    qG.push({xx, yy});
                }
            }
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(dZ, 0x3f, sizeof(dZ));
        memset(dM, 0x3f, sizeof(dM));
        memset(dG, 0x3f, sizeof(dG));

        while (qZ.size())
            qZ.pop();
        while (qG.size())
            qG.pop();
        while (qM.size())
            qM.pop();

        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> (G[i] + 1);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (G[i][j] == 'Z') {
                    qZ.push({i, j});
                    dZ[i][j] = 0;
                } else if (G[i][j] == 'M') {
                    qM.push({i, j});
                    dM[i][j] = 0;
                } else if (G[i][j] == 'G') {
                    qG.push({i, j});
                    dG[i][j] = 0;
                }
            }
        cout << solve() << endl;
    }
}
