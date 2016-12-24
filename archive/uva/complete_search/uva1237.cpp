#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

string name[10100];
int low[10100];
int high[10100];

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
        int n, q;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>name[i]>>low[i]>>high[i];
        }
        cin>>q;
        for (int i=0; i<q; i++){
            int x;
            cin>>x;
            int coun = 0;
            string res;
            for (int j=0; j<n; j++){
                if (low[j]<=x && high[j]>=x){
                    coun++;
                    res = name[j];
                }
            }
            if (coun==1) cout<<res<<endl;
            else cout<<"UNDETERMINED"<<endl;
        }
        if (t<T-1)cout<<endl;
    }
}
