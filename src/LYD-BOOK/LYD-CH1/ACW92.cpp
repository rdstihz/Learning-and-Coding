#include <cstdio>

int n;
int choose[20];

void dfs(int d){
	
	if(d == n+1){
		for(int i = 1;i<=n;i++)
			if(choose[i]) printf("%d ",i);
		printf("\n");
		return ;
	}
	choose[d] = 0;
	dfs(d+1);
	choose[d] = 1;
	dfs(d+1); 
	
	
}

int main(){
	scanf("%d",&n);
	dfs(1);
	return 0;
}
