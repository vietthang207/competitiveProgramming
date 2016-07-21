#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;
const double INF=99999999;

int v,e,n;
double am[60][60];
int store[60];
double save[60];
double memo[60][100000];
bool solved[60][100000];
bool visited[60];

double tsp(int pos, int mask){
	// cout<<pos<<" "<<mask<<endl;
	if (solved[pos][mask]) return memo[pos][mask];

	double res = am[0][pos];
	double tmp = 0;
	int mask1 = mask;
	if (store[pos]!=-1){
		if ( (mask & (1<<store[pos])) == 0){
			res -= save[pos];
			tmp -= save[pos];
			mask1 = mask | (1<<(store[pos]));
		}
	}

	if (mask1 == ((1<<n)-1)){
		solved[pos][mask] = true;
		return memo[pos][mask] = res;
	} 

	for (int i=0; i<v; i++){
		if (store[i]==-1 || visited[i] || i==pos) continue;
		visited[i] = true;
		double tmp1 = tmp + am[pos][i] + tsp(i, mask1);
		visited[i] = false;
		res = min(res, tmp1);	
	}
	solved[pos][mask] = true;
	return memo[pos][mask] = res;

}

int main(){
	int T;
	cin>>T;
	for (int t=0; t<T; t++){
		
		for (int i=0; i<60; i++){
			for (int j=0; j<60; j++){
				am[i][j] = INF;
			}
		}

		memset(solved, false, sizeof(solved));
		memset(store, -1, sizeof(store));
		memset(visited, false, sizeof(visited));

		cin>>v>>e;
		v++;
		for (int i=0; i<e; i++){
			int x,y;
			cin>>x>>y;
			cin>>am[x][y];
			am[y][x] = am[x][y];
		}

		for (int i=0; i<v; i++){
			am[i][i] = 0;
		}

		for (int k=0; k<v; k++){
			for (int i=0; i<v; i++){
				for (int j=0; j<v; j++){
					am[i][j] = min(am[i][j], am[i][k]+am[k][j]);
				}	
			}
		}

		// for (int i=0; i<v; i++){
		// 	for (int j=	0; j<v; j++) cout<<am[i][j]<<" ";
		// 		cout<<endl;
		// }

		cin>>n;
		for (int i=0; i<n; i++){
			int s;
			double m;
			cin>>s>>m;
			store[s] = i;
			save[s] = m;
		}


		visited[0] = true;
		double m = tsp(0,0);
		if (m+EP <0) printf("Daniel can save $%.2f\n", -m);
		else cout<<"Don't leave the house"<<endl;
	}
}
