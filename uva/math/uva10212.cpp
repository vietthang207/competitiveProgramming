#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef map<int, int> mii;

const double EP=1e-6;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;

int main(){
    int n, m;
    while (cin>>n>>m){
    	ll res = 1;
    	for (int i=n; i>=n-m+1; i--){
    		// cout<<res<<endl;
    		ll tmp = i;
    		res = (res*(tmp));
    		while (res%10==0) res/=10;
    		res = res%1000000000;
    	}
    	res%=10;
    	cout<<res<<endl;
    }
}
