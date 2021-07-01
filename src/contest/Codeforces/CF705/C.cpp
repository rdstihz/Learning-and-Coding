#include <cstdio>
#include <cstring>

const int maxn = 100000 + 100;

char s[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s + 1);

        if (n % k != 0) {
            printf("-1");
            break;
        }
    }

    return 0;
}
