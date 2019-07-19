#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll SIZE = 2e5+5;
ll a[SIZE],n,m;
char op[2];
ll l,r;
ll read() {
	ll   x = 0, f = 1;
	char ch = getchar();

	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}

	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

struct txx {
	ll *a;
	struct tree {
		int l,r,max,lz;
		void update(int x) {
			max = x;
			lz = 0;
		}
	} t[SIZE*4];

	void modify(ll *arr) {
		a = arr;
	}

	void pushup(int P) {
		t[P].max = max(t[2 * P].max, t[2 * P + 1].max);
	}

	void pushdown(int p) {
		if (t[p].lz != 0) {
			t[2 * p].update(t[p].lz);
			t[2 * p + 1].update(t[p].lz);
			t[p].lz = 0;
		}
	}

	void build(int p,int l,int r) {
		t[p].l=l;
		t[p].r=r;
		t[p].max = 0;
		if(l==r) {
			t[p].max=a[l];
			return;
		}
		int mid=(l+r)/2;
		build(p*2,l,mid);
		build(p*2+1,mid+1,r);
		pushup(p);
	}

	void change(int p,int x,int d) {
		if(t[p].l==t[p].r) {
			t[p].update(d);
			return;
		}
		int mid=(t[p].l+t[p].r)/2;
		if(x<=mid) change(p*2,x,d);
		else change(p*2+1,x,d);
		pushup(p);
	}

	long long ask(int p,int l,int r) {
		if(l<=t[p].l&&r>=t[p].r)
			return t[p].max;
		int mid = (t[p].l+t[p].r)>>1;
		long long val = -(1<<30);
		pushdown(p);
		if(l<=mid) val=max(val,ask(p*2,l,r));
		if(r>mid) val=max(val,ask(p*2+1,l,r));
		pushup(p);
		return val;
	}
} t;

int main() {
	n = read();
	m = read();
	for(int i=1; i<=n; i++) {
		a[i] = read();
	}
	t.modify(a);
	t.build(1,1,n);
	while(m--) {
		scanf("%s",op);
		l = read();
		r = read();
		if(op[0]=='Q') {
			printf("%lld\n",t.ask(1,l,r));
		} else if(op[0]=='U') {
			t.change(1,l,r);
		}
	}
}
