#include <cstdio>

int n,m;
int res[30];
void dfs(int d,int c){
	if(c == m+1){
		for(int i = 1;i<=m;i++)
			printf("%d ",res[i]);
		printf("\n");
		return ;
	}
	if(d == n+1) return ;
	
	for(int i = d;i<=n;i++){
		res[c] = i;
		dfs(i+1,c+1);
	}
	
	
}

int main(){
	scanf("%d%d",&n,&m);
	
	dfs(1,1);
	
	return 0;
}
