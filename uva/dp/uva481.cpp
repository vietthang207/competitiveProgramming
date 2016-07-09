#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int a[11111];
int lis[11111];
vi v[11111];
//bool ok[11111];

int main(){
    int n=0;
    int tmp;
//    memset(ok, false, sizeof(ok));
    while(cin>>tmp){
        a[n] = tmp;
        n++;
    }
    int coun = 1;
    lis[0] = a[0];
    v[0].push_back(a[0]);
    for (int i=1; i<n; i++){
            //cout<<i;
            //for (int i=0; i<coun; i++) cout<<lis[i]<<" ";
            //cout<<endl;
        int pos = upper_bound(lis, lis+coun, a[i])-lis;
        //cout<<pos<<endl;
        if (pos==0) {
            lis[0] = a[i];
            v[0][0] = a[i];
        }
        if (pos == coun){
            if (lis[pos-1]<a[i]){
                lis[coun] = a[i];
                v[coun] = vi(v[coun-1]);
                v[coun].push_back(a[i]);
                coun++;
            }
        }
        else {
            if (lis[pos-1]<a[i]){
                lis[pos] = a[i];
                v[pos] = vi(v[pos-1]);
                v[pos].push_back(a[i]);
            }
        }
    }

    cout<<coun<<endl<<"-"<<endl;
    for (int i=0; i<coun; i++) cout<<v[coun-1][i]<<endl;
}
