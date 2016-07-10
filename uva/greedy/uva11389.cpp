#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int m[1000];
int a[1000];

int main(){
    int n,d,r;
    int coun=1;
    cin>>n>>d>>r;
    while (n!=0){
        for (int i=0; i<n; i++) cin>>m[i];
        for (int i=0; i<n; i++) cin>>a[i];
        sort(m, m+n);
        sort(a, a+n, greater<int>());
        int res = 0;
        for (int i=0; i<n; i++){
            if (m[i]+a[i]>d) res+=(m[i]+a[i]-d);
        }
        cout<<res*r<<endl;
        coun ++;
        cin>>n>>d>>r;
    }
}
