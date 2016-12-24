#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef map<int, int> mii;

const double EPS=1e-9;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;

int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, 1, 0, -1};

int n,m;
bool visited[2100][2100];
int dis[2100][2100];
vii mall1, mall2;

int main(){
	while (cin>>n){
		if (n==0) break;
		memset(visited, false, sizeof visited);
		mall1.clear();
		mall2.clear();
		int minx=MAX31, maxx=MIN31, miny=MAX31, maxy=MIN31;
		queue<int> qx, qy;
		for (int i=0; i<n; i++){
			int x,y;
			cin>>x>>y;
			minx = min(minx, x);
			miny = min(miny, y);
			maxx = max(maxx, x);
			maxy = max(maxy, y);
			pii tmp = pii(x,y);
			mall1.push_back(tmp);
			dis[x][y] = 0;
			qx.push(x);
			qy.push(y);
			visited[x][y] = true;
		}
		cin>>m;
		for (int i=0; i<m; i++){
			int x,y;
			cin>>x>>y;
			minx = min(minx, x);
			miny = min(miny, y);
			maxx = max(maxx, x);
			maxy = max(maxy, y);
			pii tmp = pii(x,y);
			mall2.push_back(tmp);
		}
		int res = -1;
		while (!qx.empty()){
			int curx = qx.front();
			int cury = qy.front();
			qx.pop();
			qy.pop();
			pii cur = pii(curx,cury);
			// cout<<cur.first<<" "<<cur.second<<endl;
			bool flag = false;
			for (pii p:mall2){
				if (cur.first == p.first && cur.second == p.second){
					flag = true;
					break;
				}
			}
			if (flag) {
				res = dis[cur.first][cur.second];
				break;
			}
			for (int i=0; i<4; i++){
				int x = cur.first + mx[i];
				int y = cur.second + my[i];
				if (x>=minx && x<=maxx && y>=miny && y<=maxy && !visited[x][y]){
					visited[x][y] = true;
					dis[x][y] = dis[cur.first][cur.second]+1;
					qx.push(x);
					qy.push(y);
				}
			}
		}
		cout<<res<<endl;
	}
}






