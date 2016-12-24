#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

string g1[6];
string g2[6];

int main(){
	int T; 
	cin>>T;
	for (int t=0; t<T; t++){
		int k;
		cin>>k;
		for (int i=0; i<6; i++) cin>>g1[i];
		for (int i=0; i<6; i++) cin>>g2[i];
		vi v[5];
		for (int i=0; i<5; i++){
			for (int j=0; j<6; j++){
				char cur = g1[j][i];
				for (int k=0; k<6; k++){
					if (cur==g2[k][i]){
						bool flag = false;
						for (int x:v[i]){
							if (x==cur) flag = true;
						}
						if (!flag)v[i].push_back(cur);
						break;
					}
				}
			}
		}
		for (int i=0; i<5; i++) sort(v[i].begin(), v[i].end());
		int max =1;
		for (int i=0; i<5; i++)
			max*=v[i].size();
		if (k>max) {
			cout<<"NO"<<endl;
			continue;
		}
		k--;
		char res[5];

		for (int i=4; i>=0; i--){
			res[i] = v[i][k%v[i].size()];
			k/=v[i].size();
		}

		for (int i=0; i<5; i++) cout<<res[i];
			cout<<endl;

	}
}
