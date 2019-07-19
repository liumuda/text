#include <iostream>
#include <stdio.h>
using namespace std;

const int SIZE = 50000+10; 
int a[SIZE],T,n;
struct tree {
	int l,r,sum;
} t[SIZE*4];

void build(int p,int l,int r) {
	t[p].l=l,t[p].r=r;
	if(l==r) {
		t[p].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
}

void change(int p,int x,int d) {
	if(t[p].l==t[p].r) {
		t[p].sum+=d;
		return;
	}
	int mid=(t[p].l+t[p].r)/2;
	if(x<=mid) change(p*2,x,d);
	else change(p*2+1,x,d);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
}

long long ask(int p,int l,int r) {
	if(l<=t[p].l&&r>=t[p].r) return t[p].sum;
	int mid=(t[p].l+t[p].r)/2;
	long long val = 0;
	if(l<=mid) val += ask(p*2,l,r);
	if(r>mid) val += ask(p*2+1,l,r);
	return val;
}

int main() {
	scanf("%d",&T);
	for(int i=1; i<=T; i++) {
		scanf("%d",&n);
		for(int j=1; j<=n; j++) {
			scanf("%d",&a[j]);
		}
		for(int k=0;k<= 4*n; k++)
		{
			t[k].l=0;
			t[k].r=0;
			t[k].sum=0;
		}
		build(1,1,n);
		
		string op;
		int l,r;
		printf("Case %d:\n",i);
		while(cin>>op) {
			if(op=="Add") {
				scanf("%d%d",&l,&r);
				change(1,l,r);
			} else if(op=="Sub") {
				scanf("%d%d",&l,&r);
				change(1,l,-r);
			} else if(op=="Query") {
				scanf("%d%d",&l,&r);
				printf("%lld\n",ask(1,l,r));
			} else if(op=="End")  break;
		}
	}
}
