#include <cstdio>
#include <cstring>

using namespace std;

const int reversable[] = {0, 1, 2, 5, 8};
const int revers[] = {0, 1, 5, 2, 8};

int rev[110];

void init() {
    memset(rev, -1, sizeof(rev));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            int a = reversable[i];
            int b = reversable[j];

            rev[a * 10 + b] = revers[j] * 10 + revers[i];
        }
}

int h, m;

inline bool check(int sh, int sm) {

    int eh = rev[sm];
    int em = rev[sh];

    if (eh < 0 || em < 0)
        return false;
    if (eh >= h || em >= m)
        return false;
    return true;
}

int main() {

    //printf("%d", check(0, 1));

    int T;
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &h, &m);
        int sh, sm;
        scanf("%02d:%02d", &sh, &sm);

        while (true) {
            if (check(sh, sm)) {
                printf("%02d:%02d\n", sh, sm);
                break;
            }
            sm++;
            if (sm >= m) {
                sm = 0;
                sh++;
            }
            if (sh >= h) {
                sh = 0;
            }
        }
    }

    return 0;
}