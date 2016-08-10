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

int n, m;
map<string,int> vertices;
vi al[2100];
vi alw[2100];
vector<char> alc[2100];

int main(){
	string tmp;
    while (cin>>m){
    	if (m==0) break;
    	for (int i=0; i<2100; i++){
    		al[i].clear();
    		alw[i].clear();
    		alc[i].clear();
    	}
    	getline(cin, tmp);
    	getline(cin, tmp);
    	istringstream iss(tmp);
    	string cur;
		int coun = 0;
		while (iss>>cur){
			vertices[cur] = coun;
			coun++;
			cout<<cur<<endl;
		}    	
		for (int i=0; i<m; i++){
			string tmp1, tmp2, w;
			cin>>tmp1>>tmp2>>w;
			int v1 = vertices[tmp1];
			int v2 = vertices[tmp2];
			al[v1] = 
		}
    }
}
