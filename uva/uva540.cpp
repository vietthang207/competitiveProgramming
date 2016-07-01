#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int t, n;
map<int, int> member;
queue<int> q;
vector<queue<int> > teams;

int main(){
    int n=-1 ; 
    int count=1;
    cin>>n;
    while (n!=0){
	teams.clear();
	member.clear();
	q=queue<int>();
	printf("Scenario #%d\n", count);
	for (int i=0; i<n; i++){
	    queue<int> bla;
	    teams.push_back(bla);
	    int m,x;
	    cin>>m;
	    for (int j=0; j<m; j++){
		cin>>x;
		member[x]=i;
	    }
	}

	string cmd;
	cin>>cmd;
	while (cmd!="STOP"){
	    if (cmd == "ENQUEUE"){
		int id;
		cin>>id;
		//cout<<cmd<<id<<endl;
		int team = member[id];
		if (teams[team].size()==0){
		    q.push(team);
		}
		teams[team].push(id);
	    }
	    else if (cmd=="DEQUEUE"){
		//cout<<cmd<<endl;
		cout<<teams[q.front()].front()<<endl;
		teams[q.front()].pop();
		if (teams[q.front()].size()==0){
		    q.pop();
		}
	    }
	    //else cout<<cmd;
	    cin>>cmd;
	}
	cout<<endl;
	count ++;
	cin>>n;
    }
}
