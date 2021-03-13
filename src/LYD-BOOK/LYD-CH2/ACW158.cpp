#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2000000 + 100;

char s1[maxn], s2[maxn];

int minE(char* s) {
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        s[i + n] = s[i];

    int i = 1, j = 2;

    while (i <= n && j <= n) {
        int k = 0;
        while (k < n && s[i + k] == s[j + k])
            k++;
        if (k == n) break;
        if (s[i + k] < s[j + k]) {
            j = j + k + 1;
            if (i == j) j++;
        } else {
            i = i + k + 1;
            if (i == j) i++;
        }
    }

    return min(i, j);
}

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    int n = strlen(s1 + 1);
    int a = minE(s1);
    int b = minE(s2);

    bool flag = true;
    for (int k = 0; k < n; k++) {
        if (s1[a + k] != s2[b + k]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        puts("Yes");
        for (int i = 0; i < n; i++)
            printf("%c",s1[a + i]);
    }
    else {
        puts("No");
    }

    return 0;
}