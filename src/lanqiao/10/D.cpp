#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

char s[100][100];
int d[100][100];

PII pre[100][100];
char op[100][100];

const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};
const char ops[] = "DLRU";
inline bool legal(int x, int y) {
    return x >= 1 && x <= 30 && y >= 1 && y <= 50 && s[x][y] == '0';
}

int main() {

    for (int i = 1; i <= 30; i++)
        scanf("%s", s[i] + 1);

    memset(d, 0x3f, sizeof(d));

    d[1][1] = 0;
    queue<PII> Q;
    Q.push(make_pair(1, 1));

    while (Q.size()) {
        PII node = Q.front();
        Q.pop();

        int x = node.first;
        int y = node.second;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (legal(xx, yy)) {
                if (d[xx][yy] > d[x][y] + 1) {
                    d[xx][yy] = d[x][y] + 1;
                    pre[xx][yy] = node;
                    op[xx][yy] = ops[i];
                    Q.push(make_pair(xx, yy));
                }
            }
        }
    }

    string res = "";
    PII cur = {30, 50};
    while (cur != make_pair(1,1)) {
        res += op[cur.first][cur.second];
        cur = pre[cur.first][cur.second];
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}