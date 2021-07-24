#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    //不要第一次
    int ans0 = 0;
    int xx = n;
    while (xx > 1) {
        ans0 += 2;
        xx = (xx + 1) / 2;
    }
    ans0++;
    for (int i = 1; i <= n; i++) {

        //回答yes
        int ans1 = 1;
        int x = n - i + 1;

        if (x > 1) {
            while (x > 1) {
                ans1 += 2;
                x = (x + 1) / 2;
            }
            ans1++;
        }

        //回答no
        int ans2 = 1;
        x = n;
        while (x > 1) {
            ans2 += 1;
            x = (x + 1) / 2;
        }

        printf("%d ", min(ans0, max(ans1, ans2)));
    }
    printf("\n");
    return 0;
}