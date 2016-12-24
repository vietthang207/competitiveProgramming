#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef map<int, int> mii;

const double EPS=1e-9;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;

int n;
int a[100000];
int b[100000];

int main(){
	while (cin>>n){
		if (n==0) break;
		for (int i=0; i<n; i++){
			cin>>a[i]>>b[i];
			if (a[i]>b[i]){
				double tmp = b[i];
				b[i] = a[i];
				a[i] = tmp;
			}
			a[i]*=4;
			b[i]*=4;
		}
		int maxi = -1;
		int res;
		for (int i=0; i<n; i++){
			int tmp;
			// if (b[i]>a[i]*4) tmp = a[i];
			// else tmp = a[i]/2;
			tmp = min(a[i], b[i]/4);
			tmp = max(tmp, a[i]/2);
			if (tmp>maxi){
				maxi = tmp;
				res = i;
			}
		}
		cout<<res+1<<endl;
	}
}
