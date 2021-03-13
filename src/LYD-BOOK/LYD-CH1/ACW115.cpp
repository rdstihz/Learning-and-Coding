#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1010;
struct Node{
	int father,size,sum;
	double avg;
}node[maxn];
bool del[maxn];

int n,r;

int find(){
	int res = 0;
	double maxv = 0;
	for(int i = 1;i<=n;i++) {
		if(i != r && node[i].avg > maxv ){
			maxv = node[i].avg;
			res = i;
		}
		
	}
	return res;
}


int main(){
	while(cin >> n >> r , n||r){
		int ans = 0;
		for(int i = 1;i<=n;i++){
			cin >> node[i].sum;
			ans += node[i].sum;
			node[i].size = 1;
			node[i].avg = node[i].sum;
			node[i].father = 0;
		}
		
		for(int i = 1,a,b;i<n;i++){
			cin >> a >> b;
			node[b].father = a;
		}
		
		for(int i = 1;i<n;i++){
			int x = find();
			int f = node[x].father;
			
			ans += node[f].size * node[x].sum;
			//合并两个点 
			node[f].sum += node[x].sum;
			node[f].size += node[x].size;
			node[f].avg = (double)node[f].sum/node[f].size;
			
			for(int j = 1;j<=n;j++) if(node[j].father == x) 
				node[j].father = f;
			
			//删除点x
			node[x].avg = 0; 
			
		}
		cout << ans << endl;
	}
	
	
	return 0;
} 
