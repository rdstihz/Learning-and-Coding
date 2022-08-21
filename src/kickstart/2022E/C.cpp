#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 10;
char s[maxn];
int fail[maxn];

int main() {
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        fail[1] = 0;
        for(int i = 2; i <= n; i++) {
            int j = fail[i - 1];
            while(j && s[i] != s[j + 1]) j = fail[j];
            if(s[i] == s[j + 1]) j++;
            fail[i] = j;
        }

        int l = n - fail[n];

        printf("Case #%d: ", kase);
        if(n % l != 0) {
            printf("%s\n", s + 1);
        }else {
            for(int i = l; i >= 1; i--) 
                printf("%c", s[i]);
            printf("\n");
        }
    }
    
    return 0;
}