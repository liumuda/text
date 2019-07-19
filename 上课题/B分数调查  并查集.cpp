#include<cstdio>
using namespace std;
const int N=1e5+5;
int n,m,q,fa[N],dis[N];
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int find(int x) {
	int t;
	if(fa[x]!=x) t=find(fa[x]),dis[x]+=dis[fa[x]],fa[x]=t;
	return fa[x];
}
int main() {
	n=read();
	m=read();
	q=read();
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1,l,r,s,u,v; i<=m; i++) {
		r=read();
		l=read();
		s=read();
		u=find(l);
		v=find(r);
		if(u!=v) dis[u]=dis[r]+s-dis[l],fa[u]=v;
	}
	for(int i=1,x,y; i<=q; i++) {
		x=read();
		y=read();
		if(find(x)!=find(y)) puts("-1");
		else printf("%d\n",dis[y]-dis[x]);
	}
	return 0;
}
