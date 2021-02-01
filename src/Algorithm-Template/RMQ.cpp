#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 50000 + 10;
const int N = 15; 
int log_2[maxn];
int st[maxn][N];

int main(){
	
	log_2[1] = 0;
	for(int i = 2;i<=50000;i++) log_2[i] = log_2[i/2] + 1;
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i = 1;i<=n;i++) scanf("%d",&st[i][0]);
	
	//Ô¤´¦ÀíST±í
	for(int k = 1;k<=N;k++)
		for(int i = 1;i+(1<<k)-1 <=n; i++)
			st[i][k] = min(st[i][k-1],st[i+(1<<k-1)][k-1]); 
	
	int a,b;
	for(int i = 1;i<=m;i++){
		scanf("%d%d",&a,&b);
		int t = log_2[b-a+1];
		printf("%d\n",min(st[a][t],st[b-(1<<t) +1][t]));
	}
	
	
	return 0;
} 
