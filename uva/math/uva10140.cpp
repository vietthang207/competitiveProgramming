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
bitset<1000010> rbs;

// first part

void sieve(ll size) {          // create list of primes in [0..upperbound]
  _sieve_size = size + 1;                   // add 1 to include upperbound
  bs.set();                                                 // set all bits to 1
  bs[0] = bs[1] = 0;                                     // except index 0 and 1
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    // cross out multiples of i starting from i * i!
  	for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
  	primes.push_back((int)i);
} }                                           // call this method in main method

bool isPrime(ll N) {                 // a good enough deterministic prime tester
  if (N <= _sieve_size) return bs[N];                   // O(1) for small primes
  for (int i = 0; i < (int)primes.size(); i++)
  	if (N % primes[i] == 0) return false;
  return true;                    // it takes longer time if N is a large prime!
}                      // note: only work for N <= (last prime in vi "primes")^2

ll n,m;
vector<ll> a;
int main(){
	sieve(50000);

	while (cin>>n){
		cin>>m;
		a.clear();
		rbs.set();

		for (int i:primes){
			ll cur = ll(i);
			// cout<<cur<<endl;
			if (cur>m) break;
			ll first;
			if (n%cur==0) first = n;
			else first = n+cur-n%cur;

			for (first; first<=m; first+=cur){
				if (first!=cur) {
					// cout<<"cross "<<first<<endl;
					rbs[first-n] = 0;
				}
			}
		}

		for (int i=0; i<m-n+1; i++){
			if (rbs[i] && n+i>1) {
				// cout<<n+i<<endl;
				a.push_back(n+i);
			}
		}

		if (a.size()<2) cout<<"There are no adjacent primes."<<endl;
		else {
			ll distMin = a[1] -a[0];
			ll distMax = a[1] -a[0];
			ll valMin = 0, valMax=0;
			for (ll i=1; i<a.size()-1; i++){
				ll tmp = a[i+1] -a[i];
				if (tmp<distMin){
					distMin = tmp;
					valMin = i;
				}
				if (tmp>distMax){
					distMax = tmp;
					valMax = i;
				}
			}
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", a[valMin], a[valMin+1], a[valMax], a[valMax+1]);
		}

	}
}
