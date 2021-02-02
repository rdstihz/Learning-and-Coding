#include <queue>
#include <iostream>

using namespace std;

const int maxn = 30000 + 100;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int a[maxn], u[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> u[i];
    }

    int i = 0;
    int p = 1;

    for (int k = 1; k <= n; k++) {
        while (p <= m && u[p] == maxHeap.size() + minHeap.size()) {
            cout << minHeap.top() << endl;
            maxHeap.push(minHeap.top());
            minHeap.pop();
            i++;
            p++;
        }

        
        maxHeap.push(a[k]);
        
        while (maxHeap.size() > i) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    while (p <= m && u[p] == maxHeap.size() + minHeap.size()) {
        cout << minHeap.top() << endl;
        maxHeap.push(minHeap.top());
        minHeap.pop();
        i++;
        p++;
    }

    return 0;
}