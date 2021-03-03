#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1010;

char s[maxn];
char rs[maxn];

int f[maxn][maxn];

int main() {

    scanf("%s", s + 1);
    int n = strlen(s + 1);

    for (int i = 1; i <= n; i++) {
        rs[i] = s[n + 1 - i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i] == rs[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }

    printf("%d\n", n - f[n][n]);

    return 0;
}