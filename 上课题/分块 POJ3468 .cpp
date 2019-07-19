#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100010],sum[100010],add[100010];
int L[100010],R[100010];  //每段左右端点
int pos[100010];  //每个位置属于那一段
int n,m,t;

//再数列中第l~r个数都加d 
void change(int l,int r,long long d) {
	int p = pos[l],q = pos[r];  //记录要改变的区域属于那个块
	if(p==q) {                //如果在同一块
		for(int i=l; i<=r; i++) a[i]+=d; //该块内l-r的a[i]加d
		sum[p]+=d*(r-l+1);      //改块的和  加上  d*(r-l+1)
	} else {
		for(int i = p+1; i<=q-1; i++) add[i]+=d; //(p+1)~(q-1)为中间的完整块，其中的所有数加d 先记录在add中 
		for(int i = l; i<=R[p]; i++) a[i]+=d; //最左块  从l到最左块的右端R[p]  a[i]加d
		sum[p] += d*(R[p]-l+1);    //最左块的和加上d*(R[p]-l+1)
		for(int i = L[q]; i<=r; i++) a[i] += d; //最右块  从最右块的左端L[q]到r a[i]加d
		sum[q] += d*(r-L[q]+1);    //最右块的和加上d*(r-L[q]+1)
	}
}

//询问数列中第l~r个数的和 
ll ask(int l,int r) {
	int p = pos[l],q = pos[r];   //记录要改变的区域属于那个块
	ll ans = 0;
	if(p == q) {      //如果在同一块
		for(int i=l; i<=r; i++) ans += a[i]; //循环加上所有a[i]的值 
		ans += add[p] * (r-l+1);     // 再加上add[p] 中存储的数据 
	}
	else{
		for(int i = p+1;i<=q-1;i++)
			ans += sum[i]+add[i]*(R[i]-L[i]+1); //累加中间完整块的和，并加上add中存储的数据 
		for(int i=l;i<=R[p];i++) ans+=a[i];
		ans += add[p]*(R[p]-l+1);
		for(int i = L[q];i<=r;i++) ans += a[i];
		ans += add[q]*(r-L[p]+1); 
	}
	return ans; 
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	//分块
	t=sqrt(n);  //以n的开方分块
	for(int i=1;i<=t;i++){
		L[i] = (i-1)*sqrt(n)+1;   //标记每块的左端和右端 
		R[i] = i*sqrt(n);
	} 
	if(R[t]<n) t++,L[t] = R[t-1]+1,R[t] = n; //如果最右块的右端小于n 增加一块，并标记增加块的左端和右端 
	
	//预处理 
	for(int i = 1; i <=t; i++)
		for(int j = L[i];j<=R[i];j++){
			pos[j] = i;   //标记每一块包含的数据下标 
			sum[i] += a[j];   //记录每一块的数据和 
		}
		
	//指令   C l r d :表示把数列中第l~r个数都加d        Q l r ： 表示询问数列中第l~r个数的和 
	while(m--){
		char op[3];
		int l,r,d;
		scanf("%s%d%d",op,&l,&r);
		if(op[0]=='C'){
			scanf("%d",&d);
			change(l,r,d);
		}
		else printf("%lld\n",ask(l,r));
	} 
} 
