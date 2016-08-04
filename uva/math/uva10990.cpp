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
const int size = 2000001;

int sieve[size];

void buildSieve(){
	for (int i=0; i<size; i++) sieve[i] = i;

	for (int i=2; i<size; i++){
		if (sieve[i]!=i) continue;
		for (int j=i; j<=size; j+=i){
			sieve[j] = (sieve[j]/i)*(i-1);
		}
	}
}

int memo[size];
ll sum[size];

int eulerPhi(int n){
	return sieve[n];
}

int dephi(int n){
	if (n==1) return 0;
	if (memo[n]!=-1) return memo[n];
	return memo[n] = 1+dephi(eulerPhi(n));
}

int main(){
    buildSieve();
    memset(memo, -1, sizeof memo);
    for(int i=2; i<size; i++) dephi(i);
    sum[0] = memo[0];
    for (int i=1; i<size; i++){
    	sum[i] = memo[i]+sum[i-1];
    }
    // for (int i=0; i<14; i++)
    	// cout<<memo[i]<<" "<<eulerPhi(i)<<endl;
    int T; cin>>T;
    for (int t=0; t<T; t++){
    	int a, b;
    	cin>>a>>b;
    	cout<<sum[b]-sum[a-1]<<endl;
    }
}
