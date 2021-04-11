#include <cstdio>

int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();

    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

bool check(int h, int m) {
    int ah = (h % 10) * 10 + h / 10;
    return ah == m;
}

int main() {

    int h = read();
    int m = read();
    int hh = h;
    int mm = m;

    //上一个

    while (true) {
        m--;
        if (m < 0) {
            h--;
            m = 59;
        }
        if (h < 0) {
            h = 23;
        }

        if (check(h, m)) {
            printf("%d:%d\n", h, m);
            break;
        }
    }
    h = hh;
    m = mm;
    while (true) {
        m++;
        if (m >= 60) {
            h++;
            m = 0;
        }
        if (h >= 24) {
            h = 0;
        }
        if (check(h, m)) {
            printf("%d:%d\n", h, m);
            break;
        }
    }

    return 0;
}