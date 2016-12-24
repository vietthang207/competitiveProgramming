#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int n,m;
int a[70000];
int b[70000];
vi c;
vi lis;
vi e;

int main(){
	int T;
	cin>>T;
	for (int t=0; t<T; t++){
		cin>>n;
		cin>>n>>m;
		n++; m++;
		c.clear();
		lis.clear();

		map<int,int> ma;
		for (int i=0; i<n; i++) {
			cin>>a[i];
			ma[a[i]] = i;
		}
		for (int j=0; j<m; j++) {
			cin>>b[j];
			if (ma.find(b[j])!=ma.end()){
				c.push_back(ma[b[j]]);
			}
		}
		lis.push_back(c[0]);
		for (int i=1; i<c.size(); i++){
			int cur = c[i];
			int pos = upper_bound(lis.begin(), lis.end(), cur) - lis.begin();
			if (pos == lis.size()) lis.push_back(cur);
			else lis[pos] = cur;
		}
		printf("Case %d: %d\n", t+1, (int)lis.size());
	}
}
