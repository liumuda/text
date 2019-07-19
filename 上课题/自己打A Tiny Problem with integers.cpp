#include <bits/stdc++.h>
using namespace std;
const int MAXN = 0x3f3f3f;
int a[MAXN],c[MAXN],n,m;

int ask(int x){
	int ans=a[x];
	for(;x;x-=x&(-x)) ans+=c[x];
	return ans;
}
void add(int x,int d){
	for(;x<=n;x+=x&(-x)){
		c[x]+=d;
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	string cp;
	int l,r,d;
	for(int i=1;i<=m;i++){
		cin>>cp;
		if(cp[0]=='Q'){
			cin>>l;
			cout<<ask(l)<<endl;
		}else{
			cin>>l>>r>>d;
			add(l,d);
			add(r+1,-d);
		}
	}
	return 0; 
}
