#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b;
        int x = 0, y = 0;
        scanf("%d%d", &a, &b);
        if (a == b) {
            x = 2, y = a;
        } else {
            if (a < b) swap(a, b);
            int d = a - b;

            x = y = d;
            for (int i = 2; i * i <= d; i++)
                if (d % i == 0) {
                    x = i;
                    y = d;
                    break;
                }
        }

        if (x < 2 || y < 2) {
            printf("-1 -1\n");
        } else {
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}