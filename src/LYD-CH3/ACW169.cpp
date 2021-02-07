#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 16;
const int full = (1 << N) - 1;

char str[20][20], bstr[300][20][20];
int state[N][N], bstate[300][N][N];

int ones[1 << N], log[1 << N];

int lowbit(int x) {
    return x & -x;
}

void draw(int x, int y, int c) {

    //行列
    for (int i = 0; i < N; i++) {
        state[x][i] &= ~(1 << c);
        state[i][y] &= ~(1 << c);
    }
    //宫
    int sx = x / 4 * 4, sy = y / 4 * 4;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            state[sx + i][sy + j] &= ~(1 << c);

    state[x][y] = 1 << c;
    str[x][y] = c + 'A';
}

bool dfs(int cnt) {
    if (!cnt) return true;

    //备份
    int kcnt = cnt;
    memcpy(bstr[kcnt], str, sizeof str);
    memcpy(bstate[kcnt], state, sizeof state);

    //处理每一格

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (str[i][j] == '-') {

                if (!state[i][j]) {
                    memcpy(str, bstr[kcnt], sizeof str);
                    memcpy(state, bstate[kcnt], sizeof state);
                    return false;
                } else if (ones[state[i][j]] == 1) {
                    cnt--;
                    draw(i, j, log[state[i][j]]);
                }
            }

    //处理每一行
    for (int i = 0; i < N; i++) {
        int s = 0;
        for (int j = 0; j < N; j++)
            s |= state[i][j];
        if (s != full) {
            memcpy(str, bstr[kcnt], sizeof str);
            memcpy(state, bstate[kcnt], sizeof state);
            return false;
        }
    }

    //处理每一列
    for (int j = 0; j < N; j++) {
        int s = 0;
        for (int i = 0; i < N; i++)
            s |= state[i][j];
        if (s != full) {
            memcpy(str, bstr[kcnt], sizeof str);
            memcpy(state, bstate[kcnt], sizeof state);
            return false;
        }
    }

    //处理每一宫
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            int sx = i * 4, sy = j * 4;
            int s = 0;
            for (int dx = 0; dx < 4; dx++)
                for (int dy = 0; dy < 4; dy++)
                    s |= state[sx + dx][sy + dy];

            if (s != full) {
                memcpy(str, bstr[kcnt], sizeof str);
                memcpy(state, bstate[kcnt], sizeof state);
                return false;
            }
        }

    //找到选择最少的格子
    int x, y;
    int minv = 20;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (str[i][j] == '-') {
                if (ones[state[i][j]] < minv) {
                    minv = ones[state[i][j]];
                    x = i;
                    y = j;
                }
            }

    for (int i = state[x][y]; i; i -= lowbit(i)) {

        int t = log[lowbit(i)];

        draw(x,y,t);
        dfs(cnt - 1);
        
        memcpy(str, bstr[kcnt], sizeof str);
        memcpy(state, bstate[kcnt], sizeof state);

    }

    return false;
}

int main() {

    for (int i = 0; i < N; i++)
        log[1 << i] = i;
    for (int i = 0; i < 1 << N; i++) {
        int s = 0;
        for (int j = i; j; j -= lowbit(j))
            s++;
        ones[i] = s;
    }

    while (cin >> str[0]) {
        for (int i = 1; i < N; i++)
            cin >> str[i];
        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (str[i][j] != '-') {
                    draw(i, j, str[i][j] - 'A');
                } else
                    cnt++;

        dfs(cnt);

        for (int i = 0; i < N; i++)
            cout << str[i] << endl;
        cout << endl;
    }

    return 0;
}