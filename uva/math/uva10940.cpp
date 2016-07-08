#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    int n=-1 ;
    int coun=1;
    cin>>n;
    while (n!=0){

        int l = log2(n);
        int res = 2*(n-pow(2, l));
        if (res ==0) cout<<n<<endl;
        else cout<<res<<endl;

        coun ++;
        cin>>n;
    }
}
