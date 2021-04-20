#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#define belong(x) ((x - 1) / size + 1)

using namespace std;

const int maxn = 300000 + 100;
const int maxm = 600;
const int INF = 0x3f3f3f3f;
int color[maxn], val[maxn];

int lb[1000], rb[1000];
int v[maxm][maxm];
int time[maxm][maxm];

int s[600][maxn];

vector<int> pos[maxn];

int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int main() {

    int n, T;
    n = read();
    T = read();

    for (int i = 1; i <= n; i++) {
        color[i] = read();
    }

    int size = sqrt(n);
    int block = (n - 1) / size + 1;

    for (int i = 1; i <= block; i++) {
        lb[i] = rb[i - 1] + 1;
        rb[i] = rb[i - 1] + size;
    }
    rb[block] = n;
    lb[block + 1] = INF;
    rb[0] = -INF;

    int m = n;

    for (int i = 1; i <= n; i++) {
        pos[color[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        s[belong(i)][color[i]]++;
    }
    for (int i = 1; i <= block; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] += s[i - 1][j];
    //预处理每个块区间的信息

    for (int l = block; l >= 1; l--) {
        for (int r = l; r <= block; r++) {
            if (l == r) {
                int tempv = 0, times = 0;
                int a, b;
                for (int i = lb[r]; i <= rb[r]; i++) {
                    int col = color[i];
                    b = s[r][col] - s[l - 1][col];
                    if (b > times || (b == times && col < tempv)) {
                        tempv = col;
                        times = b;
                    }
                }
                v[l][r] = tempv;
                time[l][r] = times;

            } else {
                int tempv = v[l][r - 1];
                int times = time[l][r - 1];
                int b = s[r][tempv] - s[l - 1][tempv];
                times = b;

                for (int i = lb[r]; i <= rb[r]; i++) {
                    int col = color[i];
                    b = s[r][col] - s[l - 1][col];
                    if (b > times || (b == times && col < tempv)) {
                        tempv = col;
                        times = b;
                    }
                }
                v[l][r] = tempv;
                time[l][r] = times;
            }
        }
    }

    int l, r;
    int x = 0;
    while (T--) {
        l = read();
        r = read();
        //l = (l + x - 1) % n + 1;
        //r = (r + x - 1) % n + 1;
        if (l > r) swap(l, r);
        //大块
        int L = (l - 1) / size + 2; //向上取整
        if (l % size == 1) L--;
        int R = r / size;

        int tempv = v[L][R];
        int times = time[L][R];
        int a, b;

        int col;
        //左边小块
        for (int i = l; i <= rb[L - 1]; i++) {
            col = color[i];
            a = lower_bound(pos[col].begin(), pos[col].end(), l) - pos[col].begin();
            b = upper_bound(pos[col].begin(), pos[col].end(), r) - pos[col].begin();
            b -= a;
            if (b > times || (b == times && col < tempv)) {
                tempv = col;
                times = b;
            }
        }

        //右边小块
        for (int i = lb[R + 1]; i <= r; i++) {
            col = color[i];
            a = lower_bound(pos[col].begin(), pos[col].end(), l) - pos[col].begin();
            b = upper_bound(pos[col].begin(), pos[col].end(), r) - pos[col].begin();
            b -= a;
            if (b > times || (b == times && col < tempv)) {
                tempv = col;
                times = b;
            }
        }

        int temp = r - l + 1 - times;
        printf("%d\n", max(1, times - temp));
    }

    return 0;
}