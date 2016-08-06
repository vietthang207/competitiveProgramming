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

vi a;

int gcd(int a, int b){
	return (b==0) ? a: gcd(b, a%b);
}

int main(){
    int n;
    int T; cin>>T;
    string tmp;
    getline(cin, tmp);
    for (int t=0; t<T; t++){
    	a.clear();
    	getline(cin, tmp);
    	istringstream iss(tmp);
    	int x;
    	while (iss>>x){
    		a.push_back(x);
    	}
    	int res = 0;
    	for (int i=0; i<a.size(); i++){
    		for (int j=i+1; j<a.size(); j++){
    			res = max(res, gcd(a[i], a[j]));
    		}
    	}
    	cout<<res<<endl;
    }
}
