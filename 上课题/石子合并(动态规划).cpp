//ʯ�Ӻϲ�
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
		f[i][i]=0;				//��ʼΪ0 
		sum[i]=sum[i-1]+a[i];   //ǰ׺�� 
	}
	for(int len=2;len<=n;len++)    //ȷ������ 
		for(int l=1;l<=n-len+1;l++){   //ȷ����˵�
			r=l+len-1;					//ȷ���Ҷ˵� 
			int temp = sum[r]-sum[l-1];  //ȷ����˵㵽�Ҷ˵����ʯ���� 
			for(int k=l;k<r;k++){     
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+temp),cout<<l<<"-"<<r<<":"<<f[l][r]<<endl; //ȡl��r֮��ϲ�����Сֵ���� 
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
