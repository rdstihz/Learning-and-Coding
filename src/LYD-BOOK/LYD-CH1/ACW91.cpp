#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 25;

int dist[maxn][maxn];
int d[1100000][maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			scanf("%d",&dist[i][j]);
	
	memset(d,0x3f,sizeof(d));
	
	d[1][0] = 0;
	for(int S = 1;S<1<<n;S++){
		for(int i = 0;i<n;i++) if(S & (1<<i) )
			for(int k = 0;k<n;k++) if( (S^(1<<i)) & (1<<k) )
				d[S][i] = min(d[S][i],d[S^(1<<i)][k] + dist[k][i] ); 
		
	}
	
	printf("%d\n",d[(1<<n)-1][n-1]);		
	
	
	return 0; 
} 
