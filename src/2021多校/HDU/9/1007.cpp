#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000000 + 10;
int pos[maxn];
bool del[maxn];
deque<int> Q[2];
int s[2];

void adj() {
    if (s[0] > s[1]) {
        while (del[Q[0].back()])
            Q[0].pop_back();
        Q[1].push_front(Q[0].back());
        Q[0].pop_back();
        s[0]--, s[1]++;
        pos[Q[1].front()] = 1;
    }

    if (s[1] > s[0] + 1) {
        while (del[Q[1].front()])
            Q[1].pop_front();
        Q[0].push_back(Q[1].front());
        Q[1].pop_front();
        s[0]++, s[1]--;
        pos[Q[0].back()] = 0;
    }
}

int main() {
    int q;
    scanf("%d", &q);
    char op[2];
    int x;
    int id = 0;
    while (q--) {
        scanf("%s", op);
        if (*op == 'L') {
            Q[0].push_front(++id), s[0]++;
            pos[id] = 0;
            adj();
        } else if (*op == 'R') {
            Q[1].push_back(++id), s[1]++;
            pos[id] = 1;
            adj();
        } else if (*op == 'G') {
            scanf("%d", &x);
            del[x] = true;
            s[pos[x]]--;
            adj();
        } else if (*op == 'Q') {
            while (del[Q[1].front()])
                Q[1].pop_front();
            printf("%d\n", Q[1].front());
        }
    }

    return 0;
}