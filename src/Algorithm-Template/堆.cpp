#include <cstdio>

#define lc (o<<1)
#define rc (o<<1|1)
#define p (o>>1)

const int maxn = 1000000 + 10;
int a[maxn];
int cnt; 


void minHeap(int o){
	int s = o;
	if(lc <= cnt && a[lc] < a[s]) s = lc;
	if(rc <= cnt && a[rc] < a[s]) s = rc;
	if(s != o){
		int t = a[o]; a[o] = a[s]; a[s] = t;
		minHeap(s);
	}
	
}

int pop(){
	int t = a[1];
	a[1] = a[cnt--];
	minHeap(1);
	return t;
}

void insert(int value){
	int o = ++cnt;
	a[o] = value;
	
	while(p && a[o] < a[p]){
		int t = a[o]; a[o] = a[p]; a[p] = t;
		o = p;
	}
}


int main(){
	cnt = 0;
	int n;
	scanf("%d",&n);
	int op,v;
	while(n--){
		scanf("%d",&op);
		
		if(op == 1){
			scanf("%d",&v);
			insert(v);
		}else if(op == 2){
			printf("%d\n",a[1]);
		}else if(op == 3){
			pop();
		}
		
	}	
	
	return 0;
}
