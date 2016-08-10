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
const double PI = acos(-1);

int T, d,l;

int main(){
	cin>>T;
	for (int t=0; t<T; t++){
		cin>>d>>l;
		double a = l/2.0;
		double b = sqrt(l*l/4.0-d*d/4.0);
		printf("%.3f\n", PI*a*b);
	}
}
