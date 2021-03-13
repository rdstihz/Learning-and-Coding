#include <cstdio>

bool vis[30];
int p[30];
int n;

void dfs(int d){
	
	if(d == n+1) {
		for(int i = 1;i<=n;i++)
			printf("%d ",p[i]);
		printf("\n");
	}
	
	for(int i = 1;i<=n;i++) if(!vis[i]) {
		p[d] = i;
		vis[i] = true;
		dfs(d+1);
		vis[i] = false;
	}
	
} 

int main(){
	
	scanf("%d",&n);
	
	dfs(1);
	
	return 0;
}
