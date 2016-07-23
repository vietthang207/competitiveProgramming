#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int n;
int a[110000];

bool check(int k){
	int pos = 0;
	for (int i=0; i<n; i++){
		int dis = a[i]-pos;
		if (dis>k) return false;
		if (dis==k){
			k--;
		}
		pos = a[i];
	}
	return true;
}

int main(){
	int T;
	cin>>T;
	for (int t=0;t<T; t++){
		cin>>n;
		for (int i=0; i<n; i++)
			cin>>a[i];
		int lo=1, hi=12000000;
		int mid;
		while (lo<hi){
			mid = (hi+lo)/2;
			if (check(mid)){
				hi = mid;
			}
			else {
				lo = mid+1;
			}
		}
		printf("Case %d: %d\n", t+1, hi);
	}
}
