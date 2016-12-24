#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int mx[] = {-1, 0, 1, 0};
int my[] = {0, 1, 0, -1};

int m,n;
bool b[1100][1100];
int d[1100][1100];
bool visited[1100][1100];

int main(){
	cin>>m>>n;
    while (m>0){

    	memset(b, false, sizeof(b));
    	memset(d, -1, sizeof(d));
    	memset(visited, false, sizeof(visited));
    	int coun; cin>>coun;
    	for (int i=0; i<coun; i++){
    		int r, no, tmp;
    		cin>>r>>no;
    		for (int j=0; j<no; j++){
    			cin>>tmp;
    			b[r][tmp] = true;
    		}
    	}

    	int sx, sy, dx, dy;
    	cin>>sx>>sy>>dx>>dy;

    	queue<pii> q;
    	q.push(pii(sx, sy));
    	d[sx][sy] = 0;
    	visited[sx][sy] = true;
    	while (!q.empty()){
    		pii cur = q.front();
    		q.pop();
    		int curx = cur.first, cury = cur.second;
    		// cout<<curx<<" "<<cury<<endl;
    		if (curx==dx && cury==dy){
    			cout<<d[curx][cury]<<endl;
    			break;
    		}
    		for (int i=0; i<4; i++){
    			int nx = mx[i]+curx;
    			int ny = my[i]+cury;
    			if (nx>=0 && nx<m && ny>=0 && ny<n && !b[nx][ny] && !visited[nx][ny]){
    				visited[nx][ny] = true;
    				d[nx][ny] = d[curx][cury]+1;
    				q.push(pii(nx,ny));
    			}
    		}
    	}

    	cin>>m>>n;
    }
}
