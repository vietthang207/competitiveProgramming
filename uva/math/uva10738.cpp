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

ll numDiffPF(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    if (N % PF == 0) ans++;                           // count this pf only once
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
}
if (N != 1) ans++;
return ans;
}

int memo[1000100];

int mu(ll n){
	if (n==1) return 1;
	if (memo[n]!=2) return memo[n];
	vi pf = primeFactors(n);
	int cur = pf[0];
	for (int i=1; i<pf.size(); i++){
		if (pf[i]==cur) return memo[n] = 0;
		cur = pf[i];
	}
	if (numDiffPF(n)%2==0) return memo[n] = 1;
	return memo[n] = -1;
}

int main(){
	int n;
	for (int i=0; i<1000100; i++)
		memo[i] = 2;
	sieve(1100);
	while (cin>>n){
		if (n==0) break;
		int res=0;
		for (int i=1; i<n; i++) res+=mu(i);
		printf("%8d%8d%8d\n", n, mu(n), res+mu(n));
	}
}
