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

string s;
ll f[21];
ll fac(ll i) {
	if (i==0) return 1;
	return f[i] = i*fac(i-1);
}
char a[21];
int n;
int main(){
	int T; cin>>T;
	f[0] = 1;
	fac(20);
	for (int t=0; t<T; t++) {
		cin>>s;
		n = s.size();
		ll res = f[n];
		for (int i=0; i<n; i++)
			a[i] = s[i];
		sort(a, a+n);
		char cur = a[0];
		ll coun = 1;
		for (int i=1; i<n; i++){
			// cout<<a[i]<<endl;
			if (a[i]!=cur) {
				res/=f[coun];
				coun = 1;
				cur = a[i];
			}
			else {
				coun++;
			}
		}
		res/=f[coun];
		printf("Data set %d: %lld\n", t+1, res);
	}
}
