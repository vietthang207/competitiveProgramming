#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int n,m;
pii el[2100];
int we[2100];
int d[1100];

int main(){
	int T; cin>>T;
	for (int t=0 ; t<T; t++){
		cin>>n>>m;
		memset(d, 20000000, sizeof(d));
		for (int i=0; i<m; i++){
			int x,y, w;
			cin>>x>>y>>w;
			el[i] = pii(x,y);
			we[i] = w;
		}

		d[0] = 0;
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				pii p = el[j];
				int x = p.first, y = p.second;
				d[y] = min(d[y], d[x]+we[j]);
			}
		}
		int res = false;
		for (int i=0; i<m; i++){
			pii p = el[i];
			int x = p.first, y = p.second;
			if (d[y]>d[x]+we[i]){
				res = true;
			}
		}

		if (res) cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;

	}
}
