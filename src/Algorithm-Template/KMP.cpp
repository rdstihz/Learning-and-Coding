// Luogu P3375

#include <cstdio>
#include <cstring>

const int maxn = 1000000 + 100;
int fail[maxn];

char T[maxn], S[maxn]; // 文本串，模式串

void getFail() {
    int n = strlen(S + 1);
    fail[1] = 0;
    for (int i = 2; i <= n; i++) {
        int j = fail[i - 1];
        while (j && S[j + 1] != S[i])
            j = fail[j];
        if (S[j + 1] == S[i]) j++;
        fail[i] = j;
    }
}

int main() {
    scanf("%s%s", T + 1, S + 1);
    int n = strlen(S + 1), m = strlen(T + 1);
    getFail();
    int j = 0;
    for (int i = 1; i <= m; i++) {
        while (j && S[j + 1] != T[i])
            j = fail[j];
        if (S[j + 1] == T[i]) {
            j++;
            if (j == n) {
                printf("%d\n", i - n + 1);
                j = fail[j];
            }
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", fail[i]);

    return 0;
}