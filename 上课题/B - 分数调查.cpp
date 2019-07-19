#include <bits/stdc++.h>
using namespace std;
const int MAXN = 0x3f3f3f;
int fa[MAXN];
int d[MAXN];
int get(int x) {
	int t;
	if(x==fa[x]) return x;
	else t=get(fa[x]),d[x]+=d[fa[x]],fa[x]=t;
	return fa[x] ;
}
int main() {
	int N,M,Q;
	int a,b,s;
	int m,n;
	cin>>N>>M>>Q;
	for(int i=0; i<=N; i++)
		fa[i]=i,d[i]=0;
	for(int i=1; i<=M; i++) {
		cin>>a>>b>>s;
		int f1,f2;
		f1=get(a);
		f2=get(b);
		if(f1!=f2) {
			fa[f1]=f2;
			d[f1]=d[b]+s-d[a];
		}
	}
	while(Q--) {
		cin>>m>>n;
		if(get(m)!=get(n)) cout<<"-1"<<endl;
		else cout<<d[m]-d[n]<<endl;
	}
}
