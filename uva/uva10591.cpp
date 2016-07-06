#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int cal(int n){
    if (n==1) return 1;
    //cout<<n;
    int d=10;
    int sum = 0;
    while (n!=0){
        sum+= (n%d)*(n%d);
        n/=10;
    }
    //cout<<" "<<sum<<endl;
    return sum;
}

bool isHappy(int n){
    set<int> s;
    while (s.find(cal(n))==s.end() && cal(n)!=1){
        s.insert(cal(n));
        n=cal(n);
    }
    if (cal(n)==1) return true;
    return false;

}

int main(){
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int n;
        cin>>n;

        if (isHappy(n)) printf("Case #%d: %d is a Happy number.\n", i+1, n);
        else printf("Case #%d: %d is an Unhappy number.\n", i+1, n);
    }
}
