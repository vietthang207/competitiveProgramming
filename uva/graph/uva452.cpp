#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int T;
vi al[30];
bool visited[30];
int l[30];
vi topo;

void dfs(int v){
	visited[v] = true;
	for (int i:al[v]){
		if (!visited[i]) dfs(i);
	}
	topo.push_back(v);
}
int main(){
	cin>>T;
	string tmp;
	getline(cin, tmp);
	getline(cin, tmp);
	for (int t=0; t<T; t++){
		// cout<<t;
		memset(visited, false ,sizeof(visited));
		memset(l, -1, sizeof(l));
		topo.clear();
		for (int i=0; i<30; i++) al[i].clear();

			int coun = 0;
		map<char, int> m;
		map<int, int> weight;
		getline(cin, tmp);
		while (tmp!=""){
			char c1 = tmp[0];
			int w = tmp[2] -'0';
			vector<char> p;
			for (int i=4; i<tmp.size(); i++){
				p.push_back(tmp[i]);
			}
			if (m.find(c1)==m.end()){
				m[c1] = coun++;
			}
			int child = m[c1];
			weight[child] = w;
			for (int i=0; i<p.size(); i++){
				if (m.find(p[i])==m.end()) m[p[i]] = coun++;
				int par = m[p[i]];
				al[par].push_back(child);
				// cout<<p[i]<<" "<<c1<<" "<<w<<endl;
			}

			
			getline(cin, tmp);
		}
		dfs(0);
		for (int cur: topo){
			l[cur] = weight[cur];
			for (int i:al[cur]){
				l[cur] = max(l[cur], l[i]+weight[cur]);
			}
		}

		int res = -1;
		for (int cur: topo){
			res = max(res, l[cur]);
		}
		cout<<res<<endl<<endl;
	}
}
