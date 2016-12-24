#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int d[30000];
int k[30000];

int main(){
    int n,m ;
    int coun=1;
    cin>>n>>m;
    while (n!=0 || m!=0){
        ll res = 0;

        for (int i=0; i<n; i++){
            cin>>d[i];
        }
        for (int i=0; i<m; i++){
            cin>>k[i];
        }
        sort(d,d+n);
        sort(k, k+m);
        int ind = 0;
        bool resFlag = true;
        for (int i=0; i<n; i++){
            bool flag = false;
            //cout<<ind<<endl;
            for (int j=ind; j<m; j++){
                if (k[j]>=d[i]){
                    ind++;
                    //cout<<i<<" "<<" "<<j<<" "<<ind<<endl;
                    res+=k[j];
                    flag = true;
                    break;
                }
                else ind++;
            }
            if (!flag) {
                resFlag = false;
                break;
            }
        }

        if (resFlag) cout<<res<<endl;
        else cout<<"Loowater is doomed!"<<endl;

        coun ++;
        cin>>n>>m;
    }
}
