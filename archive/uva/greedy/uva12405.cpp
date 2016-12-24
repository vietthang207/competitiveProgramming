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
        string a;
        cin>>a;
        cout<<"Case "<<t+1<<": ";
        if (n ==0 ) {
            cout<<0<<endl;
            continue;
        }
        if (n ==1) {
            if (a=="#"){
                cout<<0<<endl;
                continue;
            }
            else {
                cout<<1<<endl;
                continue;
            }
        }
        int res = 0;
        for (int i=0; i<n; i++){
            if (a[i]=='.') {
                res ++;
                i +=2;
            }
        }
        cout<<res<<endl;
    }
}
