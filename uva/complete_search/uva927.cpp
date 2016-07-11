#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

vi poly;
int d,k;

ll f(int x){
    ll cur = 1;
    ll res = 0;
    for (int i=0; i<poly.size(); i++){
        res+=poly[i]*cur;
        cur*=x;
    }
    return res;
}

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
        poly.clear();
        int degree;
        cin>>degree;
        for (int i=0; i<degree+1; i++){
            int tmp;
            cin>>tmp;
            poly.push_back(tmp);
        }
        //cout<<poly.size()<<endl;
        cin>>d>>k;

        double delta = 1.0+8.0*k/d;
        //cout<<delta<<endl;
        //cout<< (-1.0+sqrt(delta))/2.0<<endl;
        int root = (-1.0+sqrt(delta))/2.0;
        int diff = k - d*root*(root+1)/2;
        //cout<<root<<" "<<diff<<endl;
        if (diff ==0) cout<<f(root)<<endl;
        else cout<<f(root+1)<<endl;
    }
}
