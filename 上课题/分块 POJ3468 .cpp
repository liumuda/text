#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100010],sum[100010],add[100010];
int L[100010],R[100010];  //ÿ�����Ҷ˵�
int pos[100010];  //ÿ��λ��������һ��
int n,m,t;

//�������е�l~r��������d 
void change(int l,int r,long long d) {
	int p = pos[l],q = pos[r];  //��¼Ҫ�ı�����������Ǹ���
	if(p==q) {                //�����ͬһ��
		for(int i=l; i<=r; i++) a[i]+=d; //�ÿ���l-r��a[i]��d
		sum[p]+=d*(r-l+1);      //�Ŀ�ĺ�  ����  d*(r-l+1)
	} else {
		for(int i = p+1; i<=q-1; i++) add[i]+=d; //(p+1)~(q-1)Ϊ�м�������飬���е���������d �ȼ�¼��add�� 
		for(int i = l; i<=R[p]; i++) a[i]+=d; //�����  ��l���������Ҷ�R[p]  a[i]��d
		sum[p] += d*(R[p]-l+1);    //�����ĺͼ���d*(R[p]-l+1)
		for(int i = L[q]; i<=r; i++) a[i] += d; //���ҿ�  �����ҿ�����L[q]��r a[i]��d
		sum[q] += d*(r-L[q]+1);    //���ҿ�ĺͼ���d*(r-L[q]+1)
	}
}

//ѯ�������е�l~r�����ĺ� 
ll ask(int l,int r) {
	int p = pos[l],q = pos[r];   //��¼Ҫ�ı�����������Ǹ���
	ll ans = 0;
	if(p == q) {      //�����ͬһ��
		for(int i=l; i<=r; i++) ans += a[i]; //ѭ����������a[i]��ֵ 
		ans += add[p] * (r-l+1);     // �ټ���add[p] �д洢������ 
	}
	else{
		for(int i = p+1;i<=q-1;i++)
			ans += sum[i]+add[i]*(R[i]-L[i]+1); //�ۼ��м�������ĺͣ�������add�д洢������ 
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
	
	//�ֿ�
	t=sqrt(n);  //��n�Ŀ����ֿ�
	for(int i=1;i<=t;i++){
		L[i] = (i-1)*sqrt(n)+1;   //���ÿ�����˺��Ҷ� 
		R[i] = i*sqrt(n);
	} 
	if(R[t]<n) t++,L[t] = R[t-1]+1,R[t] = n; //������ҿ���Ҷ�С��n ����һ�飬��������ӿ����˺��Ҷ� 
	
	//Ԥ���� 
	for(int i = 1; i <=t; i++)
		for(int j = L[i];j<=R[i];j++){
			pos[j] = i;   //���ÿһ������������±� 
			sum[i] += a[j];   //��¼ÿһ������ݺ� 
		}
		
	//ָ��   C l r d :��ʾ�������е�l~r��������d        Q l r �� ��ʾѯ�������е�l~r�����ĺ� 
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
