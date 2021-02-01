#include <cstdio>
#include <cstdlib> 

const int maxn = 100000 + 100;
int a[maxn];

//�������� 
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


//���ֲ���
//�½�,��a[l...r]���ҵ�һ�����ڵ���value���� 
int lower_bound(int l,int r,int value){
	int m;
	
	while(l<r){
		m = l+r>>1;
		if(a[m] < value ) l = m+1;
		else r = m;
	}
	
	return l;
} 

//�Ͻ�,��a[l...r]���ҵ�һ������value���� 

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
	
	//���� 
	sort(1,n);
	
	for(int i = 1;i<=n;i++) printf("%d ",a[i]);
	
	
	return 0;
}
