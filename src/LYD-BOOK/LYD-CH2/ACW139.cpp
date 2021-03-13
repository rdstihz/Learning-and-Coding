#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


typedef unsigned long long uLL;
const int maxn = 1000000 + 10;
const uLL P = 131;
char s[maxn];
uLL H1[maxn], H2[maxn];
uLL B[maxn];
int n;

inline bool check1(int o, int x) {
    if (o < x || o + x - 1 > n) return false;
    return H1[o] - H1[o - x] * B[x] == H2[o] - H2[o + x] * B[x];
}

inline bool check2(int o, int x) {
    if (o < x || o + x > n) return false;
    return H1[o] - H1[o - x] * B[x] == H2[o + 1] - H2[o + 1 + x] * B[x];
}

int main() {

    int k = 0;

    B[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        B[i] = B[i - 1] * P;
    }

    while (scanf("%s", s + 1) == 1 && s[1] != 'E') {

        memset(H1, 0, sizeof H1);
        memset(H2, 0, sizeof H2);

        n = strlen(s + 1);

        for (int i = 1; i <= n; i++) {
            H1[i] = H1[i - 1] * P + s[i] - 'a' + 1;
        }

        for (int i = n; i >= 1; i--) {
            H2[i] = H2[i + 1] * P + s[i] - 'a' + 1;
        }


        int ans = 0;
        //长度为奇数的回文子串

        for (int i = 1; i <= n; i++) {
            int l = 1, r = n;
            int m;
            while (l < r) {
                m = l + r >> 1;
                if (check1(i, m)) l = m + 1;
                else r = m;
            }
            ans = max(ans, 2 * l - 3);
        }

        //2.偶数
        for (int i = 1; i <= n; i++) {
            int l = 0, r = n;
            int m;
            while (l < r) {
                m = l + r >> 1;
                if (check2(i, m)) l = m + 1;
                else r = m;
            }
            ans = max(ans, 2 * l - 2);
        }

        printf("Case %d: %d\n", ++k, ans);

    }


    return 0;
}