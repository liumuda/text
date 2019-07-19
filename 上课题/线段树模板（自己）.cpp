#include <bits/stdc++.h>
using namespace std;
int a[100010],n,m;
struct tree{
	int l,r;
	long long sum,add;
}t[100010*4];

void build(int p,int l,int r){
	t[p].l=l;
	t[p].r=r;
	if(l==r){
		t[p].sum=a[l];return ;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
}

void spread(int p){
	if(t[p].add){
		t[p*2].sum+=t[p].add*(t[p*2].r-t[p*2].l+1);
		t[p*2+1].sum+=t[p].add*(t[p*2+1].r-t[p*2+1].l+1);
		t[p*2].add+=t[p].add;
		t[p*2+1].add+=t[p].add;
		t[p].add=0;
	}
}

void change(int p,int l,int r,int d){
	if(l<=t[p].l&&r>=t[p].r){
		t[p].sum+=(long long )d*(t[p].r-t[p].l+1);
		t[p].add+=d;
		return;
	}
	spread(p);
	int mid=(t[p].l+t[p].r)/2;
	if(l<=mid) change(p*2,l,r,d);
	if(r>mid) change(p*2+1,l,r,d);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
}

long long ask(int p,int l,int r){
	if(l<=t[p].l&&r>=t[p].r) return t[p].sum;
	spread(p);
	int mid=(t[p].l+t[p].r)/2;
	long long val = 0;
	if(l<=mid) val += ask(p*2,l,r);
	if(r>mid) val += ask(p*2+1,l,r);
	return val;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	while(m--){
		char op[2];
		int l,r,d;
		scanf("%s%d%d",op,&l,&r);
		if(op[0]=='c'){
			scanf("%d",&d);
			change(1,l,r,d);
		}
		else printf("%lld\n",ask(1,l,r));
	}
}
