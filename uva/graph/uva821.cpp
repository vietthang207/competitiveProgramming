#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;
int am[110][110];

int main(){
	int x,y;
	cin>>x>>y;
	int coun = 1;
	while (x!=0){
		memset(am, 999999, sizeof(am));
		int n = 0;
		map<int,int> m;
		while (x!=0){
			int v1,v2;
			if (m.find(x)==m.end()){
				m[x] = n;
				n++;
			}
			if (m.find(y)==m.end()){
				m[y] = n;
				n++;
			}
			v1 = m[x];
			v2 = m[y];
			am[v1][v2] = 1;
			cin>>x>>y;
		}

		for (int i=0; i<n; i++) am[i][i] = 0;
		for (int k=0; k<n; k++){
			for (int i=0; i<n; i++){
				for (int j=0; j<n; j++){
					am[i][j] = min(am[i][j], am[i][k]+am[k][j]);
				}
			}
		}

		// for (int i=0; i<n; i++){
		// 	for (int j=0; j<n; j++){
		// 		cout<<am[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		int sum = 0;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				sum+=am[i][j];
			}
		}
		printf("Case %d: average length between pages = %.3f clicks\n", coun, 1.0*sum/(n*(n-1)));

		cin>>x>>y;
		coun++;
	}
}
