#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;
ll qpow(ll a, ll n)//����a^n % mod
{
    ll re = 1;
    while(n)
    {
        if(n & 1)//�ж�n�����һλ�Ƿ�Ϊ1
            re = (re * a);
        n >>= 1;//��ȥn�����һλ
        a = (a * a) ;//��aƽ��
    }
    return re ;
}
int main(){
	ll a,n;
	cin>>a>>n;
	cout<<qpow(a,n);
}
