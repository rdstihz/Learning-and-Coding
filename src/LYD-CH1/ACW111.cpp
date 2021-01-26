#include <cstdio>
#include <algorithm>
#define l (o<<1)
#define r (o<<1|1)
#define p (o>>1)

using namespace std;

const int maxn = 50000 + 10;
int a[maxn],b[maxn];
int q[maxn];

bool cmp(int x,int y){
	return a[x] < a[y];
}


struct Heap{
	int h[maxn],v[maxn];
	int size;
	
	void minHeap(int o){
		int s = o;
		if(l <= size && v[h[l]] <= v[h[s]] ) s = l;
		if(r <= size && v[h[r]] <= v[h[s]] ) s = r;
		if(s != o){
			int t = h[s]; h[s] = h[o]; h[o] = t;
			minHeap(s);
		}
	}
	int top(){
		return h[1];
	}
	void pop(){
		h[1] = h[size--];
		minHeap(1);
	}
	void insert(int value){
		int o = ++size;
		v[o] = value;
		h[o] = o;
		
		while(p && v[h[o]] < v[h[p]]){
			int t = h[p]; h[p] = h[o]; h[o] = t;
			o = p;
		}
	}
	
	
}heap;

int pos[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d%d",a+i,b+i);
	for(int i = 1;i<=n;i++) q[i] = i;
	
	sort(q+1,q+1+n,cmp);
	
	for(int e = 1;e<=n;e++){
		int i = q[e];
		if(heap.top() && heap.v[heap.top()] < a[i] ){
			pos[i] = heap.top();
			heap.v[heap.top()] = b[i];
			heap.minHeap(1);
		}else{
			heap.insert(b[i]);
			pos[i] = heap.size;
		}
		
	}
	
	printf("%d\n", heap.size);
	for(int i = 1;i<=n;i++) printf("%d\n",pos[i]);
	
	return 0;
}

