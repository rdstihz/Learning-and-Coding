#include <cstdio>
#include <cstring>

char s[100000 + 100];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);

    s[n] = '~';
    s[n + 1] = '\0';

    int pos = n;
    for (int i = 1; i < n; i++)
        if (strcmp(s + i, s) > 0) {
            pos = i;
            break;
        }

    for (int i = 0; i < k; i++)
        printf("%c", s[i % pos]);
    printf("\n");

    return 0;
}