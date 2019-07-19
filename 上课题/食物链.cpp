#include <cstdio>
#define MAX_N 200001
int par[MAX_N];
int n,k;
void init(int m) {
	for (int i=1;i<=m;i++) par[i]=i;
}
int find(int a) {
	if (par[a]==a) return a;
	int t=a;
	while (par[a]!=a) {
		a=par[a];
	}
	while (par[t]!=t) {
		int t2=t;
		t=par[t];
		par[t2]=a;
	}
	return a;
}
void unite(int a,int b) {
	a=find(a);
	b=find(b);
	if (a!=b) par[a]=b;
}
bool same(int a,int b) {
	return find(a)==find(b);
}
int main() {
	scanf("%d%d",&n,&k);
	init(n*3);
	int ans=0;
	for (int i=0;i<k;i++) {
		int d,x,y;
		scanf("%d%d%d",&d,&x,&y);
		if (x>n || y>n) {
			ans++;
			continue;
		}
		if (d==1) {
			if (same(x,y+n)||same(x,y+n*2)) {
				ans++;
			}
			else {
				unite(x,y);
				unite(x+n,y+n);
				unite(x+n*2,y+n*2);
			}
		}
		else {
			if (same(x,y)||same(x,y+n*2)) {
				ans++;
			}
			else {
				unite(x,y+n);
				unite(x+n,y+n*2);
				unite(x+n*2,y);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

