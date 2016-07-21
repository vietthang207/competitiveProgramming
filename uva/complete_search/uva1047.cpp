#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

vi count1(int mask){
	vi res;
	for (int i=0; i<20; i++){
		if ( (mask & (1<<i)) !=0) res.push_back(i);
	}
	return res;
}

int main(){
    int n, m, z;
    int coun=1;
    cin>>n>>m;
    while (n!=0){
    	int t[n];
    	for (int i=0; i<n; i++) cin>>t[i];
    	cin>>z;

    	vi v[z];
    	int size[z];
    	for (int i=0; i<z; i++){
    		int x;
    		cin>>x;
    		for (int j=0; j<x; j++) {
    			int tmp;
    			cin>>tmp;
    			v[i].push_back(tmp-1);
    		}
    		cin>>size[i];
    	}

    	int res = -1;
    	int resMask;

    	for (int mask=0; mask<(1<<n); mask++){
    		vi towers = count1(mask);
    		// cout<<towers.size()<<endl;
    		if (towers.size()!=m) continue;
    		int tmp=0;
    		for (int i=0; i<towers.size(); i++){
    			tmp+= t[towers[i]];
    		}
    		for (int i=0; i<z; i++){
    			int setCoun = 0;
    			for (int j: v[i]){
    				for (int k=0; k<towers.size(); k++){
    					if (j==towers[k]) setCoun++;
    				}
    			}
    			if (setCoun==0) continue;
    			tmp -= size[i]*(setCoun-1);
    		// if (mask==28) cout<<tmp<<endl;
    		}
    		if (tmp>res) {
    			res = tmp;
    			resMask = mask;
    		}
    		if (tmp==res){
    			int xo = (mask^resMask);
    			int least = (xo & (-xo));
    			// cout<<xo<<" "<<least<<endl;
    			if ( (mask & least) !=0) resMask = mask;
    		}
    	}

    	printf("Case Number  %d\n", coun);
    	printf("Number of Customers: %d\n", res);
    	printf("Locations recommended:");
    	for (int i:count1(resMask)){
    		cout<<" "<<i+1;
    	}
    	cout<<endl;
    	cout<<endl;

        coun ++;
        cin>>n>>m;
    }
}










