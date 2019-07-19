#include<iostream>
using namespace std;
int p(int r[],int low,int high){
	long long i=low;
	long long j=high;
	while(i<j){
		while(i<j&&r[j]>r[i])
			j--;
		if(i<j) swap(r[i++],r[j]);
		while(i<j&&r[j]>=r[i])
			i++;
		if(i<j) swap(r[i],r[j--]);
	}
	return i;
}
void q(int r[],int low,int high){
	int mid;
	if(low<high){
		mid=p(r,low,high);
		q(r,low,mid-1);
		q(r,mid+1,high);
	}
}
int main(){
	int a[1000],n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	q(a,0,n-1);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
