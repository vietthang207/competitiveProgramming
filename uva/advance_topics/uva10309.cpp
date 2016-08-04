#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef map<int, int> mii;

const double EP=1e-6;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;

bool a[10][10];
bool b[10][10];

bool swi(int i, int j){
	b[i][j] = !b[i][j];
	if (i>0) b[i-1][j] = !b[i-1][j];
	if (i<9) b[i+1][j] = !b[i+1][j];
	if (j>0) b[i][j-1] = !b[i][j-1];
	if (j<9) b[i][j+1] = !b[i][j+1];
}

int process(int n){
	int res = 0;
	for (int i=0; i<10; i++)
		for (int j=0; j<10; j++)
			b[i][j] = a[i][j];
	for (int i=0; i<10; i++){
		if ( (n & (1<<i)) != 0) {
			swi(0, i);
			res++;
		}
	}
	for (int i=1; i<10; i++){
		for (int j=0; j<10; j++){
			if (b[i-1][j]) {
				swi(i, j);
				res++;
			}
		}
	}
	for (int i=0; i<10; i++){
		if (b[9][i]) return 1000;
	}
	return res;
}

int main(){
	string name;
	string tmp;
    while (cin>>name){
    	if (name=="end") break;
    	for (int i=0; i<10; i++){
    		cin>>tmp;
    		for (int j=0; j<10; j++){
    			if (tmp[j]=='#') a[i][j] = false;
    			else a[i][j] = true;
    		}
    	}
    	int res = 1000;
    	for (int i=0; i< (1<<10); i++){
    		res = min(res, process(i));
    	}
    	if (res<1000) cout<<name<<" "<<res<<endl;
    	else cout<<name<<" "<<-1<<endl;
    }
}
