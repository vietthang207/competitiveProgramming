#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    int n=-1 ;
    int count=1;
    cin>>n;
    for (int i=0; i<n; i++){
        int k;
        cin>>k;
        int x1, x2;
        for (int i=2; i<k; i++){
            if (k%i==0){
                x1=i;
                break;
            }
        }
        for (int i=x1+1; i<k; i++){
            if (k%i==0){
                x2=i;
                break;
            }
        }
        printf("Case #%d: %d = %d * %d = %d * %d\n", i+1, k, x1, k/x1, x2, k/x2);
    }
}
