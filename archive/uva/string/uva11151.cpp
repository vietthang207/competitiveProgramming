#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int n;
string s1, s2;
int memo[1100][1100];

int dp(int i, int j){
	if (memo[i][j]!=-1) return memo[i][j];
	if (i==n || j==n) return 0;
	int res;
	if (s1[i] == s2[j]) res = 1+ dp(i+1, j+1);
	else {
		res = max(dp(i+1,j), dp(i, j+1));
	}
	return memo[i][j] = res;
}

int main(){
	int T; cin>>T;
	getline(cin, s1);
	for (int t=0; t<T; t++){
		memset(memo, -1, sizeof(memo));
		getline(cin,s1);
		n = s1.size();
		s2 = s1;
		for (int i=0; i<n; i++){
			s2[n-1-i] = s1[i];
		}
		cout<<dp(0,0)<<endl;
	}
}
