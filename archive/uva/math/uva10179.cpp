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

ll EulerPhi(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = N;             // start from ans = N
  while (N != 1 && (PF * PF <= N)) {
    if (N % PF == 0) ans -= ans / PF;                // only count unique factor
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
  }
  if (N != 1) ans -= ans / N;                                     // last factor
  return ans;
}

int main(){
    int n;
    sieve(40000);
    while (cin>>n){
    	if (n==0) break;
    	cout<<EulerPhi(n)<<endl;
    }
}
