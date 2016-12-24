#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
        int n, l;
        cin>>l>>n;
        int a[n];
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        int m = (1<<n);
        bool res = false;
        for (int mask=0; mask<m; mask++){
            int sum = 0;
            for (int i=0; i<n; i++){
                if ( (mask & (1<<i)) !=0) {
                    sum +=a[i];
                }
            }
            if (sum == l) {
                res = true;
                break;
            }
        }
        if (res) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
