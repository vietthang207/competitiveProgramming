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
#define PI acos(-1.0)

int main(){
	double l,w,h,t;
	while (cin>>l>>w>>h>>t){
		double l1 = l*tan(PI*t/180);
		if (h-l1>0){
			double s = 0.5*l*l*tan(PI*t/180);
			double res = w*(l*h-s);
			printf("%.3f mL\n", res);
		}
		else {
			double s = 0.5*h*h/tan(PI*t/180);
			double res = w*s;
			printf("%.3f mL\n", res);
		}
	}
}
