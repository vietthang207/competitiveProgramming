#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    int a, b, c, d, L;
    cin>>a>>b>>c>>d>>L;
    //cout<<a<<b<<c<<d<<L<<endl;

    while (a!=0 || b!=0 || c!=0 || d!=0 || L!=0){
        int res = 0;
        for (int i=0; i<=L; i++){
            if ((a*i*i+b*i+c) %d==0){
                res++;
            }
        }
        cout<<res <<endl;

        cin>>a>>b>>c>>d>>L;
    }

}
