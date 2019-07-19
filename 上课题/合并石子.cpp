#include <iostream>
#include <string>
using namespace std;
const int INF = 1 << 30;
const int N = 205;
int Min[N][N],Max[N][N];
int sum[N];
int a[N];
void straight (int a[],int n){
	for(int i=1;i<=n;i++) //��ʼ�� 
	Min[i][i]=0,Max[i][i]=0;
	sum[0]=0;
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i]; 
	for(int v=2;v<=n;v++)    //ö�ٺϲ��Ķ�����ģ 
	{
		for(int i=1;i<=n-v+1;i++)  //ö�����i 
		{
			int j=i+v-1;         //ö���յ�j 
			Min[i][j]=INF;        //��ʼ��Ϊ���ֵ 
			Max[i][j]=-1;          //��ʼ��Ϊ-1 
			int tmp=sum[j]-sum[i-1]; //��¼i....j֮���ʯ����֮�� 
			for(int k=i;k<j;k++){  //ö���м�ָ��� 
				Min[i][j]=min(Min[i][j],Min[i][k]+Min[k+1][j]+tmp);
				Max[i][j]=max(Max[i][j],Max[i][k]+Max[k+1][j]+tmp);
		    }
		}
	} 
} 
int main()
{
	int n;
	cout<<"������ʯ�ӵĶ���n:";
	cin>>n;
	cout<<"��������ѵ�ʯ������"; 
	for(int i=1;i<=n;i++) 
	cin>>a[i];
	straight(a,n);
	cout<<"��С����Ϊ��"<<Min[1][n]<<endl;
	cout<<"��󻨷�Ϊ��"<<Max[1][n]<<endl;
	return 0;
}
