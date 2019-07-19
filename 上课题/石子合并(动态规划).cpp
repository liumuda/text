//石子合并
#include <bits/stdc++.h>
using namespace std;
int sum[20005];
int f[20][20];
int a[20005];
int r; 
int INF = 0x3f; 
void dp(int n){
	memset(f,INF,sizeof(f));
	sum[0]=0;
	for(int i=1;i<=n;i++){
		f[i][i]=0;				//初始为0 
		sum[i]=sum[i-1]+a[i];   //前缀和 
	}
	for(int len=2;len<=n;len++)    //确定堆数 
		for(int l=1;l<=n-len+1;l++){   //确定左端点
			r=l+len-1;					//确定右端点 
			int temp = sum[r]-sum[l-1];  //确定左端点到右端点的总石子数 
			for(int k=l;k<r;k++){     
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+temp),cout<<l<<"-"<<r<<":"<<f[l][r]<<endl; //取l到r之间合并的最小值（） 
			}
		}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp(n);
	printf("min == %d",f[1][n]);
	return 0;
} 
