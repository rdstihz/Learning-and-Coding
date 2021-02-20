#include <bits/stdc++.h>

using namespace std;

int read(){
    int x = 0;
    int sgn = 1; //正负
    char c = getchar();
    while((c < '0' || c > '9') && c != '-') c = getchar(); // 舍弃掉前面的非数字且不是负号的字符
    if(c == '-') {
        sgn = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        x = x * 10 + c - '0'; // 把字符c拼到结果x的后面
        c = getchar();
    }
    return sgn * x;
}

int main(){

}