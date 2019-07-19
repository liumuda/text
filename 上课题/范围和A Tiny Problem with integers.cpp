#include <bits/stdc++.h>
using namespace std;
const int MAXN = 0x3f3f3f;
int a[MAXN],sum[MAXN],c[2][MAXN],n,m;

int ask(int k,int x){
	int ans=0;
	for(;x;x-=x&(-x)) ans+=c[k][x];
	return ans;
}
void add(int k,int x,int d){
	for(;x<=n;x+=x&(-x)){
		c[k][x]+=d;
	}
}

int main(){
	cin>>n>>m;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	string cp;
	int l,r,d;
	for(int i=1;i<=m;i++){
		cin>>cp>>l>>r;;
		if(cp[0]=='Q'){
			int ans=sum[r]+(r+1)*ask(0,r)-ask(1,r);
			ans-=sum[l-1]+l*ask(0,l-1)-ask(1,l-1);
			cout<<ans<<endl;
		}else{
			cin>>l>>r>>d;
			add(0,l,d);
			add(0,r+1,-d);
			add(1,l,d+l);
			add(1,r+1,-(r+1)*d); 
		}
	}
	return 0; 
}
