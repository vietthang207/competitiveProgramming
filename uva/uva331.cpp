#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int res;
int c[25];

void cs(int n, int len , vector<int> a){
    if (is_sorted(a.begin(), a.end())){
	c[len]+=1;
	return;
    }
    for (int i=0; i<n-1; i++){
	if (a[i]>a[i+1]) {
	    vector<int> b(a);
	    int tmp = b[i];
	    b[i] = b[i+1];
	    b[i+1] = tmp;
	    cs(n, len+1, b);
	}
    }
}

int main(){
    int n=-1 ; 
    int count=1;
    cin>>n;
    while (n!=0){
	memset(c, 0, sizeof(c));
	res = 0;
	vector<int> a(n);
	for (int i=0; i<n; i++){
	    cin>>a[i];
	}
	if (!is_sorted(a.begin(),a.end())){
	    cs(n, 0, a);
	}
	else {
	    printf("There are %d swap maps for input data set %d.\n", 0, count);
	}


	for (int i=1; i<24; i++){
	    if (c[i]!=0){

		printf("There are %d swap maps for input data set %d.\n", c[i], count);
		break;
	    }
	}
	count ++;
	n=-1;
	cin>>n;
    }
}
