#include <cstdio>

using namespace std;

int lowbit(int x) {
    return x & -x;
}

int n;
void print(int x) {
    for(int i = n - 1; i >= 0; i--)
        if(x >> i & 1) printf("X");
    else   
        printf("O");
    printf("\n");
}

int main() {

    scanf("%d", &n);
    int t = 0;

    for(int i = 1; i <= 1 << n; i++) {
        print(t);
        t ^= lowbit(i);
    }
    print(0);


    return 0;
}