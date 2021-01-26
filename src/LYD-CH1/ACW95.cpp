#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int map[5][5];
int b_map[5][5];

int read(){
	char c = getchar();
	while(c != '0' && c != '1') c = getchar();
	return c-'0';
}


int work(int S){
	int count = 0;
	memcpy(b_map,map,sizeof(map));
	
	//第一行 
	for(int i = 0;i<5;i++){
		if(S & (1<<i)){ 
			count++;
			b_map[0][i] ^= 1;
			b_map[1][i] ^= 1;
			if(i>0) b_map[0][i-1] ^= 1;
			if(i<4) b_map[0][i+1] ^= 1;
		}
	}
	
	//2-5行
	for(int i = 1;i<5;i++) {
		for(int j = 0;j<5;j++) if(!b_map[i-1][j]){
			count++;
			b_map[i-1][j] ^= 1; b_map[i][j] ^= 1;
			if(j>0) b_map[i][j-1] ^= 1;
			if(j<4) b_map[i][j+1] ^= 1;
			if(i<4) b_map[i+1][j] ^= 1;
			
		}
	} 
	
	for(int i = 0;i<5;i++) if(!b_map[4][i]){
		return 100;
	}
	return count;
	
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i = 0;i<5;i++)
			for(int j = 0;j<5;j++)
				map[i][j] = read();
		
		int ans = 100;
		
		for(int S = 0;S < 32;S++){
			ans = min(ans,work(S));
		} 
		if(ans > 6) printf("-1\n");
		else printf("%d\n",ans);
	} 
	
	
	return 0;
} 
