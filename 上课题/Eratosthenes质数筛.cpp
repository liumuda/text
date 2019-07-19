#include <bits/stdc++.h>
using namespace std;
int v[10010];
void Eratosthenes(int n){
	memset(v,0,sizeof(v));
	for(int i=2;i<=n;i++){
		if(v[i]) continue;
		cout<<i<<" ";
		for(int j=i;j<=n/i;j++) v[j*i] = 1;
	}
} 

int main(){
	int n;
	cin>>n;
	Eratosthenes(n);
}
