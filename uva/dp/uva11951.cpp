#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int n,m,k,T;
ll a[110][110];
ll sum[110][110];

int main(){
	cin>>T;
	for (int t=0; t<T; t++){
		cin>>n>>m>>k;
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				cin>>a[i][j];
			}
		}
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				ll tmp = a[i][j];
				if (i>0) tmp+=sum[i-1][j];
				if (j>0) tmp+=sum[i][j-1];
				if (i>0 && j>0) tmp-=sum[i-1][j-1];
				sum[i][j] = tmp; 
			}
		}

		ll res = 0;
		ll p = 0;

		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				for (int i1=i; i1<n; i1++){
					for (int j1=j; j1<m; j1++){
						ll tmp = sum[i1][j1];
						if (i>0) tmp-=sum[i-1][j1];
						if (j>0) tmp-=sum[i1][j-1];
						if (i>0 && j>0) tmp+=sum[i-1][j-1];
						int area = (i1-i+1)*(j1-j+1);
						// cout<<area<<" "<<tmp<<endl;
						if (tmp>k) continue;
						if (area>res){
							res = area;
							p = tmp;
						}
						else if (area==res){
							p = min(p,tmp);
						}
					}
				}
			}
		}

		printf("Case #%d: %lld %lld\n", t+1, res, p);

	}
}
