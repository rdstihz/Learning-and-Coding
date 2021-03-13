#include <cstdio>

const int maxn = 100000 +100; 
bool ok[40][2];

char op[maxn][5];
int value[maxn];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i = 1;i<=n;i++)
		scanf("%s%d",op[i],value+i);
	
	for(int i = 0;i<31;i++){
		//1.第i位填0 
		int t = 0;
		for(int j = 1;j<=n;j++){
			if(op[j][0] == 'A') t &= value[j];
			else if(op[j][0] == 'O') t |= value[j];
			else if(op[j][0] == 'X') t ^= value[j];
		}
		
		if(t & (1 << i)) ok[i][0] = true;
		//2.第i位填1 
		t = 1<<i;
		for(int j = 1;j<=n;j++){
			if(op[j][0] == 'A') t &= value[j];
			else if(op[j][0] == 'O') t |= value[j];
			else if(op[j][0] == 'X') t ^= value[j];
		}
		if(t&(1<<i)) ok[i][1] = true; 
		
	}
	int ans = 0;
	
	for(int i = 30;i>=0;i--){
		if(ok[i][0]) ans += (1<<i);
		else if(ok[i][1] && m >= (1<<i) ){
			ans += (1<<i);
			m -= (1<<i);
		} 
		
	} 
	
	
	printf("%d\n",ans);
} 
