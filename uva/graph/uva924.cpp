#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int main(){
	int n;
	cin>>n;
	vi al[n];
	bool visited[n];
	int dist[n];

	for (int i=0; i<n; i++){
		int x, tmp;
		cin>>x;
		for (int j=0; j<x; j++){
			cin>>tmp;
			al[i].push_back(tmp);
		}
	}
	int T;
	cin>>T;
	for (int t=0; t<T; t++){
		int s; cin>>s;
		memset(visited, false, sizeof(visited));
		queue<int> q;
		q.push(s);
		int res = 0;
		int m;
		dist[s] = 0;
		int curDist = 0;
		int curCoun = 0;
		visited[s] = true;
		while (!q.empty()){
			int cur = q.front();
			q.pop();
			for (int i:al[cur]){
				// cout<<"x "<<curCoun<<endl;	
				if (!visited[i]){
					visited[i] = true;
					dist[i] = dist[cur]+1;
					q.push(i);
					if (dist[i]!=curDist){
						if (res<curCoun){
							res = curCoun;
							m = dist[i];
						}
						curCoun = 0;
						curDist = dist[i];
					}	
					curCoun++;
				}
			}
			if (curCoun>res) {
				res = curCoun;
				m = curDist;
			}
		}
		if (res == 0) cout<<0<<endl;
		else cout<<res<<" "<<m<<endl;
	}
}
