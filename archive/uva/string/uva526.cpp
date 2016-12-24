#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;
const int LEFT = 1;
const int UP = 2;
const int DIA = 0;

string s1, s2;
int n,m;
int dp[90][90];

int main(){
	bool first = true;
	while (cin>>s1){
		if (first) first = false;
		else cout<<endl;
		int coun = 1;
		cin>>s2;
		n = s1.size()+1;
		m = s2.size()+1;

		for (int i=0 ;i<n; i++) {
			dp[0][i] = i;
		}
		for (int i=0; i<m; i++) {
			dp[i][0] = i;
		}
		for (int j=1; j<m; j++){
			for (int i=1; i<n; i++){
				int r1,r2,r3;
				if (s1[i-1]==s2[j-1]){
					r1 = dp[j-1][i-1];
				}
				else r1 = dp[j-1][i-1]+1;
				r2 = dp[j-1][i] +1;
				r3 = dp[j][i-1] +1;
				dp[j][i] = min(r1, min(r2,r3));
				// cout<<j<<" "<<i<<" "<<dp[j][i]<<endl;
			}
		}
		cout<<dp[m-1][n-1]<<endl;
		int x = n-1, y = m-1;
		while (x!=0 || y!=0){
			int r1 = 100, r2 = 100, r3 = 100;
			if (x>0 && y>0 && s1[x-1] == s2[y-1]) r1 = dp[y-1][x-1];
			if (x>0 && y>0 && s1[x-1] != s2[y-1]) r1 = dp[y-1][x-1]+1;
			if (x>0) r2 = dp[y][x-1]+1;
			if (y>0) r3 = dp[y-1][x]+1;
			if (r1<=r2 && r1<=r3) {
				if (s1[x-1]!=s2[y-1]) {
					printf("%d Replace %d,%c\n", coun++, x, s2[y-1]);
				}
				x--; y--;
			}
			else if (r2<=r3){
				printf("%d Delete %d\n", coun++, x);
				x--;
			}
			else {
				printf("%d Insert %d,%c\n", coun++, y, s2[y-1]);
				y--;
			}
		}
	}
}








