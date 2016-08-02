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
bitset<10000010> bs;   
vi primes;  

void sieve(ll upperbound) {         
	_sieve_size = upperbound + 1;                
	bs.set();                                                 
	bs[0] = bs[1] = 0;                                   
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
			primes.push_back((int)i);  
	} 
}         

vi primeFactors(ll n){
	vi res;
	for (int i: primes){
		while (n!=1 && i*i<=n && n%i==0) {
			n/=i;
			res.push_back(i);
		}
		if (n==1) break;
	}
	if (n!=1) res.push_back(n);
	return res;
}

int memo[1000100];

int main(){
	int n;
	sieve(1000010);
	n = 1000000;
	memo[1] = 1;
	ll res=1;
	mii coun;
	for (int i=2; i<=n; i++){
		vi pf = primeFactors(i);
		int cur = pf[0];
		int cc = 1;
		for (int j=1; j<pf.size(); j++){
			if (pf[j]!=cur){
				if (coun.find(cur) == coun.end()){
					coun[cur] = cc;
					res*=pow(cur, cc);
					while (res%10==0) res/=10;
					res%=10;
						// cout<<cur<<" "<<cc<<endl;
				}
				else {
					if (coun[cur]<cc) {
						res*=pow(cur, cc-coun[cur]);
						while (res%10==0) res/=10;
						res%=10;
						coun[cur] = max(coun[cur], cc);
							// cout<<cur<<" "<<cc-coun[cur]<<endl;
					}
				}
				cur = pf[j];
				cc = 1;
			}
			else {
				cc++;
			}
		}
		if (coun.find(cur) == coun.end()){
			res*=pow(cur, cc);
			while (res%10==0) res/=10;
			res%=10;
			coun[cur] = cc;
				// cout<<cur<<" "<<cc<<endl;
		}
		else {
			if (coun[cur]<cc) {
				res*=pow(cur, cc-coun[cur]);
				while (res%10==0) res/=10;
				res%=10;
				coun[cur] = max(coun[cur], cc);
					// cout<<coun[cur]<<" "<<cur<<" "<<cc-coun[cur]<<endl;
			}
		}
		while (res%10==0) res/=10;
		res%=10;
		memo[i] = res;
		// cout<<i<<" "<<res<<endl;
	}
	while (cin>>n){
		if (n==0) break;
		cout<<memo[n]<<endl;
	}
}
