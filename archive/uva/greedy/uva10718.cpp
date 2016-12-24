#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

bool isSet(int mask, int n){
	return ( (mask & (1<<n)) !=0);
}

int main(){
    unsigned int n,b,s;
    while (cin>>n>>s>>b){
    	unsigned res = 0;
    	for (int i=31; i>=0; i--){
    		if (!isSet(n, i)){
    			res|=(1<<i);
    			if (res>b) res^=(1<<i);
    		}
    		else {
    			res|=(1<<i);
    			if (res-1<s) continue;
    			res^=(1<<i);
    		}
    	}

    	cout<<res<<endl;
    }
}
