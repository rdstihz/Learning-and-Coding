#include <cstdio>
#include <cstring>

const int maxn = 10000 + 100;

char s[maxn][80];
bool st[80];
int fail[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++) {
            for (int k = j + 1; k <= m; k++) {
                if (s[i][k] != s[i][k - j]) {
                    st[j] = 1;
                    break;
                }
            }
        }
    }
    int b = 1;
    while (st[b])
        b++;

    for (int i = 1; i <= n; i++) {
        s[i][b + 1] = 0;
    }

    fail[1] = 0;
    for (int i = 2; i <= n; i++) {
        int j = fail[i - 1];
        while (j && strcmp(s[i] + 1, s[j + 1] + 1) != 0)
            j = fail[j];
        if (strcmp(s[i] + 1, s[j + 1] + 1) == 0) j++;
        fail[i] = j;
    }
  //  printf("%d %d\n", b, n - fail[n]);
    printf("%d\n", b * (n - fail[n]));
    return 0;
}
