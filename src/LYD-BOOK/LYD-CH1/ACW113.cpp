// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

#include <vector>
#include <cstdio>
using namespace std;

bool compare(int a,int b){
	return a>b;
}

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> V(N);
        
        for(int k = 1;k<=N;k++){
        	int l = 1,r = k;
        	int m;
        	while(l<r){
        		m = l+r >> 1;
        		if(compare(k,V[m-1])) r = m;
        		else l = m+1;
			}
        	
        	for(int i = k-1;i>=l;i--) V[i] = V[i-1];
        	V[l-1] = k;
		}
        return V;
    }
};



int main(){
	vector<int> v = (new Solution())->specialSort(10);
	for(auto it = v.begin();it != v.end();it++) printf("%d ",*it);
}


1 2 
