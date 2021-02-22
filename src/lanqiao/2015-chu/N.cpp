#include <cstring>
#include <iostream>

using namespace std;

char M[1100][1100];

int main() {
    int n, m;
    while (cin >> n >> m) {
        memset(M, '.', sizeof(M));
        for (int i = 0; i < m; i++) {
            for (int j = i; j < i + n; j++)
                M[i][j] = '*';
        }
        for (int i = 0; i < m; i++) {
            for (int j = m + n - 2 - i; j > m - 2 - i; j--)
                M[i][j] = '*';
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m + n - 1; j++)
                cout << M[i][j];
            cout << endl;
        }
    }

    return 0;
}