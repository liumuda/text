#include <iostream>
using namespace std;
const int maxn = 4;
int n, P[maxn], hashTable[maxn] = {false};
void generateP(int index) {
    if (index == n+1) {
        for (int i = 1; i <= n; i++) {
            cout<<P[i];
        }
        cout<<endl;
    }
    for (int x = 1; x <= n; x++) {
        if (hashTable[x] == false) {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
        }
    }
}

int main() {
    cin>>n;
    generateP(1);
    return 0;
}
