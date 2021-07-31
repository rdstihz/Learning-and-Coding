#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000000 + 100;
int a[maxn];

int readIn() {
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
    int n;
    int op, x;
    n = readIn();

    int p1 = 0, p2 = 1;
    for (int i = 1; i <= n; i++) {
        op = readIn(), x = readIn();
        if (op == 1) {
            a[x] = 1;
            while (p1 < n && a[p1 + 1] == 1)
                p1++;
            p2 = p1 + 1;
            while (p2 < n && a[p2 + 1] == 1)
                p2++;
        } else {
            if (p1 + 1 != x)
                printf("%d\n", p1 + 1);
            else
                printf("%d\n", p2 + 1);
        }
    }

    return 0;
}