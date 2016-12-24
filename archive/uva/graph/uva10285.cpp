#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int mx[] = {-1, 0, 1, 0};
int my[] = {0, 1, 0, -1};

int h[110][110];
bool visited[110][110];
int l[110][110];
int n,m,T;
string name;
vii topo;

void dfs(int x, int y){
	for (int i=0; i<4; i++){
		int nx = x+mx[i];
		int ny = y+my[i];
		if (nx>=0 && nx<n && ny>=0 && ny<=m && !visited[nx][ny] && h[nx][ny]<h[x][y]){
			visited[nx][ny] = true;
			dfs(nx, ny);
		}
	}
	topo.push_back(pii(x,y));
}

int main(){

	cin>>T;
	for (int t=0; t<T; t++){
		cin>>name>>n>>m;
		memset(visited, false, sizeof (visited));
		topo.clear();
		memset(l, -1, sizeof(l));

		for (int i=0; i<n; i++){
			for (int j=0 ;j<m ; j++){
				cin>>h[i][j];
			}
		}
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				if (!visited[i][j]){
					visited[i][j] = true;
					dfs(i, j);
				}
			}
		}

		for (pii cur:topo){
			int x = cur.first;
			int y = cur.second;
			l[x][y] = 1;
			for (int i=0; i<4; i++){
				int nx = x+mx[i];
				int ny = y+my[i];
				if (nx>=0 && nx<n && ny>=0 && ny<=m && h[nx][ny]<h[x][y]){
					l[x][y] = max(l[x][y] , l[nx][ny]+1);
				}	
			}
		}

		int res = -1;
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				res = max(res, l[i][j]);
			}
		}
		cout<<name<<": "<<res<<endl;

	}

}









