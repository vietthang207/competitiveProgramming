#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int n,m;
ll a[1100];

int coun(ll s){
	int res = 0;
	ll curLeft = s;
	for (int i=0; i<n; i++){
		if (a[i]>s) return 10000000;
		if (a[i]<curLeft){
			curLeft-=a[i];
		}
		else if (a[i]==curLeft){
			res++;
			curLeft = s;
		}
		else {
			res++;
			curLeft = s-a[i];
		}
	}
	if (curLeft!=s) res++;
	// cout<<s<<" "<<res<<endl;
	return res;
}

int main(){
    while (cin>>n>>m){
    	for (int i=0; i<n; i++)
    		cin>>a[i];
    	ll lo=1, hi=1100000000000;
    	ll mid;
    	while (lo<hi){
    		mid = (lo+hi)/2;
    		int tmp = coun(mid);
    		if (tmp>m) {
    			lo = mid+1;
    		}
    		else {
    			hi = mid;
    		}
    	}
    	cout<<hi<<endl;
    }
}
