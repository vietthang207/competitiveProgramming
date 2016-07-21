#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int a[5][5];
int x[30];
int y[30];
int w[30];

int r(int pos) {
	return pos/5;
}
int c(int pos){
	return pos%5;
}

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
    	memset(a, 0, sizeof(a));
    	int n;
    	cin>>n;
    	for (int i=0; i<n; i++){
    		cin>>x[i]>>y[i];
    		cin>>w[i];
    	}

    	int res = 2000000000;
    	int r1,r2,r3,r4,r5;

    	for (int i1=0; i1<25; i1++){
    		for (int i2=i1+1; i2<25; i2++){
    			for (int i3=i2+1; i3<25; i3++){
    				for (int i4=i3+1; i4<25; i4++){
    					for (int i5=i4+1; i5<25; i5++){
    						int tmp = 0;
    						for (int j=0; j<n; j++){
    							int tmp1= (abs(x[j]-r(i1))+abs(y[j]-c(i1)))*w[j];
    							int tmp2= (abs(x[j]-r(i2))+abs(y[j]-c(i2)))*w[j];
    							int tmp3= (abs(x[j]-r(i3))+abs(y[j]-c(i3)))*w[j];
    							int tmp4= (abs(x[j]-r(i4))+abs(y[j]-c(i4)))*w[j];
    							int tmp5= (abs(x[j]-r(i5))+abs(y[j]-c(i5)))*w[j];
    							tmp+= min(tmp1, min(tmp2,min(tmp3, min(tmp4,tmp5))));
    						}
    						if (tmp<res){
    							res = tmp;
    							r1=i1;
    							r2=i2;
    							r3=i3;
    							r4=i4;
    							r5=i5;
    						}
    					}
    				}
    			}
    		}
    	}

    	cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<" "<<r5<<endl;

    }
}
