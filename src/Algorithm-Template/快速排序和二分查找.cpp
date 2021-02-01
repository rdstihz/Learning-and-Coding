#include <cstdio>
#include <cstdlib> 

const int maxn = 100000 + 100;
int a[maxn];

//快速排序 
void sort(int l,int r){
	if(l>=r) return;
	
	int x0 = a[r];
	int p = l;
	
	for(int i = l;i<r;i++){
		if(a[i] < x0 ) {
			int t = a[i];
			a[i] = a[p];
			a[p] = t;
			p++;
		}
	}
	a[r] = a[p];
	a[p] = x0;
	
	sort(l,p-1);
	sort(p+1,r);
}


//二分查找
//下界,在a[l...r]查找第一个大于等于value的数 
int lower_bound(int l,int r,int value){
	int m;
	
	while(l<r){
		m = l+r>>1;
		if(a[m] < value ) l = m+1;
		else r = m;
	}
	
	return l;
} 

//上界,在a[l...r]查找第一个大于value的数 

int upper_bound(int l,int r,int value){
	int m;
	while(l<r){
		m = l+r>>1;
		if(a[m] <= value) l = m+1;
		else r = m;
	}
	return l;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)	scanf("%d",a+i);
	
	//排序 
	sort(1,n);
	
	for(int i = 1;i<=n;i++) printf("%d ",a[i]);
	
	
	return 0;
}
