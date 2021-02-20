#include <iostream>
#include <algorithm>

using namespace std;

const int N = 9;
const int g[9][9] = {
    {6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 9, 10, 9, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6}};

int a[N][N];
int row[N], col[N], cell[3][3];

int log[1 << N], ones[1 << N];

inline int lowbit(int x) {
    return x & -x;
}
int ans;

int get(int x, int y) {
    return row[x] & col[y] & cell[x / 3][y / 3];
}

void dfs(int cnt, int sum) {
    if (!cnt) {
        ans = max(ans, sum);
        return;
    }

    //找到选择最少的格子
    int x, y;
    int minv = 10;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (a[i][j] == -1 && ones[get(i, j)] < minv) {
                minv = ones[get(i, j)];
                x = i, y = j;
            }
        }

    for (int i = get(x, y); i; i -= lowbit(i)) {
        int t = log[lowbit(i)];
        row[x] ^= 1 << t;
        col[y] ^= 1 << t;
        cell[x / 3][y / 3] ^= 1 << t;
        a[x][y] = t;

        dfs(cnt - 1, sum + g[x][y] * (t + 1));

        row[x] ^= 1 << t;
        col[y] ^= 1 << t;
        cell[x / 3][y / 3] ^= 1 << t;
        a[x][y] = -1;
    }
}

int main() {
    for (int i = 0; i < N; i++)
        log[1 << i] = i;
    for (int i = 0; i < 1 << N; i++) {
        for (int j = i; j; j -= lowbit(j))
            ones[i]++;
    }

    for (int i = 0; i < N; i++) {
        row[i] = (1 << N) - 1;
        col[i] = (1 << N) - 1;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cell[i][j] = (1 << N) - 1;
        }

    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            a[i][j]--;

            if (a[i][j] == -1) {
                cnt++;
            } else {
                row[i] &= ~(1 << a[i][j]);
                col[j] &= ~(1 << a[i][j]);
                cell[i / 3][j / 3] &= ~(1 << a[i][j]);
                sum += g[i][j] * (a[i][j] + 1);
            }
        }
    ans = -1;
    dfs(cnt, sum);
    cout << ans << endl;
    return 0;
}