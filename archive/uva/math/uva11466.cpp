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
bitset<40000010> bs;   
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

int main(){
	ll n;
	sieve(10000010);
	while (cin>>n){
		if (n==0) break;
		if (n==1 || n==-1) {
			cout<<-1<<endl;
			continue;
		}
		if (n<0) n = -1*n;
		ll last = n;
		ll coun = 0;
		for (int i: primes){
			bool flag = false;
			while (n%i==0) {
				n/=i;
				if (!flag){
					last = i;
					flag = true;
					coun++;
				}
			}
			if (n==1) break;
		}
		if (n!=1) coun++;
		if (coun == 1) cout<<-1<<endl;
		else if (n==1) cout<<last<<endl;
		else cout<<n<<endl;
	}
}
