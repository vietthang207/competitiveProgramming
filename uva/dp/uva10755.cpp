#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int a,b,c,T;
ll arr[22][22][22];
ll sum[22][22][22];

void cal(int n){
	for (int i=0; i<b; i++){
		for (int j=0; j<c; j++){
			ll tmp = arr[n][i][j];
			if (i>0) tmp+=sum[n][i-1][j];
			if (j>0) tmp+=sum[n][i][j-1];
			if (i>0 && j>0) tmp-=sum[n][i-1][j-1];
			sum[n][i][j] = tmp;
			cout<<tmp<<endl;
		}
	}
}

ll getSum(int n, int i1, int j1, int i2, int j2){
	ll res = sum[n][i2][j2];
	if (i1>0) res-=sum[n][i1-1][j2];
	if (j1>0) res-=sum[n][i2][j1-1];
	if (i1>0 && j1>0) res+=sum[n][i1-1][j1-1];
	return res;
}

ll kadane(int i1, int j1, int i2, int j2){
	ll res = getSum(0, i1,j1,i2,j2);
	ll s = 0;
	for (int i=0; i<a; i++){
		ll cur = getSum(i,i1,j1,i2,j2);
		if (s+cur<0) {
			res = max(res, s+cur);
			s = 0;
		}
		else s+=cur;
	}
	return res;
}

int main(){
	cin>>T;
	for (int t=0; t<T; t++){
		cin>>a>>b>>c;
		for (int i=0; i<a; i++){
			for (int j=0; j<b; j++){
				for (int k=0; k<c; k++) cin>>arr[i][j][k];
			}
		}
		for (int i=0; i<a; i++)
			cal(i);

		ll res = arr[0][0][0];
		for (int i1=0; i1<b; i1++){
			for (int j1=0; j1<c; j1++){
				for (int i2=i1; i2<b; i2++){
					for (int j2=j1; j2<c; j2++){
						ll tmp = kadane(i1,j1,i2,j2);
						res = max(res, tmp);
						// cout<<res<<endl;
					}
				}
			}
		}

		cout<<res<<endl;

	}
}
