#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n=-1 , k;
    int count=1;
    cin>>n;
    while (n!=-1){
        cin>>k;
        int b=0;
        int res = 0;
        while (n!=0 || b>=k){
            n+= b/k;
            b = b%k;
            res+=n;
            b+=n;
            n=0;
        }
        cout<<res<<endl;
        count ++;
        n=-1;
        cin>>n;
    }
}
