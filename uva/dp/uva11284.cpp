#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int v,e,n;
vii al[60];
vii save[60];
int coun ;
int tsp(int pos, int mask){
    coun++;
    cout<<pos<<" "<<mask<<endl;
    if (coun>10) return 0;

    if (pos == 0 && mask!=0) return 0;
    int res = -999999;
    int s = 0;
    for (pii p: save[pos]){
        if ((mask & (1<<p.first)) == 0){
            mask|=(1<<p.first);
            s+=p.second;
        }
    }
    for (pii p: al[pos]){
        if (p.first ==0 && mask ==0) continue;
        int tmp = s - p.second +tsp(p.first, mask);
        if (tmp>res) res = tmp;
    }
    return res;
}

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
        for (int i=0; i<60; i++) al[i].clear();
        cin>>v>>e;
        coun = 0;
        for (int i=0; i<e; i++){
            int v1,v2,w;
            double w1;
            cin>>v1>>v2>>w1;
            w = int(100*(w1+1e-6));
            al[v1].push_back(pii(v2,w));
            al[v2].push_back(pii(v1,w));
  //          cout<<v1<<" "<<v2<<" "<<w<<endl;
        }

        cin>>n;
        for (int i=0; i<n; i++){
            int x, s;
            double w;
            cin>>x>>w;
            s = 100*(w+1e-6);
            save[x].push_back(pii(i, s));
            //cout<<x<<" "<<i<<" "<<s<<endl;
        }
        tsp(0,0);
    }
}
