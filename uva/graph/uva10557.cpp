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

int n;
vi al[110];
int ene[110];
int sp[110];

int main(){
	int coun=1;
	while (cin>>n){
		if (n==-1) break;
		for (int i=0; i<n; i++){
			sp[i] = MAX31;
			al[i].clear();
			cin>>ene[i];
			ene[i] = -ene[i];
			int m; cin>>m;
			for (int j=0; j<m; j++){
				int tmp; cin>>tmp;
				tmp--;
				al[i].push_back(tmp);
			}
		}

		sp[0] = 0;
		for (int k=0; k<n-1; k++){}
			for (int i=0; i<n; i++){
				for (int j=0; j<al[i].size(); j++){
					sp[j] = min(sp[j], ene[j] + sp[i]);
				}
			}
		}
		set<int> loop;
		for (int i=0; i<n; i++){
			for (int j=0; j<al[i].size(); j++){
				if (sp[j]>sp[i]+ene[j]) {
					loop.insert(j);
				}
			}
		}
		bool res = false;
		if (sp[])

		coun ++;
	}
}
