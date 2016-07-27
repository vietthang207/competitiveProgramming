#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;

int n;
string s;
ll memo[210][15];

ll dp(int pos, int digit){
	if (pos == -1) return 0;
	if (memo[pos][digit]!=-1) return memo[pos][digit];
	ll cur = atoll(s.substr(pos, digit+1).c_str());
	ll res1 = s[pos]-'0' + dp(pos-1, 1);
	ll res2 = -1;
	if (cur<=MAX31 && digit<11){
		res2 = (s[pos]-'0')*pow(10,digit) + dp(pos-1, digit+1);
	}
	return memo[pos][digit] = max(res1, res2);
}

int main(){
	int T; cin>>T;
	for (int t=0; t<T; t++){
		cin>>s;
		n = s.size();
		memset(memo, -1, sizeof(memo));
		cout<<dp(n-1, 0)<<endl;
	}
}
