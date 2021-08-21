#include <bits/stdc++.h>

using namespace std;


int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        puts(a * 2 > b ? "Yes" : "No");

    }
    return 0;
}