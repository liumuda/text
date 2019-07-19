#include <iostream>
using namespace std;
const int INF=0x3fffffff;
const int N=100;
bool s[N];
int closest[N];
int lowcost[N];
void prim(int n,int u0,int c[N][N]){
	//�������n,��ʼ����u0,��Ȩ�ڽӾ���c[N][N]
	/*���s[i]=true,˵������i�Ѽ�����С�������Ķ��㼯��U;
	���򶥵�i�Ѽ�����С������*/ 
	 //��������ص���СȨֵ���ݵ�����lowcost
	 s[u0]=true;    //��ʼʱ,������Uֻ��һ��Ԫ��,������u0
	 int i;
	 int j;
	 for(i=1;i<=n;i++){  // �� 
	 	if(i!=u0){
	 		lowcost[i]=c[u0][i];
	 		closest[i]=u0;
	 		s[i]=false;
		 }
		 else lowcost[i]=0;
	 }
	 for(i=1;i<=n;i++){  // �� 
	 	int temp=INF;
	 	int t=u0;
	 	for(j=1;j<=n;j++){   //�ڼ�����V-U��Ѱ�Ҿ���U����Ķ���t 
	 		if((!s[j])&&(lowcost[j]<temp)){
	 			t=j;
	 			temp=lowcost[j];
			 }
		 }
		if(t==u0) break; //�Ҳ���t������ѭ�� 
		s[t]=true;       //���򣬽�t���뼯��U
		for(j=1;j<=n;j++){     //����lowcost��closest 
			if((!s[j])&&(c[t][j]<lowcost[j])){
				lowcost[j]=c[t][j];
				closest[j]=t;
			} 
		} 	
	 } 
} 
int main(){
	int n,c[N][N],m,u,v,w;
	int u0;
	cin>>n>>m; //��������n�ͱ���m 
	int sumcost=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c[i][j]=INF;
	for(int i=1;i<=m;i++){   //��������u,v�ͱ�ֵw 
		cin>>u>>v>>w;
		c[u][v]=c[v][u]=w;
	} 
	cin>>u0;  //������һ���u0
	//��������lowcos���ܺ�,��Ϊ���Ҫ�����С�ķ���֮��
	prim(n,u0,c);
	for(int i=1;i<=n;i++)
		cout<<lowcost[i]<<" ";  //�������lowcost������ 
	cout<<endl;
	for(int i=1;i<=n;i++)
		sumcost+=lowcost[i];
	cout<<"��С�Ļ�����:"<<sumcost<<endl<<endl;
	return 0; 
}





