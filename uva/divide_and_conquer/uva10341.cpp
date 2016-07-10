#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define EP 1e-7
int p,q,r,s,t,u;

double f(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double bs(double st, double en){
    double x = (st+en)/2;
    double poly = f(x);
    //cout<<st<<" "<<en<<" "<<poly<<endl;
    if (poly < (-EP)) return bs(st, x);
    else if (poly>EP) return bs(x, en);
    return x;
}

int main(){
//    int n=-1 ;
//    int coun=1;
    while (cin>>p){
        cin>>q>>r>>s>>t>>u;
        //cout<<double(1e-6)<<endl;
      //  cout<<p<<q<<r<<s<<t<<u<<endl;
        //double res = bs(0, 1);
        if (f(0)*f(1)>0) cout<<"No solution"<<endl;
        else printf("%.4f\n", bs(0,1));
    }

}
