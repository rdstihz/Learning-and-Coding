#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 16;
const int maxn = 260;

using namespace std;

int ones[1 << N], log[1 << N];
char str[N][N + 1];
int state[N][N];

inline int lowbit(int x) {
    return x & -x;
}

inline void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            state[i][j] = (1 << N) - 1;
}

inline void draw(int x, int y, int c) {
    //同行同列
    for (int i = 0; i < N; i++) {
        state[x][i] &= ~(1 << c);
        state[i][y] &= ~(1 << c);
    }
    //同一宫
    int sx = x / 4 * 4, sy = y / 4 * 4;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            state[sx + i][sy + j] &= ~(1 << c);
        }
    //本身，只能固定的一个数
    state[x][y] = 1 << c;
    str[x][y] = 'A' + c;
}

int bstr[maxn][N][N + 1], bstr2[maxn][N][N + 1];
int bstate[maxn][N][N], bstate2[maxn][N][N];

bool dfs(int cnt) {
    if (!cnt) return true; // 填完，找到答案

    //备份
    int kcnt = cnt;
    memcpy(bstr[kcnt], str, sizeof str);
    memcpy(bstate[kcnt], state, sizeof(state));

    //检索每一格，如果一格不能填任何一个数，剪枝
    //如果一格只能填一个数，直接填上

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (str[i][j] == '-') {
                if (state[i][j] == 0) {
                    //恢复现场并退出
                    memcpy(str, bstr[kcnt], sizeof str);
                    memcpy(state, bstate[kcnt], sizeof state);
                    return false;
                } else if (ones[state[i][j]] == 1) {
                    draw(i, j, log[state[i][j]]);
                    cnt--;
                }
            }

    //检索每一行，如果某个数不能填在任务位置,退出
    //如果某个数只能填在一个位置，填上
    for (int i = 0; i < N; i++) {
        int sor = 0;             //能填的数
        int sand = (1 << N) - 1; //只能填一个位置的数
        int drawn = 0;           //已经填好的数

        for (int j = 0; j < N; j++) {
            int s = state[i][j];
            sand &= ~(s & sor);
            sor |= s;

            if (str[i][j] != '-')
                drawn |= s;
        }

        //如果这行不能填上所有数，退出
        if (sor != (1 << N) - 1) {
            //恢复并退出
            memcpy(str, bstr[kcnt], sizeof str);
            memcpy(state, bstate[kcnt], sizeof state);
            return false;
        }
        //填上位置确定的数
        for (int j = sand; j; j -= lowbit(j)) {
            int t = lowbit(j);
            if (!(t & drawn)) {
                for (int k = 0; k < N; k++)
                    if (state[i][k] & t) {
                        draw(i, k, log[t]);
                        cnt--;
                    }
            }
        }
    }

    //检索每一列，如果某个数不能填在任务位置,退出
    //如果某个数只能填在一个位置，填上
    for (int i = 0; i < N; i++) {
        int sor = 0;             //能填的数
        int sand = (1 << N) - 1; //只能填一个位置的数
        int drawn = 0;           //已经填好的数

        for (int j = 0; j < N; j++) {
            int s = state[j][i];
            sand &= ~(s & sor);
            sor |= s;

            if (str[j][i] != '-')
                drawn |= s;
        }

        //如果这行不能填上所有数，退出
        if (sor != (1 << N) - 1) {
            //恢复并退出
            memcpy(str, bstr[kcnt], sizeof str);
            memcpy(state, bstate[kcnt], sizeof state);
            return false;
        }
        //填上位置确定的数
        for (int j = sand; j; j -= lowbit(j)) {
            int t = lowbit(j);
            if (!(t & drawn)) {
                for (int k = 0; k < N; k++)
                    if (state[k][i] & t) {
                        draw(k, i, log[t]);
                        cnt--;
                    }
            }
        }
    }

    //检索每一宫，如果某个数不能填在任何位置，退出
    //如果某个数只能填在一个位置，直接填上

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            int sor = 0;
            int sand = (1 << N) - 1;
            int drawn = 0;

            int sx = 4 * i, sy = 4 * j;
            for (int dx = 0; dx < 4; dx++)
                for (int dy = 0; dy < 4; dy++) {
                    int s = state[sx + dx][sy + dy];
                    sand &= ~(s & sor);
                    sor |= s;

                    if (str[sx + dx][sy + dy] != '-')
                        drawn |= s;
                }

            if (sor != (1 << N) - 1) {
                //恢复并退出
                memcpy(str, bstr[kcnt], sizeof str);
                memcpy(state, bstate[kcnt], sizeof state);
                return false;
            }

            for (int v = sand; v; v -= lowbit(v)) {
                int t = lowbit(v);

                if (!(drawn & t)) {
                    for (int dx = 0; dx < 4; dx++)
                        for (int dy = 0; dy < 4; dy++) {
                            if (state[sx + dx][sy + dy] & t) {
                                draw(sx + dx, sy + dy, log[t]);
                                cnt--;
                            }
                        }
                }
            }
        }

    if (!cnt) return true;
    //再次备份现场
    memcpy(bstr2[kcnt], str, sizeof(str));
    memcpy(bstate2[kcnt], state, sizeof state);

    //找到可能选择最少的空格
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
        //改变现场并递归
        int t = log[lowbit(i)];
        draw(x, y, t);
        if (dfs(cnt - 1)) return true; //如果成功，return true;

        //恢复现场
        memcpy(str, bstr2[kcnt], sizeof str);
        memcpy(state, bstate2[kcnt], sizeof state);
    }

    return false;
}

int main() {

    //预处理出ones和log
    for (int i = 0; i < N; i++)
        log[1 << i] = i;

    for (int i = 0; i < 1 << N; i++) {
        for (int j = i; j; j -= lowbit(j))
            ones[i]++;
    }

    while (cin >> str[0]) {
        for (int i = 1; i < N; i++)
            cin >> str[i];
        //初始化
        init();

        //填上已知的数
        int cnt = 0; // 空格个数

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (str[i][j] != '-') {
                    draw(i, j, str[i][j] - 'A');
                } else
                    cnt++;
            }

        //dfs填数
        dfs(cnt);

        //输出答案
        for (int i = 0; i < N; i++)
            cout << str[i] << endl;
        cout << endl;
    }

    return 0;
}
