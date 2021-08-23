/*
    Created by rdstihz at 2021-08-15 22:40:06
*/

#include <bits/stdc++.h>

using namespace std;

char s[1000];

void solve() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    s[n] = 'B';
    int i = 0;
    while (s[i] == '?')
        i++;
    
    for(int j = i - 1; j >= 0; j--) {
        if(s[j] == '?') {
            s[j] = s[j + 1] == 'B' ? 'R' : 'B';
        }
    }
    for(int j = i + 1; j < n; j++) {
        if(s[j] == '?')
            s[j] = s[j - 1] == 'B' ? 'R' : 'B';
   }
   s[n] = '\0';
    printf("%s\n", s);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}