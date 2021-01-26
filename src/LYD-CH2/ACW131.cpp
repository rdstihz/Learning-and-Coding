#include <cstdio>

const int maxn = 100000 + 10;
int h[maxn];
int st[maxn],top;
int left[maxn],right[maxn];

int main(){
	
	int n;
	while(scanf("%d",&n),n) {
		for(int i = 1;i<=n;i++)
			scanf("%d",h+i);
		
		h[0] = -1;
		h[n+1]  = -1;
		
	
		top = 0;
		st[0] = 0;
		for(int i = 1; i<=n; i++) {
			while(h[st[top]] >= h[i]) top--;
			left[i] = st[top] + 1;
			st[++top] = i;
		}
		
		top = 0;
		st[0] = n + 1;
		for(int i = n; i >= 1; i--) {
			while(h[st[top]] >= h[i]) top--;
			right[i] = st[top] - 1;
			st[++top] = i;
		}
		
		long long res = 0;
		for(int i = 1;i<=n;i++){
			long long t = (long long )h[i] * (right[i] - left[i] + 1);
			res = res > t ? res : t; 
		}
		printf("%lld\n",res);
	}
	
	return 0;
}
