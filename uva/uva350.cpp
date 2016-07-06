#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    int z,i,m,l ;
    int count=1;
    cin>>z>>i>>m>>l;
    while (z!=0){
        int l1=l;
        int res = 0;
        set<int> s;
        do {
            s.insert(l1);
            l1 = (z*l1+i)%m;
            res++;
            //cout<<res<<endl;
        }
        while (s.find(l1) == s.end());
        int sub = 0;
        while (l!=l1){
            sub++;
            l = (z*l+i)%m;
        }

        printf("Case %d: %d\n", count, res-sub);

        count ++;
        cin>>z>>i>>m>>l;
    }
}
