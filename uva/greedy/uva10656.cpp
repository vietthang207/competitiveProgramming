#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int a[1100];

int main(){
	int n;
	cin>>n;
	while (n!=0){
		// cout<<n<<endl;
		for (int i=0; i<n; i++)
			cin>>a[i];

		bool flag = false;
		int first = 0;
		for (int i=0; i<n; i++){
			if (a[i]!=0) {
				flag = true;
				first = i;
				break;
			}
		}
		cout<<a[first];
		for (int i=first+1; i<n; i++){
			if (a[i]!=0) cout<<" "<<a[i];
		}
		cout<<endl;

		// int res = a[0];
		// int s = 0, e=0;
		// int sum = 0;
		// int cur = 0;
		// for (int i=0; i<n; i++){
		// 	if (sum+a[i] <0) {
		// 		if (sum+a[i]>res){
		// 			res = sum+a[i];
		// 			s = cur;
		// 			e = i;
		// 		}
		// 		cur = i+1;
		// 		sum = 0;
		// 	}
		// 	else {
		// 		sum+=a[i];
		// 		if (sum>res){
		// 			s = cur;
		// 			e = i;
		// 		}
		// 	}
		// }

		// for(int i=s; i<=e; i++){
		// 	if (a[i]!=0){
		// 		s = i;
		// 		break;
		// 	}
		// }
		// for (int i=e; i>=s; i--){
		// 	if (i==s){
		// 		e=s;
		// 		break;
		// 	}
		// 	if (a[i]!=0){
		// 		e = i;
		// 		break;
		// 	}
		// }

		// for (int i=s; i<e+1; i++) {
		// 	if (a[i]!=0) cout<<a[i]<<" ";
		// }	
		// cout<<endl;
		cin>>n;
	}
}
