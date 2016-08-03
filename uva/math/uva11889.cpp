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

int a, c;

int main(){
	sieve(10000);
	int T; cin>>T;
	for (int t=0; t<T; t++){
		cin>>a>>c;
		if (c%a!=0) {
			cout<<"NO SOLUTION"<<endl;
			continue;
		}
		vi pfa = primeFactors(a);
		mii couna;
		for (int i: pfa){
			if (couna.find(i)==couna.end()){
				couna[i] = 1;
			}
			else couna[i]++;
		}
		vi pfc = primeFactors(c);
		mii counc;
		for(int i: pfc){
			if (counc.find(i)==counc.end()){
				counc[i] = 1;
			}
			else counc[i]++;
		}
		int res = 1;
		for (auto& kv : counc){
			int k = kv.first;
			int v = kv.second;
			if (couna.find(k) == couna.end()){
				res*=pow(k, v);
			}
			else if (v>couna[k]){
				res*=pow(k,v);
			}
		}	
		cout<<res<<endl;
	}
}





