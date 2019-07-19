#include <bits/stdc++.h>
using namespace std;
int c[10010],N,ans,a[10010];
int ask(int x){
	ans=0;
	for(;x;x-=x&-x) cout<<x<<endl,ans+=c[x];
	return ans;
}
void add(int x,int y){
	for(;x<=N;x+=x&-x) c[x]+=y;
}
int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	for(int i = N;i;i--){
		ans += ask(a[i]-1);
		add(a[i],1);
	}
}
