#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int n,m;
int am[110][110];

int main(){
	int T;
	cin>>T;
	for (int t=0; t<T; t++){
		cin>>n>>m;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++) {
				am[i][j] = 999;
			}
		}
		for (int i=0; i<m; i++){	
			int v1,v2;
			cin>>v1>>v2;
			am[v1][v2] = am[v2][v1] = 1;
		}
		for (int i=0; i<n; i++) am[i][i] = 0;
		//for (int i=0; i<n; i++){
		//	for (int j=0; j<n; j++) {
		//		cout<<am[i][j]<<" ";
		//	}
		//	cout<<endl;
		//}
		for (int k=0; k<n; k++){
			for (int i=0; i<n; i++){
				for (int j=0; j<n; j++){
					am[i][j] = min(am[i][j], am[i][k]+am[k][j]);
				}
			}
		}
		//cout<<endl;
		//for (int i=0; i<n; i++){
		//	for (int j=0; j<n; j++) {
		//		cout<<am[i][j]<<" ";
		//	}
		//	cout<<endl;
		//}
		int s, d;
		cin>>s>>d;
		int m = -1;
		for (int i=0; i<n; i++){
			int tmp = am[s][i] + am[i][d];
			m = max(tmp, m);
		}
		printf("Case %d: %d\n", t+1, m);
	}
}
