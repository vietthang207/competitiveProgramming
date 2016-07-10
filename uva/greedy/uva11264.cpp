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
        int n;
        cin>>n;
        int a[n];
        for (int i=0; i<n; i++) cin>>a[i];
        int res = 1;
        int sum = a[n]+;
        int curr = a[n];
        int prev = a[n-1];
        for (int i=n-2; i>=0; i--){
            if (a[i]+sum){
                res++;
                sum+=a[i];
            }
        }
        cout<<res<<endl;
    }
}
