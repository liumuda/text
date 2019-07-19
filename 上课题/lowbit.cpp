#include <bits/stdc++.h>
using namespace std;
int main(){
	int x;
	cin>>x;
	while(x>0){
		printf("[%d,%d]\n",x-(x&-x)+1,x);
		x-=x&-x;
	}
} 
