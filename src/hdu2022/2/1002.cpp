#include <bits/stdc++.h>


using namespace std;

const int maxn = 2000;
char s[maxn];

void solve() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i++) {
        if(s[i] >= '0' && s[i] <= '9' || s[i] == '-' || s[i] == '(' || s[i] == ')' || s[i] == ',')
            putchar(s[i]);
    }
    putchar('\n');
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}