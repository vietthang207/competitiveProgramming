#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[1030][1030];
int p[20100][2];
int killed[1030][1030];

int main(){
    int t, d, n; 
    cin>>t;
    for (int i1=0; i1<t; i1++){
	memset(a, 0, sizeof(a));
	memset(p, 0, sizeof(p));
	memset(killed, 0, sizeof(killed));
	cin>>d>>n;
	for (int j=0; j<n; j++){
	    int x1, y1;
	    cin>>x1>>y1;
	    p[j][0] = x1;
	    p[j][1] = y1;
	    cin>>a[x1][y1];

	}
	for (int i=0; i<n; i++){
	    int x = p[i][0], y = p[i][1], sum = 0;
	    for (int j=x-d; j<=x+d; j++){
		for (int k=y-d; k<=y+d; k++){
		   if (j>=0 && k>=0 && j<1025 && k<1025)
		    killed[j][k]+=a[x][y]; 
		}
	    }
	}

	int mx,my , sum=0;
	for (int i=0; i<1025 ; i++){
	    for (int j=0; j<1025; j++){
		if (killed[i][j]>sum){
		    mx=i;
		    my=j;
		    sum = killed[i][j];
		}
	    }
	}
	cout<<mx<<" "<<my<<" "<<sum<<endl;
    }
}
