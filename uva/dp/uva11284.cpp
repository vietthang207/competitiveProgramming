#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int v,e,n;
vii al[60];
vi save[60];

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
        for (int i=0; i<60; i++) al[i].clear();
        cin>>v>>e;
        for (int i=0; i<e; i++){
            int v1,v2,w;
            double w1;
            cin>>v1>>v2>>w1;
            w = int(100*(w1+1e-6));
            al[v1].push_back(pii(v2,w));
            al[v2].push_back(pii(v1,w));
            cout<<v1<<" "<<v2<<" "<<w<<endl;
        }

        cin>>n;
        for (int i=0; i<n; i++){
            int x, s;
            double w;
            cin>>x>>w;
            s = 100*(w+1e-6);
            save[x]
        }
    }
}
