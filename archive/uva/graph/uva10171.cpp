#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int amy[30][30];
int amm[30][30];
char name[30];

int main(){
    int n;
    cin>>n;
    while (n!=0){

    	memset(amy, 20000, sizeof(amy));
    	memset(amm, 20000, sizeof(amm));

    	map<char,int> m;
    	int coun = 0;
    	for (int i=0; i<n; i++){
    		char age, ub, c1,c2;
    		int w;
    		cin>>age>>ub>>c1>>c2>>w;
    		if (m.find(c1)==m.end()){
    			m[c1] = coun;
    			name[coun] = c1;
    			coun++;
    		}
    		if (m.find(c2) == m.end()){
    			m[c2] = coun;
    			name[coun] = c2;
    			coun++;
    		}

    		int v1 = m[c1], v2 = m[c2];
    		if (age=='Y'){
    			amy[v1][v2] = min(amy[v1][v2],w);
    			if (ub=='B') amy[v2][v1] = min(amy[v2][v1],w);
    		}
    		else {
    			amm[v1][v2] = min(amm[v1][v2], w);
    			if (ub=='B') amm[v2][v1] = min(amm[v2][v1], w);
    		}
    	}

    	for (int i=0; i<coun; i++) {
    		amy[i][i] = amm[i][i] = 0;
    	}

    	for (int k=0; k<coun; k++){
    		for (int i=0; i<coun; i++){
    			for (int j=0; j<coun; j++){
    				amy[i][j] = min(amy[i][j], amy[i][k]+amy[k][j]);
    				amm[i][j] = min(amm[i][j], amm[i][k]+amm[k][j]);
    			}
    		}
    	}

    	vi pos;
    	int res = 20000;
    	char c1, c2;
		vector<char> chars;
    	cin>>c1>>c2;
    	if (c1==c2 && m.find(c1)==m.end()) {
    		cout<<0<<" "<<c1<<endl;
    		cin>>n;
    		continue;
    	}
    	if (c1!=c2 && (m.find(c1)==m.end() || m.find(c2)==m.end())){
    		cout<<"You will never meet."<<endl;
    		cin>>n;
    		continue;
    	}
    	int v1 = m[c1], v2= m[c2];
    	for (int i=0; i<coun; i++)	{
    		int tmp = amy[v1][i]+amm[v2][i];
    		if (tmp<res) {
    			res = tmp;
    			pos = vi();
    			pos.push_back(i);
    		}
    		else if (tmp==res){
    			pos.push_back(i);
    		}
    	}

    	if (pos.empty()) cout<<"You will never meet."<<endl;
    	else {
    		cout<<res;
    		for (int i:pos) chars.push_back(name[i]);
    		sort(chars.begin(), chars.end());
    		for (char c:chars) cout<<" "<<c;
    		cout<<endl;
    	} 

    	cin>>n;
    }
}
















