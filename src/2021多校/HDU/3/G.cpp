#include <bits/stdc++.h>

using namespace std;

int get(char c) {
    if (isdigit(c))
        return c - '0';
    else
        return c - 'A' + 10;
}

int readIn() {
    char c = getchar();
    while (!isdigit(c) && !isalpha(c))
        c = getchar();
    int x = get(c);
    c = getchar();
    x = x * 16 + get(c);
    return x;
}

const int maxn = 100000 + 100;
int r[maxn], g[maxn], b[maxn];
int op[maxn], last[maxn];

void print(int x) {
    int a = x / 16, b = x % 16;
    if (a < 10)
        printf("%c", a + '0');
    else
        printf("%c", a - 10 + 'A');
    if (b < 10)
        printf("%c", b + '0');
    else
        printf("%c", b - 10 + 'A');
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        last[0] = 1;
        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", op + i);
            if (op[i] == 1)
                last[i] = i;
            else
                last[i] = last[i - 1];
            r[i] = readIn(), g[i] = readIn(), b[i] = readIn();
        }

        for (int i = 1; i <= n; i++) {
            r[i] += r[i - 1], g[i] += g[i - 1], b[i] += b[i - 1];
        }

        int li, ri;
        while (q--) {
            scanf("%d%d", &li, &ri);
            li = max(li - 1, last[ri] - 1);
            print(min(255, r[ri] - r[li]));
            print(min(255, g[ri] - g[li]));
            print(min(255, b[ri] - b[li]));
            printf("\n");
        }
    }

    return 0;
}