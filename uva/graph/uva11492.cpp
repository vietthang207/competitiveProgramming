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

int main(){
	string tmp;
    while (cin>>m){
    	if (m==0) break;
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
    }
}
