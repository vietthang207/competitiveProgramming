#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

string s1, s2;
int memo[110][110];
int dp(int i, int j){
	if (memo[i][j]!=-1) return memo[i][j];
	if (i==s1.size() || j==s2.size()) return 0;
	int r0 = -1;
	if (s1[i] == s2[j]) r0= 1+dp(i+1, j+1);
	int r1 = dp(i+1, j);
	int r2 = dp(i, j+1);
	int r = max(r0, max(r1,r2));
	memo[i][j] = r;
	return r;
}

int main(){
    int coun=1;
    getline(cin, s1);
    while (s1!="#"){
    	getline(cin, s2);
    	memset(memo, -1, sizeof(memo));
    	int res = dp(0,0);
    	printf("Case #%d: you can visit at most %d cities.\n", coun, res);
    	getline(cin, s1);
        coun ++;
    }
}
