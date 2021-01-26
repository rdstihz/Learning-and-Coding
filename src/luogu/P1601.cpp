#include <cstdio>
#include <cstring>

const int maxn = 1000;

int a[maxn], b[maxn];
char s1[maxn], s2[maxn];

void read(int *x) {
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x[++x[0]] = c - '0';
        c = getchar();
    }

    for (int i = 1; i < x[0] / 2; i++) {
        int t = x[i];
        x[i] = x[x[0] + 1 - i];
        x[x[0] + 1 - i] = t;
    }

}


int main() {

    scanf("%s%s", s1 + 1, s2 + 1);

    a[0] = strlen(s1 + 1);
    for (int i = 1; i <= a[0]; i++) {
        a[i] = s1[a[0] + 1 - i] - '0';
    }

    b[0] = strlen(s2 + 1);
    for(int i = 1;i<=b[0];i++) {
        b[i] = s2[b[0] + 1 - i] - '0';
    }

    if (a[0] < b[0]) a[0] = b[0];
    int t = 0;
    for (int i = 1; i <= a[0]; i++) {
        a[i] = a[i] + b[i] + t;
        t = a[i] / 10;
        a[i] %= 10;
    }
    while (t) {
        a[++a[0]] = t % 10;
        t /= 10;
    }

    for (int i = a[0]; i >= 1; i--)
        printf("%d", a[i]);
    printf("\n");
    return 0;
}