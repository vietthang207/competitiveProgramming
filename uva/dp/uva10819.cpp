#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int m, n;
int p[110];
int f[110];
int memo[110][15000];

int ks(int pos, int spent){
    if (memo[pos][spent]!=-1) return memo[pos][spent];
    if (spent>m+200) return -999999;
    if (pos == n) {
        if (spent<=m+200 && spent>2000) return 0;
        if (spent<=m+200 && spent<=2000 && spent>m) return -999999;
        if (spent<=m+200 && spent<=2000 && spent<=m) return 0;
    }

    int res1 = ks(pos+1, spent);
    int res2 = f[pos] + ks(pos+1, spent +p[pos]);
    //cout<<pos<<" "<<spent<<" "<<res1<<" "<<res2<<endl;
    int res = max(res1, res2);
    memo[pos][spent] = res;
    return res;
}

int main(){
    while (cin>>m){
        cin>>n;
        memset(memo, -1, sizeof(memo));
        //cout<<m<<" "<<n<<endl;
        for (int i=0; i<n; i++) {
            cin>>p[i];
            cin>>f[i];
        }
        for (int i=0; i<n; i++){
         //   cout<<p[i]<<" "<<f[i]<<endl;
        }
        cout<<ks(0, 0)<<endl;
    }
}
