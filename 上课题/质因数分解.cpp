#include <bits/stdc++.h>
using namespace std;
int v[100010],prime[100010],p[100010],m=0,k=0;
void primes(int n) {
	memset(v,0,sizeof(v));
	m = 0;
	for(int i=2; i<=n; i++) {
		if(v[i]==0) {
			v[i]=i;
			prime[++m]=i;
		}
		for(int j=1; j<=m; j++) {
			if(v[i]<prime[j]||prime[j]>n/i) break;//i有比prime[j]更小的质因子，或者超出n的范围，停止循环
			v[i*prime[j]] = prime[j]; //prime[j]是合数i*prime[j]的最小质因子
		}
	}
}

int main() {
	int n;
	cin>>n;
	primes(n);
	int x=n;
	for(int i=1; i<=m; i++) {
		if(n%prime[i]==0) {
			p[++k]=prime[i];
			n/=prime[i];
		}
	}
	printf("%d=",x);
	for(int i=1; i<k; i++) {
		printf("%d*",p[i]);
	}
	cout<<p[k];
}

