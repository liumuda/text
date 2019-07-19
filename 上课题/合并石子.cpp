#include <iostream>
#include <string>
using namespace std;
const int INF = 1 << 30;
const int N = 205;
int Min[N][N],Max[N][N];
int sum[N];
int a[N];
void straight (int a[],int n){
	for(int i=1;i<=n;i++) //初始化 
	Min[i][i]=0,Max[i][i]=0;
	sum[0]=0;
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i]; 
	for(int v=2;v<=n;v++)    //枚举合并的堆数规模 
	{
		for(int i=1;i<=n-v+1;i++)  //枚举起点i 
		{
			int j=i+v-1;         //枚举终点j 
			Min[i][j]=INF;        //初始化为最大值 
			Max[i][j]=-1;          //初始化为-1 
			int tmp=sum[j]-sum[i-1]; //记录i....j之间的石子数之和 
			for(int k=i;k<j;k++){  //枚举中间分隔点 
				Min[i][j]=min(Min[i][j],Min[i][k]+Min[k+1][j]+tmp);
				Max[i][j]=max(Max[i][j],Max[i][k]+Max[k+1][j]+tmp);
		    }
		}
	} 
} 
int main()
{
	int n;
	cout<<"请输入石子的堆数n:";
	cin>>n;
	cout<<"请输入各堆的石子数："; 
	for(int i=1;i<=n;i++) 
	cin>>a[i];
	straight(a,n);
	cout<<"最小花费为："<<Min[1][n]<<endl;
	cout<<"最大花费为："<<Max[1][n]<<endl;
	return 0;
}
