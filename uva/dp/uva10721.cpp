#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

ll memo[60][60][60];
int n,m,k;
ll dp(int s, int prev , int bars){
    if (memo[s][prev][bars]!=-1) return memo[s][prev][bars];
    if (s==n) {
        if (bars == k && prev<=m) return 1;
        else return 0;
    }

    if (prev>m) return 0;

    ll res = dp(s+1, prev+1, bars) + dp(s+1, 1, bars+1);
    memo[s][prev][bars] = res;
    return res;

}

int main(){
    int coun=1;
    cin>>n;
    while (n!=-1){
        cin>>k>>m;
        memset(memo, -1, sizeof(memo));
        cout<<dp(1, 1, 1)<<endl;
        coun ++;
        n=-1;
        cin>>n;
    }
}
