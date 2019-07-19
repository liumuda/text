#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;
ll qpow(ll a, ll n)//计算a^n % mod
{
    ll re = 1;
    while(n)
    {
        if(n & 1)//判断n的最后一位是否为1
            re = (re * a);
        n >>= 1;//舍去n的最后一位
        a = (a * a) ;//将a平方
    }
    return re ;
}
int main(){
	ll a,n;
	cin>>a>>n;
	cout<<qpow(a,n);
}
