#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int main(){
    int n;
    cin>>n;
    while (n>=0){
    	cout<<n<<" coconuts, ";
    	bool found = false;
    	int res;
    	for (int i=2; (i-1)*(i-1)<=n; i++){
    		int tmp = n;
    		bool flag = true;
    		for (int j=0; j<i; j++){
    			if (tmp%i!=1) {
    				flag = false;
    				break;
    			}
    			else {
    				tmp--;
    				tmp-=(tmp/i);
    			}
    		}
    		if (flag && tmp%i==0){
    			found = true;
    			res = i;
    		} 

    	}

    	if (found) cout<<res<<" people and 1 monkey"<<endl;
    	else cout<<"no solution"<<endl;
    	cin>>n;
    }
}
