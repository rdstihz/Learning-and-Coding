/*
    Created by godlei at 2021-12-01 22:35:44
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
void solve() {
    LL a1, p1, a2, p2;
    cin >> a1 >> p1 >> a2 >> p2;

    while(a1 < 10000000) {
        a1 *= 10;
        p1--;
    }
    while(a2 < 10000000) {
        a2 *= 10;
        p2--;
    }


    if(p1 != p2) {
        putchar(p1 > p2 ? '>' : '<');
    }else if(a1 != a2) {
        putchar(a1 > a2 ? '>' : '<');
    }else
        putchar('=');
    putchar('\n');
    

}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}