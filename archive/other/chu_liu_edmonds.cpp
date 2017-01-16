#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef unordered_map<int, int> mii;

const double EPS=1e-9;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;

vi al[1100];
int vis[1100];

void dfs(int v){
	if (vis[v]) return;
	vis[v] = 1;
	for (int i: al[v]){
		dfs(i);
	}
}

struct Edge{int u, v, w;};
int chuLiuEdmonds(int n, int root, vector<Edge> edges) {
	vi cost(n), parent(n), label(n), cycle(n);
	int res = 0;
	while(1){
		cost.assign(n, MAX31);
		for (Edge e: edges) {
			if (e.u == e.v) continue;
			if (e.w < cost[e.v]){
				cost[e.v] = e.w;
				parent[e.v] = e.u;
			}
		}
		cost[root] = 0;
		for (int i=0; i<n; i++){
			if (cost[i]!=MAX31) res+=cost[i];
		}

		int cnt = 0;
		label.assign(n, -1);
		cycle.assign(n, -1);
		for (int i=0; i<n; i++){
			int cur = i;
			while (cur!=root && cycle[cur] == -1) {
				cycle[cur] = i;
				cur = parent[cur];
			}
			if (cur!=root && cycle[cur]==i) {
				while (label[cur] == -1) {
					label[cur] = cnt;
					cur = parent[cur];
				}
				cnt++;
			}
		}
		if (cnt == 0) break;
		for (int i=0; i<n; i++){
			if (label[i] == -1) label[i] = cnt++;
		}

		for (Edge &e: edges) {
			if (label[e.u] != label[e.v]) e.w -= cost[e.v];
			e.u = label[e.u];
			e.v = label[e.v];
		}
		n = cnt;
		root = label[root];
	}	
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	int T, n, m;
	int x, y, z;
	cin>>T;
	for (int t=0; t<T; t++){
		cin>>n>>m;
		n++;
		for (int i=0; i<n; i++) al[i].clear();
		memset(vis, 0, sizeof vis);
		vector<Edge> edges;
		while (m--) {
			Edge e;
			cin>>e.u>>e.v>>e.w;
			edges.push_back(e);
			al[e.u].push_back(e.v);
		}
		dfs(0);
		int flag = 0;
		for (int i=0; i<n; i++){
			if (!vis[i]) flag = 1;
		}
		if (flag) cout<<"Case #"<<t+1<<": "<<"I cannot be the very best!"<<endl;
		else cout<<"Case #"<<t+1<<": "<<chuLiuEdmonds(n, 0, edges)<<endl;
	}
}