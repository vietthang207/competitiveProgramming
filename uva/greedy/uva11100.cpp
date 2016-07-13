#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int a[11000];
vector<vi> res;
vi top;

int bs (int lo, int hi, int x){
    if (lo>hi) return top.size();
    //cout<<lo<<" "<<hi<<endl;
    if (lo==hi) {
        if (x<top[hi]) return hi;
        return top.size();
    }
    int mid = (lo+hi)/2;
    if (mid==lo) mid++;
    if (x >= top[mid]) return bs(lo, mid-1, x);
    //if (x == top[mid]) return bs(mid+1, hi, x);
    return bs(mid, hi, x);
}

int main(){
    int n;
    int coun=1;
    cin>>n;
    while (n!=0){

        //top.clear();
        res.clear();
        //int counter = 0;
        for (int i=0; i<n; i++) cin>>a[i];
        sort(a, a+n, greater<int>());

        int m = 0;
        int cur = a[0];
        int counter = 0;
        for (int i=0; i<n; i++){
            if (a[i]==cur) counter++;
            else {
                if (counter>m) m = counter;
                counter = 1;
                cur = a[i];
            }
        }
        if (counter>m) m = counter;
       // for (int i=0; i<top.size(); i++) cout<<top[i]<<" ";
        cout<<m<<endl;
        for (int i=0; i<m; i++){
            res.push_back(vi());
        }
        int ptr = 0;
        for (int i=0; i<n; i++){
            if (ptr<m) {
                res[ptr].push_back(a[i]);
                ptr++;
            }
            else {
                res[0].push_back(a[i]);
                ptr = 1;
            }
        }
        for (vi v:res){
            for (int i=0; i<v.size()-1; i++) cout<<v[i]<<" ";
            cout<<v[v.size()-1]<<endl;
        }

        coun ++;
        cin>>n;
    }
}
