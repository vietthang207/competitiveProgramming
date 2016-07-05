#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    int n=-1 ;
    int count=1;
    while (cin>>n){
        bitset<32> bs(n);
        bitset<32> clone;
        for (int i=0; i<8; i++){
            clone[i] = bs[24+i];
            clone[i+8] = bs[16+i];
            clone[i+16] = bs[8+i];
            clone[i+24] = bs[i];
        }

        printf("%d converts to %d\n", n, clone);

    }
}
