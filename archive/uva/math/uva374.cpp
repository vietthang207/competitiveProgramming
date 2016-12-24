#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

ll a, n, m;

ll cal(ll n){
    if (n==0) return 1;
    if (n==1) return a%m;
    if (n%2==0) {
        ll tmp = cal(n/2);
        return (tmp*tmp)%m;
    }
    return (cal(n/2)*cal(n-n/2))%m;
}

int main(){

    int coun=1;
    while (cin>>a){
        cin>>n>>m;
        cout<<cal(n)<<endl;
        coun ++;
    }
}
