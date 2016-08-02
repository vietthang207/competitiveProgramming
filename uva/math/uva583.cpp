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
ll _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;   // compact list of primes in form of vector<int>

void sieve(ll size){
	_sieve_size = size+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i=2; i<_sieve_size+1; i++){
		if (bs[i]) {
			for (int j = i+i; j<_sieve_size+1; j+=i){
				bs[j] = 0;
			}
			primes.push_back(i);
		}
	}
}

vi fac(ll n){
	vi res;
	for (int i: primes){
		while (n!=1 && i*i<=n && n%i==0) {
			n/=i;
			res.push_back(i);
			// cout<<i<<endl;
		}
		if (n==1) break;
	}
	if (n!=1) res.push_back(n);
	return res;
}

int main(){
    int n;
    sieve(55000);
    while (cin>>n){
    	if (n==0) break;
    	cout<<n<<" = ";

    	if (n<0) {
    		n = -1*n;
    		cout<<"-1 x ";
    	}
    	vi v = fac(n);
    	cout<<v[0];
    	for (int i=1; i<v.size(); i++){
    		cout<<" x "<<v[i];
    	}
    	cout<<endl;
    }
}
