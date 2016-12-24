#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int m,n, Q;
int a[600][600];

int main(){
	cin>>n>>m;
	while (n!=0){
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				cin>>a[i][j];
			}
		}
		cin>>Q;
		for (int q=0; q<Q; q++){
			int x,y;
			cin>>x>>y;
		}
	}
}
