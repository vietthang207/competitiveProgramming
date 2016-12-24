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
int n, m;
int main(){
	sieve(50000);
    while (cin>>n>>m){
    	int n1=n, m1=m;
    	vi facs = primeFactors(m);
    	mii mapi;
    	bool flag = true;
    	for (int i:facs){
    		for (int j=i; j<=n; j+=i){
    			if (mapi.find(j)!=mapi.end()){
    				int cur = mapi[j];
    				if (cur%i==0){
    					mapi[j]/=i;
    					m/=i;
    					break;
    				}
    			}
    			else {
    				mapi[j] = j/i;
    				m/=i;
    				break;
    			}
    		}
    	}
    	if (m==1) printf("%d divides %d!\n", m1, n1);
    	else printf("%d does not divide %d!\n", m1, n1);
    }
}
