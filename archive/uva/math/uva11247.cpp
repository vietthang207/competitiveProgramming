#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll m,x;
    int count=1;
    cin>>m>>x;
    while (m!=0){
        ll res;
        if (x==100 || x==0){
            cout<<"Not found"<<endl;
            cin>>m>>x;
            continue;
        }
        res =m/(1-x*0.01);
        bool flag = false;
        for (ll i=res+1; i>=m; i--){
            if (i*(100-x)<100*(m-1)){
                res = i;
                flag = true;
                break;
            }
        }

        if (flag)cout<<res<<endl;
        else cout<<"Not found"<<endl;
        cin>>m>>x;
    }
}
