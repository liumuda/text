#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx=1e6+100;
const int INF=1e9;
const int MOD=1e8;
int prime[maxx],ff[maxx];
int k;
void init(int n) {
	memset(ff,0,sizeof(ff));
	ff[1]=1;
	k=0;
	for(int i=2; i<=n; i++) {
		if(!ff[i]) {
			prime[k++]=i;
			for(int j=i; j<=n/i; j++) {
				ff[j*i]=1;
			}
		}
	}
}
int main() {
	int n;
	scanf("%d",&n);
	init(n);
	for(int i=0; i<k; i++) {
		ll v=0;
		ll p=prime[i];
		printf("%d ",p);
		while(p<=n) {
			v+=n/p;
			p*=prime[i];
		}
		printf("%d\n",v);
	}
	return 0;
}
