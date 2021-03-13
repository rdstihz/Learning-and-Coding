#include  <cstdio>
#define l (o<<1)
#define r (o<<1|1)
#define p (o>>1)

const int maxn = 10001;

struct MaxHeap{
	int h[maxn];
	int n;
	void init(){
		n = 0;
	}
	
	void maxHeap(int o){
		int s = o;
		if(l <= n && h[l] > h[s]) s = l;
		if(r <= n && h[r] > h[s]) s = r;
		if(s != o){
			int t = h[s]; h[s] = h[o]; h[o] = t;
			maxHeap(s);
		} 
	}
	
	void pop(){
		h[1] = h[n]; n--;
		maxHeap(1);
	}
	void insert(int value){
		int o = ++n;
		h[o] = value;
		while(p && h[o] > h[p] ){
			int t = h[o]; h[o] = h[p]; h[p] = t;
			o = p;
		}
		
	}
}maxHeap;

struct MinHeap{
	int h[maxn];
	int n;
	
	void init(){
		n = 0;
		h[1] = -2147483648;
	}
	
	void minHeap(int o){
		int s = o;
		if(l <= n && h[l] < h[s]) s = l;
		if(r <= n && h[r] < h[s]) s = r;
		if(s != o){
			int t = h[s]; h[s] = h[o]; h[o] = t;
			minHeap(s);
		}
	}
	void pop(){
		h[1] = h[n--];
		minHeap(1);
	}
	void insert(int value){
		int o = ++n;
		h[o] = value;
		while(p && h[o] < h[p]){
			int t = h[o]; h[o] = h[p]; h[p] = t;
			o = p;
		}
	}
	
	
}minHeap;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int id,m;
		scanf("%d%d",&id,&m);
		printf("%d %d\n",id,(m+1)>>1);
		
		maxHeap.init();
		minHeap.init();
		
		int v;
		for(int i = 1;i<=m;i++){
			scanf("%d",&v);
			if(v > minHeap.h[1]) minHeap.insert(v);
			else maxHeap.insert(v);
			
			if(maxHeap.n > i/2 ){
				int t = maxHeap.h[1];
				maxHeap.pop();
				minHeap.insert(t);
			}
			if(minHeap.n > (i+1)/2){
				int t = minHeap.h[1];
				minHeap.pop();
				maxHeap.insert(t);
			}
			if(i%2) printf("%d ",minHeap.h[1]);
			if((i+1) % 20 == 0) printf("\n");
		}	
	
		if((m+1)%20 != 0) printf("\n");
	}
	
	return 0;
}
