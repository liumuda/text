#include <bits/stdc++.h>
using namespace std;

const int size=0x3f3f;
int a[size]={0};
struct tree {
	int l,r,dat;
} t[size*4];

void build(int p,int l,int r) {
	t[p].l=l,t[p].r=r;
	if(l==r) {
		t[p].dat=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].dat = max(t[p*2].dat,t[p*2+1].dat);
}

void change(int p,int x,int v) {
	if(t[p].l == t[p].r) {
		t[p].dat=v;
		return ;
	}
	int mid=(t[p].l+t[p].r)/2;
	if(x<=mid) change(p*2,x,v);
	else change(2*p+1,x,v);
	t[p].dat = max(t[p*2].dat,t[p*2+1].dat);
}

int ask(int p,int l,int r) {
	if(l<=t[p].l&&r>=t[p].r) return t[p].dat;
	int mid= (t[p].l+t[p].r)/2;
	int val = -(1<<30);
	if(l<=mid) val = max(val,ask(2*p,l,r));
	if(r>mid) val = max(val,ask(2*p+1,l,r));
	return val;
}

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	while(m--) {
		char cp[10];
		int x,v,l,r;
		scanf("%s",cp);
		if(cp[0]=='c') {
			scanf("%d%d",&x,&v);
			change(1,x,v);
		} else if(cp[0]=='a') {
			scanf("%d%d",&l,&r);
			printf("max = %d\n",ask(1,l,r));
		}
	}
}
