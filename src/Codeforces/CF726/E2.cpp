#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1000010;

int n, m, k;
char s[N];
int sa[N], x[N], y[N], c[N], rk[N], height[N];
int ord[N];
void get_sa() {
    for (int i = 1; i <= n; i++)
        c[x[i] = s[i]]++;
    for (int i = 2; i <= m; i++)
        c[i] += c[i - 1];
    for (int i = n; i; i--)
        sa[c[x[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int num = 0;
        for (int i = n - k + 1; i <= n; i++)
            y[++num] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > k)
                y[++num] = sa[i] - k;
        for (int i = 1; i <= m; i++)
            c[i] = 0;
        for (int i = 1; i <= n; i++)
            c[x[i]]++;
        for (int i = 2; i <= m; i++)
            c[i] += c[i - 1];
        for (int i = n; i; i--)
            sa[c[x[y[i]]]--] = y[i], y[i] = 0;
        swap(x, y);
        x[sa[1]] = 1, num = 1;
        for (int i = 2; i <= n; i++)
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++num;
        if (num == n) break;
        m = num;
    }
}

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    n++;
    s[n] = 'z';
    s[n + 1] = '\0';
    m = 122;
    get_sa();

    // printf("\n%s\n", s + 1);
    // for(int i = 1; i <= n; i++)
    //     printf("%d ", sa[i]);
    

    for (int i = 1; i <= n; i++)
        ord[sa[i]] = i;
    

    int pos = n;
    for (int i = 2; i <= n; i++)
        if (ord[i] > ord[1]) {
            pos = i - 1;
            break;
        }

    for (int i = 0; i < k; i++)
        printf("%c", s[(i % pos) + 1]);

    return 0;
}