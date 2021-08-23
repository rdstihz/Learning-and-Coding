/*
    Created by rdstihz at 2021-07-18 00:28:21
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
char s[maxn];
int cnt[26];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);

        for (int i = 0; i < 26; i++)
            cnt[i] = 0;
        for (int i = 1; i <= n; i++)
            cnt[s[i] - 'a']++;

        vector<int> chs;
        for (int i = 0; i < 26; i++)
            if (cnt[i]) chs.push_back(i);

        if (chs.size() <= 1) { //只有一种字符
            printf("%s\n", s + 1);
            continue;
        }

        //单个字符
        bool flag = false;
        int pos;
        for (int i : chs) {
            if (cnt[i] == 1) {
                flag = true;
                pos = i;
                break;
            }
        }
        if (flag) {
            printf("%c", 'a' + pos);
            cnt[pos]--;
            for (int i : chs)
                while (cnt[i]-- > 0)
                    printf("%c", 'a' + i);
            printf("\n");
            continue;
        }

        //能插的
        int a = chs[0];
        if (cnt[a] <= n / 2 + 1) { // aabababacadae
            printf("%c%c", 'a' + a, 'a' + a), cnt[a] -= 2;

            for (int i : chs) {
                if (i == a) continue;
                while (cnt[i] > 0) {
                    printf("%c", 'a' + i);
                    cnt[i]--;
                    if (cnt[a] > 0) {
                        printf("%c", 'a' + a);
                        cnt[a]--;
                    }
                }
            }
            printf("\n");
            continue;
        }

        //只有两种字符
        // abbbbbbaaaaa
        int b = chs[1];
        if (chs.size() == 2) {
            printf("%c", 'a' + a), cnt[a]--;
            while (cnt[b] > 0) {
                printf("%c", 'a' + b);
                cnt[b]--;
            }
            while (cnt[a] > 0) {
                printf("%c", 'a' + a);
                cnt[a]--;
            }

            printf("\n");
            continue;
        }

        if (chs.size() >= 3) {
            //aabaaaacbbccdddd
            int c = chs[2];
            printf("%c", 'a' + a), cnt[a] -= 1;
            printf("%c", 'a' + b), cnt[b]--;
            if (cnt[a] > 0) {
                while (cnt[a] > 0) {
                    printf("%c", 'a' + a), cnt[a]--;
                }
                printf("%c", 'a' + c), cnt[c]--;
            }

            for (int i : chs) {
                while (cnt[i] > 0) {
                    printf("%c", 'a' + i);
                    cnt[i]--;
                }
            }

            printf("\n");
            continue;
        }
    }

    return 0;
}

//tutttttttttttttttttvuuuuuuuuvvvv