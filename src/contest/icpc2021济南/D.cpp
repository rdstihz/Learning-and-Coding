#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 200000 + 10;

LL a[maxn], b[maxn];
int n;

LL read() {
    LL x = 0;
    char c = getchar();
    int flag = 1;
    while((c < '0' || c > '9') && c != '-') c = getchar();
    if(c == '-') {
        flag = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * flag;
}

__int128 __abs(__int128 a) {
    return a > 0 ? a : -a;
}

__int128 calc(LL x) {
    for(int i = 1; i <= n; i++)
        b[i] = a[i] - x * i;
    __int128 res = 0;
    nth_element(b + 1, b + (n + 1) / 2, b + n + 1);
    __int128 m = b[(n + 1) / 2];
    for(int i = 1; i <= n; i++)
        res += __abs(b[i] - m);
    return res;
}

void print(__int128 x) {
    if(x >= 10)
        print(x / 10);
    putchar('0' + x % 10);
}


int main() {
    n = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    
    LL L = -(2e13+10), R = 2e13 + 10;
    LL M1, M2;
    while(L < R) {
        M1 = L + (R - L) / 3;
        M2 = R - (R - L) / 3;
        if(calc(M1) < calc(M2))
            R = M2 - 1;
        else
            L = M1 + 1;
    }
    __int128 ans =calc(L);

    print(ans);
    return 0;
}