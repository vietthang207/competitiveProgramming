#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef map<int, int> mii;

const double EP=1e-6;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;

int s, e, m;
vi a;

vi al[10000];
int dis[10000];

int main(){
    int n = 10000;
    int coun = 1;
    while (cin>>s>>e>>m){
    	if (m==0) break;
    	a.clear();
    	for (int i=0; i<n; i++) 
    		al[i].clear();
    	memset(dis, -1, sizeof dis);

    	for (int i=0; i<m; i++){
    		int tmp; cin>>tmp;
    		a.push_back(tmp);
    	}

    	for (int i=0; i<n; i++){
    		for (int j:a){
    			int tmp = (i+j)%n;
    			al[i].push_back(tmp);
    			// cout<<i<<" "<<tmp<<endl;
    		}
    	}

    	queue<int> q;
    	q.push(s);
    	dis[s] = 0;

    	int res = -1;

    	while (!q.empty()){
    		int cur = q.front();
    		q.pop();
    		// cout<<cur<<" "<<e<<endl;
    		if (cur == e){
    			res = dis[cur];
    			break;
    		}
    		for (int i:al[cur]){
    			if (dis[i]==-1){
    				dis[i] = dis[cur]+1;
    				q.push(i);
    			}
    		}
    	}
    	cout<<"Case "<<coun<<": ";
    	if (res==-1) cout<<"Permanently Locked"<<endl;
    	else cout<<res<<endl;

    	coun++;
    }
}
