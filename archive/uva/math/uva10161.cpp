#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    ll n;
    int coun=1;
    cin>>n;
    while (n!=0){

        ll root = sqrt(n);
        ll diff = n-root*root;
        ll x, y;

        if (diff == 0) {
            x=root;
            y = 1;
        }
        else if (diff<=root){
            x = root+1;
            y = diff;
        }
        else {
            x = 2*root+2- diff;
            y = root+1;
        }

        if (root%2==0){
            cout<<x<<" "<<y<<endl;
        }
        else {
            cout<<y<<" "<<x<<endl;
        }

        coun ++;
        cin>>n;
    }
}
