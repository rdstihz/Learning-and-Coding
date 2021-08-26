/*
    Created by rdstihz at 2021-08-26 22:49:07
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
char s[maxn];

bool isprime[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0};

void solve() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (!isprime[s[i] - '0']) {
            printf("1\n%c\n", s[i]);
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '2' || s[j] == '5' || s[j] == '7') {
                    printf("2\n%c%c\n", s[i], s[j]);
                    return;
                }
            }
        }
        if (s[i] == '3') {
            for (int j = i + 1; j < n; j++)
                if (s[j] == '2' || s[j] == '3' || s[j] == '5') {
                    printf("2\n%c%c\n", s[i], s[j]);
                    return;
                }
        }
        if (s[i] == '5') {
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '2' || s[j] == '5' || s[j] == '7') {
                    printf("2\n%c%c\n", s[i], s[j]);
                    return;
                }
            }
        }
        if (s[i] == '7') {
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '2' || s[j] == '5' || s[j] == '7') {
                    printf("2\n%c%c\n", s[i], s[j]);
                    return;
                }
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