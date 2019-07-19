#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define SIZE 100005
#define INF 0x3ffff
int fa[SIZE*2];
int t,n;
long tem[SIZE*2];		//离散化数组
long tems[SIZE*2];
int tot;
int m;

int nextt[SIZE*2];
int head[SIZE*2];

long eq[SIZE][2];
long uneq[SIZE][2];
int eqs,uneqs;



int getnum(long x) {
	long a=x%13331;
	int j;
	for ( j = head[a]; j ; j=nextt[j]) {
		if(tems[j]==x) return j;
	}
	return 0;
}

void init() {
	memset(head,0,sizeof(head));
	memset(nextt,0,sizeof(nextt));
	m=0;
	tot=0;
	eqs=0;
	uneqs=0;
}

int get(int x) {
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);		//	路径压缩，尽量接近跟节点
}

void merge(int i,int j) {
	fa[get(i)]=get(j);
}

int main(int argc, char const *argv[]) {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		init();
		for (int i = 1; i <= n; ++i) {
			long a,b,e;
			scanf("%ld %ld %ld",&a,&b,&e);
			tem[++tot] = a;
			tem[++tot] = b;
			if(e==1) eq[++eqs][0] = a, eq[eqs][1] = b;
			else uneq[++uneqs][0] = a, uneq[uneqs][1] = b;
		}

		sort(tem+1,tem+1+tot);
		for (int i = 1; i <= tot ; ++i) {	//	进行离散化
			if(i==1||tem[i]!=tem[i-1]) {
				tems[++m]=tem[i];
				long ts = tems[m]%13331;
				nextt[m] = head[ts];
				head[ts] = m;
			}
		}
		for (int i = 1; i <=m ; ++i) {
			fa[i]=i;    //	并查集初始化
		}

		for (int i = 1; i <= eqs ; ++i)
			merge(getnum(eq[i][0]),getnum(eq[i][1]));
		int flag = 0;
		for (int i = 1; i <= uneqs ; ++i) {
			if(get(getnum(uneq[i][0]))==get(getnum(uneq[i][1]))) {
				printf("NO\n") ;
				flag = 1;
				break;
			}
		}
		if(flag==0)
			printf("YES\n");
	}
	return 0;
}

