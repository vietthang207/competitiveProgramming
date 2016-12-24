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

vii pts;
int n;

int main(){
	int T; cin>>T;
	for (int t=0; t<T; t++){
		cin>>n;
		pts.clear();
		int x, y;
		for (int i=0; i<n; i++){
			cin>>x>>y;
			pts.push_back(pii(x,y));
		}
		sort(pts.begin(), pts.end());
		double res = 0;
		int h = 0;
		for (int i=n-2; i>=0; i--){
			int x1 = pts[i].first;
			int y1 = pts[i].second;
			// cout<<res<<endl;
			if (y1>h){
				int x2 = pts[i+1].first;
				int y2 = pts[i+1].second;
				// cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
				double tmp = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
				tmp = sqrt(tmp);
				if (h>y2){
					tmp = (tmp/(y1-y2))*(y1-h);
				}
				res += tmp;
				h = y1;
			}
		}
		printf("%.2f\n", res);
	}
}
