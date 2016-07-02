#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int a, int b, int c){
    int root = sqrt(c);
    for (int i=0-root; i<=root; i++){
	int root1 = sqrt(c-i*i);
	for (int j=0-root1; j<=root1; j++){
	    int k = a-i-j;
	    if (i!=j && i!=k && j!=k && k*k+i*i+j*j==c && i*j*k ==b ){
		cout<<i<<" "<<j<<" "<<k<<endl;
		return;
	    }
	}
    }
    cout<<"No solution."<<endl;
}

int main(){
    int n=-1 ; 
    cin>>n;
    int a,b,c;
    for (int i=0; i<n; i++){
	cin>>a>>b>>c;
	solve(a,b,c);
    }
}
