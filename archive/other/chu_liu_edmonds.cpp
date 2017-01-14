#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef unordered_map<int, int> mii;

#define SIZE = 3300

const double EPS=1e-9;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;
const int NO_EDGE = -1;

int n, nodeCount;
int origin_mat[1100][1100];
int am[SIZE][SIZE]; //adjacent matrix
int hasNode[SIZE];
vi containedNodes[SIZE];
int sbp[SIZE]; //shortest branching parent
vi sbc[SIZE]; //shortest branching children
int vis[SIZE]; //dfs visited
vi st; //dfs stack

bool dfs(int v){
	if (vis[SIZE]) return false;
	vis[SIZE] = 1;
	st.push_back(v);
	for (int i: sbc[v]){
		if (!hasNode[i]) continue;
		if (vis[i]){
			st.push_back(i);
			return true;
		}
		bool res = dfs(i);
		if (res) return res;
	}
	st.pop_back();
	return false;
}

void chuLiuEdmonds(){
	for (int i=0; i<SIZE; i++) {
		if (!hasNode[i]) continue;
		if (sbp[i]!=-1) continue;
		int mi=MAX31;
		for (int j=0; j<SIZE; j++){
			if (!hasNode[j]) continue;
			if (am[j][i] < mi){
				mi = am[j][i];
				sbp[i] = j;
			}
		}
	}

	for (int i=0; i<SIZE; i++){
		if (!hasNode[i]) continue;
		if (sbp[i]==-1) continue; //root node
		int minInCost = am[sbp[i]][i];
		for (int j=0; j<SIZE; j++){
			if (!hasNode[j]) continue;
			am[j][i] -= minInCost;
		}
	}

	memset(vis, 0, sizeof vis);
	st.clear();
	bool hasCycle = false;
	for (int i=0; i<SIZE; i++){
		if (!hasNode) continue;
		if (vis[i]) continue;
		bool res = dfs(i);
		if (res) {
			hasCycle = true;
			break;
		}
	}

	if (hasCycle){
		int newNode = nodeCount++;
		hasNode[newNode] = 1;
		for (int i: st){
			containedNodes[newNode].push_back(i);
			for (int j=0; j<SIZE; j++){
				if (j==newNode) continue;
				if (!hasNode[j]) continue;
				if (am[i][j]!=NO_EDGE) {
					am[newNode][j] = am[i][j];
				}
				if (am[j][i]!=NO_EDGE) {
					am[j][newNode] = am[j][i];
				}
			}
			hasNode[i] = 0;
		}
		st.clear();

		chuLiuEdmonds();

		
	}

}

int main(){
	ios::sync_with_stdio(0);
}







