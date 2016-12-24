#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int a[11000];
int b[11000];

int main(){
    int n,m;;
    int coun=1;
    cin>>n>>m;
    while (n!=0 && m!=0){

    	for (int i=0; i<n; i++) cin>>a[i];
    	for (int i=0; i<m; i++) cin>>b[i];

    	int res;
    	if (n<=m) res = 0;
    	else res = n-m;

    	sort(a, a+n);
    	printf("Case %d: ", coun);
    	if (res == 0) cout<<res<<endl;
    	else cout<<res<<" "<<a[0]<<endl;

    	cin>>n>>m;
        coun ++;
    }
}
