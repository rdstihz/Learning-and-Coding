#include <bits/stdc++.h>


using namespace std;

const int maxn = 11000100;

char s[maxn];
char ss[2 * maxn];

int n;

void init() {
    n = strlen(s);

    ss[0] = '$';
    ss[1] = '#';
    int j = 2;
    for (int i = 0; i < n; i++) {
        ss[j++] = s[i];
        ss[j++] = '#';
    }
    ss[j++] = '\0';
    n = j;

}

int p[2*maxn];

int manacher() {
    int ans = 0;

    int id = 0;
    int mx = 1;

    for (int i = 1; i < n; i++) {
        if (i < mx) {
            p[i] = min(p[2 * id - i], mx - i);
        } else {
            p[i] = 1;
        }

        while(ss[i-p[i]] == ss[i + p[i]] ) p[i]++;

        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
        ans = max(ans, p[i] - 1);
    }


    return ans;
}

int main() {

    scanf("%s", s);

    init();


    int ans = manacher();

    printf("%d\n", ans);

    return 0;
}