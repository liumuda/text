#include <cstdio>
#include <cstring>

using namespace std;
#define ll = long long;
const int maxn = 1e5 + 10;

int n, m;
int a[maxn], s[maxn], c[maxn]; // a为原数组，s为前缀和数组，c为树状数组

void add(int x, int d) {
	for (; x <= n; x += x&(-x))
		c[x] += d;
}

int ask(int x) {
	int ans = a[x];
	for (; x; x -= x&(-x))
		ans += c[x];
	return ans;
}

int main() {
	// freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	char ops[2];
	int l, r, d;

	for (int i = 1; i <= m; i++) {
		scanf("%s%d", ops, &l);
		if (ops[0] == 'Q')
			printf("%d\n", ask(l));
		else {
			scanf("%d%d", &r, &d);
			add(l, d);
			add(r+1, -d);
		}
	}

	return 0;
}

