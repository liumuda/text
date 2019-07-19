#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#define MAXN 5010
using namespace std;
int rank[2*MAXN], pre[2*MAXN];   //离散化 
int find(int x) { //***递归压缩路径
	if(x!=pre[x]) {			//不为根 
		int px=find(pre[x]);   //找到根 为px 
		rank[x]=rank[x]^rank[pre[x]];  //***更新rank[x]
		pre[x]=px;   //压缩路径 
	} 
	return pre[x];   //为根 
}

int jion(int x, int y, int d) {
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) {  //x y在同一个集合 
		if(rank[x]^rank[y]!=d) { //判断话是否为真 
			return 1;      //假 
		} else {			//真 
			return 0;
		}
	} else {     //不在同一集合 
		pre[fy]=fx;    //合并 
		rank[fy]=(rank[x]+rank[y]+d)%2;   //更新rank 
	}
	return 0;
}

int main(void) {
	map<int, int>mp;
	int n, m, gg=0, jj=1;
	mp.clear();
	scanf("%d%d", &n, &m);
	for(int i=0; i<=2*MAXN; i++) {
		pre[i]=i;
		rank[i]=0;
	}
	for(int i=1; i<=m; i++) {
		int x, y, d;
		char ch[10];
		scanf("%d%d%s", &x, &y, ch);
		if(!mp[x-1]) {
			mp[x-1]=jj++;
		}
		if(!mp[y]) {
			mp[y]=jj++;
		}
		if(strstr(ch, "even")) {
			d=0;
		} else {
			d=1;
		}
		if(jion(mp[x-1], mp[y], d)&&!gg) {
			gg=i;
		}
	}
	if(!gg) {    //全为真 
		gg=m+1;
	}
	printf("%d\n", gg-1);
	return 0;
}
