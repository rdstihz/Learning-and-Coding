#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const int maxn = 3010;
const int P = 131;

char s[maxn];

int p, n;

ull dfs() {
    ull res = 0;
    int cnt = 0;
    while (p <= n && s[p] - '0' == 0) {
        cnt++;
        p++;
        res += dfs();
    }
    p++;
    return res * P * cnt + 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        p = 1;
        ull A = dfs();

        scanf("%s", s + 1);
        if (strlen(s + 1) != n) {
            puts("different");
            continue;
        }
        p = 1;
        ull B = dfs();
        


        if (A == B)
            puts("same");
        else
            puts("different");
    }

    return 0;
}