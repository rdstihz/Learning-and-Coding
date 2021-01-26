#include <cstdio>
#include <cstring>

const int maxn = 1000;

char s[maxn];
int sum[maxn];

void work(int l, int r) {
    if (l == r) {
        printf("%c", s[l] == '0' ? 'A' : 'B');
        return;
    }

    if (sum[r] - sum[l - 1] == 0) {
        printf("A");
    } else if (sum[r] - sum[l - 1] == r - l + 1) {
        printf("B");
    } else {
        printf("C");
        int m = l + r >> 1;
        work(l, m);
        work(m + 1, r);
    }

}

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + s[i] - '0';

    work(1, n);

    return 0;
}