#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int mat[10][7] = {
	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};

int n;
string seq[11];
bool bad[7];

bool check(int numb, string s){
	for (int i=0; i<7; i++){
		if (s[i]=='Y' && mat[numb][i]==0) return false;
		if (s[i]=='N' && mat[numb][i]==1) {
			bad[i] = true;
		}
		if (s[i]=='Y' && bad[i]) return false;
	}
	return true;
}

bool cs(int numb, int start){
	if (start==n) return true;
	if (!check(numb, seq[start])) return false;
	return cs(numb-1, start+1);
}

int main(){
	cin>>n;
    while (n!=0){

    	for (int i=0; i<n; i++)
    		cin>>seq[i];
    	bool res = false;
    	for (int i=n-1; i<10; i++){
    		memset(bad, false, sizeof(bad));
    		if (cs(i, 0)) {
    			res = true;
    			break;
    		}
    	}

    	if (res) cout<<"MATCH"<<endl;
    	else cout<<"MISMATCH"<<endl;

    	cin>>n;
    }
}
