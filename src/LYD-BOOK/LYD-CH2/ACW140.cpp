#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;
const int maxn = 300000 + 100;
const ULL P = 131;

ULL H[maxn];
ULL B[maxn];
char s[maxn];
int n;

int sa[maxn];
int hight[maxn];

inline bool check(int a, int b, int x) {
    if (a + x > n || b + x > n) return false;
    return H[a + x] - H[a - 1] * B[x + 1] == H[b + x] - H[b - 1] * B[x + 1];
}

bool cmp(int a, int b) {

    int l = 0;
    int r = n;
    int m;

    while (l < r) {
        m = l + r >> 1;
        if (!check(a, b, m)) r = m;
        else l = m + 1;

    }

    return s[a + l] < s[b + l];
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);

    H[0] = 0;
    B[0] = 1;


    for (int i = 1; i <= n; i++) {
        H[i] = H[i - 1] * P + s[i] - 'a' + 1;
        B[i] = B[i - 1] * P;
    }

    for (int i = 1; i <= n; i++) {
        sa[i] = i;
    }

    sort(sa + 1, sa + 1 + n, cmp);



    for (int i = 1; i <= n; i++) {
        printf("%d ", sa[i] - 1);
    }
    printf("\n");

    hight[1] = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = n;
        int m;
        while (l < r) {
            m = l + r >> 1;
            if (!check(sa[i], sa[i - 1], m)) r = m;
            else l = m + 1;
        }
        hight[i] = l;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", hight[i]);
    }
    printf("\n");
    return 0;
}