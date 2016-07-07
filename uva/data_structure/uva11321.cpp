#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m;
ll a[10009];

bool cmp (ll i, ll j){
    if (i%m == j%m) {
	if (i%2 == 0 && j%2==0){
	    return i<j;
	} else if (i%2 !=0 && j%2!=0){
	    return i>j;
	}
	return i%2!=0;
    }
    return (i%m<j%m) ;
}

int main(){
    int n=-1 ; 
    int count=1;
    cin>>n>>m;
    while (n!=0){
	for (int i=0; i<n; i++){
	    cin>>a[i];
	}
	sort(a, a+n, cmp);

	cout<<n<<" "<<m<<endl;

	for (int i=0; i<n; i++){
	    printf("%lld\n", a[i]);
	}
	count ++;
	cin>>n>>m;
    }
	cout<<"0 0"<<endl;
}
