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

ll sumDiv(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;             // start from ans = 1
  while (N != 1 && (PF * PF <= N)) {
    ll power = 0;
    while (N % PF == 0) { N /= PF; power++; }
    ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);         // formula
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);        // last one
  return ans;
}

int res[1001];
int main(){
	sieve(1001);
	memset(res, -1, sizeof(res));
	for (int i=1; i<100001; i++){
		int tmp = sumDiv(i);
		if (tmp<1001) res[tmp] = i;
		// cout<<tmp<<" "<<i<<endl;
	}
	// cout<<sumPF(101)<<endl;
	res[1] = 1;
    int n;
    int coun=1;
    while (cin>>n){
    	if (n==0) break;
    	cout<<"Case "<<coun<<": ";
    	cout<<res[n]<<endl;

        coun ++;
    }
}
