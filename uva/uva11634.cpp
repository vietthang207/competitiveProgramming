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
            //cout<<n<<endl;
        set<int> s;
        while (s.find(n)== s.end()){
            s.insert(n);
            n = (n*n/100)%10000;
        }
        cout<<s.size()<<endl;

        count ++;
        n=-1;
        cin>>n;
    }
}
