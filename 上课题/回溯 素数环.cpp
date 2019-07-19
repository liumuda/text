#include<bits/stdc++.h>
using namespace std;
//pd(int x,int y)
//print()
//search(int t)
bool b[101]= {0};
int total,ii,a[101]= {0};
bool Pd(int x,int y) {
	int e=x+y;
	for(int i=2; i<=sqrt(e); i++) {
		if(e%i==0) return 0;
	}
	return 1;
}

int print() {
	total++;
	printf("<%d> ",total);
	for(int j=1; j<=ii; j++) {
		printf("%d ",a[j]);
	}
	printf("\n");
}

int search(int t) {
	for(int i=1; i<=ii; i++) {
		if(!b[i]) {
			if(Pd(a[t-1],i)) {
				a[t]=i;
				b[i]=1;
				if(t==ii) {
					if(Pd(a[ii],a[1])) print();
				} else
					search(t+1);
				b[i]=0;
			}
		}
	}
}

int main() {
	freopen("sushuhuan.txt","w",stdout);
	cin>>ii;
	search(1);
	fclose(stdout);
	return 0;
}
