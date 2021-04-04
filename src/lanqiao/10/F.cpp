#include <iostream>

using namespace std;

const int maxn = 100000 + 100;

int floor[maxn];

long long v[maxn];

int main() {

    floor[0] = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        floor[i] = floor[i >> 1] + 1;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        v[floor[i]] += x;
    }
    int maxf = 0;
    long maxv = -100000000000000;

    for(int i = 1; i <= floor[n]; i++) {
        if(v[i] > maxv) {
            maxf = i;
            maxv = v[i];
        }
        
    }
    cout << maxf << endl;
    return 0;
}