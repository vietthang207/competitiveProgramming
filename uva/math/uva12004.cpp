#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    int n=-1 ;
    int coun=1;
    cin>>n;
    for (int i=0; i<n; i++){
        ll x;
        cin>>x;
        printf("Case %d: ", i+1);
        ll denom = x*(x-1);
        if (denom%4==0) cout<<denom/4<<endl;
        else if (denom%2 == 0 ) cout<<denom/2<<"/"<<2<<endl;
        else cout<<denom<<"/"<<4<<endl;
    }
}
