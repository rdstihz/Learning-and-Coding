#include <cstdio>
#include <algorithm>
#define l (o<<1)
#define r (o<<1|1)
#define p (o>>1)

using namespace std;

const int maxn = 50000 + 100;

struct MinHeapP{
	
	int h[maxn],v[maxn];
	int n;
	
	void minHeap(int o){
		int s = o;
		if(l<=n && v[h[l]] < v[h[s]] ) s = l;
		if(r<=n && v[h[r]] < v[h[s]] ) s = r;
		if(s != o){
			int t = h[s]; h[s] = h[o]; h[o] = t;
			minHeap(s);
		}
	}
	
	int top(){
		return h[1];
	}
	void pop(){
		h[1] = h[n--];
		minHeap(1);
	}
	void insert(int id,int value){
		int o = ++n;
		h[o] = id;
		v[id] = value;
		
		while(p && v[h[p]] > v[h[o]] ){
			int t = h[p]; h[p] = h[o]; h[o] = t;
			o = p;
		}
	}

}heap;
int ans[maxn];
int a[maxn],b[maxn];
int q[maxn];
bool cmp(int x,int y){
	return a[x] < a[y];
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		q[i] = i;
		scanf("%d%d",a+i,b+i);
	}
	sort(q+1,q+1+n,cmp);
	
	
	int cnt = 0;
	
	for(int e = 1,i;e<=n;e++){
		i = q[e];
		if(!heap.h[1] || heap.v[heap.h[1]]>=a[i] ){ //ÐÂ½¨
			ans[i] = ++cnt; 
			heap.insert(cnt,b[i]);
		}
		else{
			ans[i] = heap.h[1];
			heap.v[heap.h[1]] = b[i];
			heap.minHeap(1);
		}
		
	}
	
	printf("%d\n",cnt);
	for(int i = 1;i<=n;i++)
		printf("%d\n",ans[i]);
	
	return 0;
}
