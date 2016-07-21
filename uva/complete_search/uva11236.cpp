#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;
const ll big = 1000000;

int main(){
	int n=2001;
	int coun = 0;
	for (ll a=1; a<n; a++){
		for (ll b=a; b<n-a; b++){
			for (ll c=b; c<n-a-b; c++){
				ll num = big*(a+b+c);
				ll denom = a*b*c-big;
				if (denom!=0 && num%denom==0){
					ll d = num/denom;
					if (d>=c && d<n-a-b-c) printf("%.2f %.2f %.2f %.2f\n", a/100.0, b/100.0, c/100.0, d/100.0);
				}
			}
		}
	}
}
