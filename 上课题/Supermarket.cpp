#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
int fa[MAXN];
struct x {
	int p,d;
} a[MAXN];
bool cmp(x b,x c) {
	return b.p>c.p;
}
int find(int z) {
	if(fa[z]==-1) return z;
	return fa[z]=find(fa[z]);
}
int main() {
	int n;
	memset(fa,-1,sizeof(fa));
	while(cin>>n) {
		for(int i=0; i<n; i++) {
			cin>>a[i].p>>a[i].d;
		}
		int sum=0;
		sort(a,a+n,cmp);
		for(int i=0; i<n; i++) {
			int	t=find(a[i].d);
			if(t>0) {
				sum+=a[i].p;
				fa[t]=t-1;
			}
		}
		cout<<sum<<endl;
	}
}

