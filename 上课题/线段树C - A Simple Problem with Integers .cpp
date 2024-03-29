#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
const ll N   = 2e5 + 5;
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

struct segt {
	ll *a;
	struct Tree {
		int l, r;
		ll  sum, lz;
		void update(ll v) {
			sum += v*(r-l+1);
			lz  += v;
		}
	} tree[N * 4];

	void modify(ll *arr) {
		a = arr;
	}

	void pushup(int x) {
		tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
	}

	void pushdown(int x) {
		if (tree[x].lz != 0) {
			tree[2 * x].update(tree[x].lz);
			tree[2 * x + 1].update(tree[x].lz);
			tree[x].lz = 0;
		}
	}

	void build(int x, int l, int r) {
		tree[x].l   = l;
		tree[x].r   = r;
		tree[x].sum = tree[x].lz = 0;

		if (l == r) {
			tree[x].sum =a[l];

			return;
		}
		int mid = (l + r) / 2;
		build(2 * x,     l,       mid);
		build(2 * x + 1, mid + 1, r);
		pushup(x);
	}

	void update(int x, int l, int r, ll c) {
		int L = tree[x].l, R = tree[x].r;
		int mid = (L + R) / 2;

		if ((l <= L) && (r >= R)) {
			tree[x].update(c);
			return;
		}
		pushdown(x);

		if (l <= mid) update(2 * x, l, r, c);

		if (r > mid) update(2 * x + 1, l, r, c);
		pushup(x);
	}

	ll querySUM(int x, int l, int r) {
		int L = tree[x].l, R = tree[x].r;
		int mid = (L + R) / 2;
		ll  res = 0;

		if ((l <= L) && (r >= R)) { 
			return tree[x].sum;
		}

		pushdown(x);

		if (l <= mid) res += querySUM(2 * x, l, r);

		if (r > mid) res += querySUM(2 * x + 1, l, r);
		pushup(x);
		return res;
	}
} tree;

int  n, m, l, r, v;
ll   a[N], ans;
char ope;

int main() {
	n = read();
	m = read();

	for (int i = 1; i <= n; i++) a[i] = read();
	tree.modify(a);
	tree.build(1, 1, n);

	while (m--) {
		cin >> ope;
		l   = read(), r = read();
		if (ope == 'Q') {
			ans = tree.querySUM(1, l, r);
			printf("%lld\n", ans);
		} else {
			v = read();
			tree.update(1, l, r, v);
		}
	}
return 0;
}
