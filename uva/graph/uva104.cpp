#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

double a[25][25];
int p[25][25];
int n;

int main(){
    while (cin>>n){

    	// for (int i=0; i<n; i++){
    	// 	for (int j=0; j<n; j++){
    	// 		a[i][j] = -99999999;
    	// 	}
    	// }

    	for (int i=0; i<n; i++){
    		for (int j=0; j<n; j++){
    			if (i==j) {
    				p[i][j] = i;
    				a[i][j] = 1;
    			}
    			else {
    				cin>>a[i][j];
    				a[j][i] = a[i][j];
    			}
    			// cout<<a[i][j]<<" ";
    		}
    		// cout<<endl;
    	}

    	for (int k=0; k<n; k++){
    		for (int i=0; i<n; i++){
    			for (int j=0; j<n; j++){
    				// double tmp = a[i][k]*a[k][j];
    				// if (a[i][j]>tmp){
    				// 	// cout<<i<<" "<<j<<" "<<k<<" "<<tmp<<endl;
    				// 	a[i][j] = tmp;
    				// 	p[i][j] = p[k][j];
    				// }
    				if (i!=j) {
    					p[i][j] = p[k][j];
    					a[i][j] = min(a[i][j], a[i][k]*a[k][j]);
    				}
    			}
    		}
    	}

    	for (int i=0; i<n; i++){
    		for (int j=0; j<n; j++)cout<<a[i][j]<<" ";
    			cout<<endl;
    	}
    	vi res;
    	for (int i=0; i<n; i++){
    		if (a[i][i]+EP>1.01) {
    			vi tmp;
    			tmp.push_back(i);
    			int cur = p[i][i];
    			while (cur !=i) {
    				// cout<<cur<<endl;
    				tmp.push_back(cur);
    				cur = p[i][cur];
    			}
    			for (int j=0; j<tmp.size(); j++) cout<<tmp[j]<<" ";
    				cout<<endl;
    		}
    	}
    	cout<<endl;

    }
}
