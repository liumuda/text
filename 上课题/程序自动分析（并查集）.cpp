#include <bits/stdc++.h>
using namespace std;
int fa[200005]; 
int get(int x){
	if(x==fa[x]) return x;
	return fa[x] = get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)] = get(y);
}
int main(){
	int t,n,i,j,e;
	cin>>t;
	while(t--){
		cin>>n;
		while(n--){
			cin>>i>>j>>e;
			fa[i]=i,fa[j]=j;
			if(e){
				merge(i,j);
			}
		}
		if(fa[i]==fa[j]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 
