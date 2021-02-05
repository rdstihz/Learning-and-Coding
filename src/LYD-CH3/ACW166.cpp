#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 9;
const int maxn = 90;

char s[maxn];
int num[N][N];

int used_row[N];
int used_col[N];
int used_pal[N];

int X[maxn], Y[maxn], q[maxn], poss[maxn];
int n;

bool dfs(int cur) {
    if (cur > n) {
        return true;
    }

    int i = X[q[cur]], j = Y[q[cur]];
    int p = i / 3 * 3 + j / 3;
    for (int k = 1; k <= N; k++) {
        if (!((used_row[i] >> k & 1) || (used_col[j] >> k & 1) || (used_pal[p] >> k & 1))) {
            num[i][j] = k;
            used_row[i] ^= 1 << k;
            used_col[j] ^= 1 << k;
            used_pal[p] ^= 1 << k;

            if (dfs(cur + 1)) return true;

            used_row[i] ^= 1 << k;
            used_col[j] ^= 1 << k;
            used_pal[p] ^= 1 << k;
        }
    }

    return false;
}

bool cmp(int a, int b) {
    return poss[a] < poss[b];
}

int main() {

    while (scanf("%s", s), s[0] != 'e') {

        n = 0;
        memset(used_row, 0, sizeof(used_row));
        memset(used_col, 0, sizeof(used_col));
        memset(used_pal, 0, sizeof(used_pal));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (s[9 * i + j] == '.') {
                    n++;
                    X[n] = i, Y[n] = j;
                    q[n] = n;
                } else {
                    int k = s[9 * i + j] - '0';
                    num[i][j] = k;
                    used_row[i] |= 1 << k;
                    used_col[j] |= 1 << k;
                    used_pal[i / 3 * 3 + j / 3] |= 1 << k;
                }
            }
        }

        for (int t = 1; t <= n; t++) {
            int i = X[t], j = Y[t];
            int p = i / 3 * 3 + j / 3;
            for (int k = 1; k <= N; k++) {
                if (!((used_row[i] >> k & 1) || (used_col[j] >> k & 1) || (used_pal[p] >> k & 1))) {
                    poss[t]++;
                }
            }
        }

        sort(q + 1, q + 1 + n, cmp);
        dfs(1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d", num[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}