#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    if (n == 2 && k == 1)
        cout << "Yes" << endl;
    else if (n == 2 && k == 2)
        cout << "Yes" << endl;
    else if(n == 2 && k == 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}