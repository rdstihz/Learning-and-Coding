//N E S W
//N->E, N->S, N->W, E->S, E->W, E->N, S->W, S->N, S->E, W->N, W->E W->S.

#include <bits/stdc++.h>

using namespace std;

int fr[] = {0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3};
int to[] = {1, 2, 3, 2, 3, 0, 3, 0, 1, 0, 1, 2};
int conf[12][12];
int id[4][4];
char* dir = "NESW";

void init() {
    for (int i = 0; i < 12; i++)
        id[fr[i]][to[i]] = i;

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++) {
            cout << dir[fr[i]] << "->" << dir[to[i]] << " ";
            cout << dir[fr[j]] << "->" << dir[to[j]] << " ";
            cout << endl;
            cin >> conf[i][j];
        }
    for (int i = 0; i < 12; i++) {
        cout << "{" << conf[i][0];
        for (int j = 1; j < 12; j++) {
            cout << ", " << conf[i][j];
        }
        cout << "}" << endl;
    }
}

int main() {
    init();

    return 0;
}