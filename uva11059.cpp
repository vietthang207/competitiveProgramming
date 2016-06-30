#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=-1 ; 
    long long a[100];
    int count=1;
    cin>>n;
    while (n!=-1){
	for (int i=0; i<n; i++){
	    cin>>a[i];
	}

	long long res = 0;
	for (int i=0; i<n; i++){
	    for (int j=i; j<n; j++){
		long long  p = 1;
		for (int k=i; k<=j; k++){
		    p*=a[k];
		}
		if (p>res){
		    res = p;
		}
	    }
	}
	printf("Case #%d: The maximum product is %lld.\n\n", count, res);
	count ++;

	n=-1;
	cin>>n;
    }
}
