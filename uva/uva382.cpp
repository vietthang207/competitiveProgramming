#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n=-1 ; 
    printf("PERFECTION OUTPUT\n");
    cin>>n;
    while (n!=0){
	int sum = 0;
	for (int i=1; i<n; i++){
	    if (n%i==0){
		sum+=i;
	    }
	}
	printf("%5d  ", n);
	if (sum == n) cout<<"PERFECT"<<endl;
	else if (sum<n) cout<<"DEFICIENT"<<endl;
	else cout<<"ABUNDANT"<<endl;
	

	cin>>n;
    }
    cout<<"END OF OUTPUT"<<endl;
}
