#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#define MAXN 5010
using namespace std;
int rank[2*MAXN], pre[2*MAXN];   //��ɢ�� 
int find(int x) { //***�ݹ�ѹ��·��
	if(x!=pre[x]) {			//��Ϊ�� 
		int px=find(pre[x]);   //�ҵ��� Ϊpx 
		rank[x]=rank[x]^rank[pre[x]];  //***����rank[x]
		pre[x]=px;   //ѹ��·�� 
	} 
	return pre[x];   //Ϊ�� 
}

int jion(int x, int y, int d) {
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) {  //x y��ͬһ������ 
		if(rank[x]^rank[y]!=d) { //�жϻ��Ƿ�Ϊ�� 
			return 1;      //�� 
		} else {			//�� 
			return 0;
		}
	} else {     //����ͬһ���� 
		pre[fy]=fx;    //�ϲ� 
		rank[fy]=(rank[x]+rank[y]+d)%2;   //����rank 
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
	if(!gg) {    //ȫΪ�� 
		gg=m+1;
	}
	printf("%d\n", gg-1);
	return 0;
}
