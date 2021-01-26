#include <bits/stdc++.h>


using namespace std;

const int maxn = 1000000 + 100;

char S[maxn],T[maxn];

int n,m;
int fail[maxn];


void init() {

    fail[1] = 0;

    for(int i = 2;i <= n;i++) {
        int j = fail[i-1];
        while(j && S[i] != S[j + 1]) j = fail[j];
        if(S[i] == S[j+1]) j++;
        fail[i] = j;
    }


}

int main(){

    scanf("%s%s",T+1,S+1);
    n = strlen(S + 1);
    m = strlen(T + 1);

    init();

    int j = 0;
    for(int i = 1; i <= m; i++) {
        while(j && T[i] != S[j+1]) j = fail[j];
        if(T[i] == S[j+1]) {
            j++;
            if(j == n) {
                printf("%d\n",i-n+1);
                j = fail[j];
            }
        }

    }

    for(int i =1;i <= n;i++)
        printf("%d ",fail[i]);
    return 0;
}