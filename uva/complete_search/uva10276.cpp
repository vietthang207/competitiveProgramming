#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int n;

int res;

void cs(int cur, vi a){
    //for (int i=0; i<a.size(); i++){
    //	cout<<a[i]<<" ";
    //  }
    //cout<<res<<endl;
    for (int i=0; i<a.size(); i++){
	if (a[i]==0){
	    if (cur>res) res = cur;
	    vi b=(a);
	    b[i] = cur;
	    cs(cur+1, b);
	    break;
	}
	else if ( ((int)sqrt(a[i]+cur))*((int)sqrt(a[i]+cur)) == a[i]+cur){
	    if (cur>res) res = cur;
	    vi b(a);
	    b[i]= cur;
	    cs(cur+1, b);
	    break;
	}
    }
}

int main(){
    int t=-1 ; 
    int count=1;
    cin>>t;
    for (int i=0; i<t; i++){

	res = 0;
	cin>>n;
	vi a(n);
	cs(1, a);
	cout<<res<<endl;
    }
}
