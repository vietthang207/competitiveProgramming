#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int s,d;
int n=12;
int tmp[12];

int cal(int m){
	int res = 0;	
	for (int i=0; i<n; i++){
		if ( (m & (1<<i)) ==0) res+=s;
		else res-=d;
	}
	return res;
}

bool check(int m){
	for (int i=0; i<n; i++){
		if ( (m & (1<<i)) ==0) tmp[i] = s;
		else tmp[i] = -d;
	}
	for (int i=0; i<8; i++){
		int su = 0;
		for (int j=i; j<i+5; j++) su+=tmp[j];
		if (su>=0) return false;
	}
	return true;
}

int main(){
    while (cin>>s>>d){
    	int res = -99999999;
    	for (int m=0; m<(1<<12); m++){
    		if (check(m)) res = max(res, cal(m));
    	}
    	if (res>0) cout<<res<<endl;
    	else cout<<"Deficit"<<endl;
    }
}
