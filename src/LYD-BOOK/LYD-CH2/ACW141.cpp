#include <bits/stdc++.h>


using namespace std;

const int maxn = 1000000 + 10;

char s[maxn];
int fail[maxn];

int main() {
    int n;
    int k = 0;
    while (cin >> n && n) {
        scanf("%s", s + 1);

        fail[1] = 0;

        for (int i = 2; i <= n; i++) {
            int j = fail[i - 1];
            while (j && s[i] != s[j + 1]) j = fail[j];
            if (s[i] == s[j + 1]) j++;
            fail[i] = j;
        }

        printf("Test case #%d\n",++k);

        for(int i = 2;i <= n; i++) {
            if(fail[i] && i % (i - fail[i]) == 0) {
                printf("%d %d\n",i,i / (i - fail[i]));
            }

        }
        printf("\n");

    }
    return 0;
}