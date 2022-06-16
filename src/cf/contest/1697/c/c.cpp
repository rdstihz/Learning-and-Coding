/*
    Created by godlei at 2022-06-12 22:48:54
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
char s[maxn], t[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    scanf("%s%s", s + 1, t + 1);


    int a = 0, b = 0, c = 0;

    for(int i = 1; i <= n; i++) {
        if(s[i] == 'a') a++;
        else if(s[i] == 'b') b++;
        else if(s[i] == 'c') c++;

        if(t[i] == 'a') a--;
        else if(t[i] == 'b') b--;
        else if(t[i] == 'c') c--;
    }

    if(a || b || c) {
        printf("NO\n");
        return ;
    }


    for(int i = 1, j = 1; i <= n; i++) {
        if(s[i] == 'a' && t[i] == 'a') continue;
        else if(t[i] == 'a') {
            printf("NO\n");
            return ;
        }else if(s[i] == 'a') {
            j = max(j, i);
            while(j < n && s[j + 1] == 'a') j++;

            if(j && s[j + 1] == 'b') {
                swap(s[i], s[j + 1]);
                j++;
            }else {

            }

        }
    }


}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}