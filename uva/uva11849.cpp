#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    int n=-1 ;
    int count=1;
    cin>>n;
    while (n!=0){
        int m;
        cin>>m;
        int a[n];
        set<int> b;
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        for (int i=0; i<m; i++){
            int x;
            cin>>x;
            b.insert(x);
        }
        int res = 0;
        for (int i=0; i<n; i++){
            if (b.find(a[i])!=b.end()){
                res++;
            }
        }
        cout<<res<<endl;
        count ++;
        n=-1;
        cin>>n;
    }
}
