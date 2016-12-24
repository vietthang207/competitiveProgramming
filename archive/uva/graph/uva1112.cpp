#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int n,e,ti,m;
vii al[110];
int sp[110];
bool relaxed[110];

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){

        for (int i=0; i<110; i++) al[i].clear();
        memset(sp, 999999, sizeof(sp));
        memset(relaxed, false, sizeof(relaxed));

        cin>>n>>e>>ti;
        e--;
        cin>>m;
        for (int i=0; i<m; i++){
            int v1,v2,w;
            cin>>v1>>v2>>w;
            v1--;
            v2--;
            al[v2].push_back(pii(v1,w));
        }

        priority_queue<pii> pq;
        pq.push(pii(0,e));

        while (!pq.empty()){
            pii cur = pq.top();
            pq.pop();
            int w = -cur.first;
            int v = cur.second;
            relaxed[v] = true;
            if (w<sp[v]){
                sp[v] = w;
                for (pii p:al[v]){
                    if (!relaxed[p.first]){
                        pq.push(pii(-p.second-w, p.first));
                    }
                }
            }
        }

        int coun = 0;
        for (int i=0; i<n; i++){
            if (sp[i]<=ti) coun++;
            //cout<<sp[i]<<endl;
        }
        cout<<coun<<endl;
        if (t!=T-1) cout<<endl;
    }
}
