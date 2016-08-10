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

int T;

int main(){
	cin>>T;
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;
	for (int t=0; t<T; t++){
		cin>>x1>>y1>>x2>>y2;
		cin>>x3>>y3>>x4>>y4;
		bool flag;
		if (x1>=x4 || y1>=y4 || x2<=x3 || y2<=y3){
			flag = false;
			cout<<"No Overlap"<<endl;
		}
		else {
			int resx1, resy1, resx2, resy2;
			if (x1>=x3){
				resx1 = x1; 
				resx2 = min(x2,x4);
			}
			else {
				resx1 = x3;
				resx2 = min(x2,x4);
			}
			resy1 = max(y1,y3);
			resy2 = min(y2,y4);
			cout<<resx1<<" "<<resy1<<" "<<resx2<<" "<<resy2<<endl;
		}
		if (t!=T-1) cout<<endl;
	}
}
