#include <bits/stdc++.h>

using namespace std;

const int maxn = 300000 + 100;

char s[3][maxn];
int S[3];

int n;

char ans[maxn];

void work1(int a, int b) {

    int i = 1;
    int j = 1;

    while (i <= 2 * n && j <= 2 * n) {
        if (s[a][i] == '1' && s[b][j] == '1') {
            putchar('1');
            i++;
            j++;
        } else if (s[a][i] == '0') {
            putchar('0');
            i++;
        } else if (s[b][j] == '0') {
            putchar('0');
            j++;
        }
    }

    while (i <= 2 * n) {
        putchar(s[a][i]);
        i++;
    }
    while (j <= 2 * n) {
        putchar(s[b][j]);
        j++;
    }

    putchar('\n');
}

void work0(int a, int b) {

    int i = 1;
    int j = 1;

    while (i <= 2 * n && j <= 2 * n) {
        if (s[a][i] == '0' && s[b][j] == '0') {
            putchar('0');
            i++;
            j++;
        } else if (s[a][i] == '1') {
            putchar('1');
            i++;
        } else if (s[b][j] == '1') {
            putchar('1');
            j++;
        }
    }

    while (i <= 2 * n) {
        putchar(s[a][i]);
        i++;
    }
    while (j <= 2 * n) {
        putchar(s[b][j]);
        j++;
    }
    putchar('\n');
}

int main() {

    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        cin >> s[0] + 1;
        cin >> s[1] + 1;
        cin >> s[2] + 1;

        for (int k = 0; k < 3; k++) {
            S[k] = 0;
            for (int i = 1; i <= 2 * n; i++) {
                S[k] += s[k][i] == '1';
            }
        }
        bool solved = false;

        for (int a = 0; a < 3; a++) {
            if (solved) break;
            for (int b = 0; b < 3; b++) {
                if (a == b) continue;

                if (S[a] >= n && S[b] >= n) {
                    work1(a, b);
                    solved = true;
                    break;
                } else if (S[a] <= n && S[b] <= n) {
                    work0(a, b);
                    solved = true;
                    break;
                }
            }
        }
    }

    return 0;
}