#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int main(){
    int n,T;
    cin>>T;
    for (int t=0; t<T; t++){
    	cin>>n;
    	int a[n][n];
    	for (int i=0; i<n; i++){
    		for (int j=0; j<n; j++){
    			cin>>a[i][j];
    		}
    	}
    	int p[n];
    	int res = 10000;
    	for (int i=0; i<n; i++) p[i] = i;
    	do {
    		int tmp = 0;
    		for (int i=0; i<n; i++){
    			tmp+=a[i][p[i]];
    		}
    		res = min(res, tmp);
    	}	
    	while (next_permutation(p, p+n));
    	cout<<res<<endl;
    }
}
