#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int n;
int m[10][1010];
int memo[10][1010];

int dp (int h, int x){
    //cout<<h<<" "<<x<<endl;
    //cout<<h<<" "<<x<<" "<<memo[h][x]<<endl;

    if (x==n && h==9) return 0;
    if (x==n && h!=9) return 9999999;
    if (h<0 || h>9) return 9999999;
    if (memo[h][x]!=-1) return memo[h][x];
    int r1,r2,r3;
    r1 = 20- m[h][x] + dp(h+1, x+1);
    r2 = 30- m[h][x] + dp(h, x+1);
    r3 = 60- m[h][x] + dp(h-1, x+1);
    //cout<<r1<<" "<<r2<<" "<<r3<<endl;
    int r = (min(r1, min(r2,r3)));
    //r = 20+ dp(h, x+1);
    //cout<< h<<" "<<x<<" "<<r<<endl;
    if (h==10 && x==1){
        cout<<"r: "<<r1<<" "<<r2<<" "<<r3<<endl;
    }
    memo[h][x] = r;

    //cout<<"ret "<<h<<" "<<x<<" "<<r<<endl;
    return r;
}

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
        cin>>n;
        n/=100;
        for (int i=0; i<10; i++){
            for (int j=0; j<n; j++){
                cin>>m[i][j];
      //          m[i][j] = 0;
            }
        }
        memset(memo, -1, sizeof(memo));
        cout<<dp(9, 0)<<endl<<endl;
    }


}
