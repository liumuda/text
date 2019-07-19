#include <cstdio>
#include <cstring>
#include <iostream>
#define N 200001
using namespace std;

int n,lh[N],ll[N],rh[N],rl[N],a[N],c[N];
long long ansup,ansdown;

int ask(int x) { //ѯ��
	int sum=0;
	for (; x; x-=x&(-x)) sum+=c[x];
	return sum;
}

void add(int x) { //�޸�
	for (; x<=n; x+=x&(-x)) c[x]++;
}

int main() {
	scanf("%d",&n);
	for (int i=1; i<=n; i++) { //��������ҵ�ÿ����
		scanf("%d",&a[i]);
		lh[i]=ask(a[i]-1);
		ll[i]=i-1-lh[i];
		add(a[i]);
	}
	memset(c,0,sizeof(c));
	for (int i=n; i>=1; i--) { //����������ÿ����
		rh[i]=ask(a[i]-1);
		rl[i]=n-i-rh[i];
		add(a[i]);
	}
	for (int i=2; i<n; i++) {
		ansup+=(long long)lh[i]*rh[i];
		ansdown+=(long long)ll[i]*rl[i];
	}
	cout<<ansdown<<" "<<ansup<<endl;
	return 0;
}
