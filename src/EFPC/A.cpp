#include <cstdio>

const int maxn = 100;

char s[maxn];
const char ecust[] = "ecust";
const char ECUST[] = "ECUST";

int T, n;
bool haveecust() {

    for (int i = 0; i < 5; i++) {
        bool flag = false;

        for (int j = 1; j <= n; j++)
            if (ecust[i] == s[j]) {
                flag = true;
                break;
            }
        if (!flag) return false;
    }
    return true;
}

bool haveECUST() {

    for (int i = 0; i < 5; i++) {
        bool flag = false;

        for (int j = 1; j <= n; j++)
            if (ECUST[i] == s[j]) {
                flag = true;
                break;
            }
        if (!flag) return false;
    }
    return true;
}

bool haveEcust() {

    for (int i = 0; i < 5; i++) {
        bool flag = false;

        for (int j = 1; j <= n; j++)
            if (ecust[i] == s[j] || ECUST[i] == s[j]) {
                flag = true;
                break;
            }
        if (!flag) return false;
    }
    return true;
}

int main() {

    scanf("%d", &T);
    for (int k = 1; k <= T; k++) {
        scanf("%d%s", &n, s + 1);

        bool havee = haveecust();
        bool haveE = haveECUST();
        bool have = haveEcust();

        if (haveE && havee) {
            printf("Case %d: ECUST and ecust\n", k);
        } else if (haveE) {
            printf("Case %d: ECUST\n", k);
        } else if (havee) {
            printf("Case %d: ecust\n", k);
        } else if (have) {
            printf("Case %d: Yes\n", k);
        } else {
            printf("Case %d: No\n", k);
        }
    }

    return 0;
}