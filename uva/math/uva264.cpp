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
    while (n!=-1){
        printf("TERM %d IS ", n);
        int delta = 1+4*2*n;
        double sol = (1+sqrt(delta))/(2.0);
        //cout<<sol<<endl;
        int res = sol;
        if (res*(res-1)/2 == n) {
            if (res %2==0) {
                cout<<"1/"<<res-1<<endl;
            }
            else cout<<res-1<<"/1"<<endl;
        }
        else {
            int sub = n-res*(res-1)/2;
            if (res %2 ==0){
                cout<<sub<<"/"<<res+1-sub<<endl;
            }
            else cout<<res+1-sub<<"/"<<sub<<endl;
        }

        coun ++;
        n=-1;
        cin>>n;
    }
}
