#include <cstdio>

using namespace std;

const int maxn = 1000;

int res[maxn];

void mul(int v) {
    int t = 0;

    for (int i = 1; i <= res[0]; i++) {
        res[i] = res[i] * v + t;
        t = res[i] / 10;
        res[i] %= 10;
    }

    while (t) {
        res[++res[0]] = t % 10;
        t /= 10;
    }
}

void add(int v) {
    res[1] += v;
    int i = 1;
    while (res[i] >= 10) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
        i++;
    }
    while (res[res[0] + 1])
        res[0]++;
}

int main() {
    int n;
    scanf("%d", &n);
    res[0] = 0;

    for (int i = 1; i <= n; i++) {
        mul(2);
        add(2);
    }
    for (int i = res[0]; i >= 1; i--)
        printf("%d", res[i]);
    printf("\n");
}