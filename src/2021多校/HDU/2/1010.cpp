#include <bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        long long a, p;
        scanf("%lld%lld", &a, &p);
        printf("%d\n", (a - p) % 2 ? 0 : 1);
    }
    return 0;
}