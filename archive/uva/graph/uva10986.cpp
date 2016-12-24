#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;
const int INF=2000000000;

int n,m,s,d;
vii al[21000];
int sp[21000];
priority_queue<pii> pq;
bool relaxed[21000];

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
        cin>>n>>m>>s>>d;
        for (int i=0; i<21000; i++) {
            al[i].clear();
            sp[i] = INF;
        }
        memset(relaxed, false, sizeof(relaxed));

        //cout<<sp[0]<<endl;
        for (int i=0; i<m; i++){
            int v1,v2,w;
            cin>>v1>>v2>>w;
            al[v1].push_back(pii(v2,w));
            al[v2].push_back(pii(v1,w));
        }

        pq = priority_queue<pii>();
        pq.push(pii(0, s));

        while (!pq.empty()){
            pii cur = pq.top();
            pq.pop();
            int v = cur.second;
            int w = -cur.first;
            //cout<<v<<" "<<w<<endl;
            //cout<<sp[v]<<endl;
            if (w<sp[v]) {
                relaxed[v] = true;
                sp[v] = w;
                //cout<<v<<endl;
                for (pii p:al[v]){
                    //cout<<p.first<<endl;
                    if (!relaxed[p.first]) pq.push(pii(-p.second-w, p.first));
                }
            }
        }

        if (sp[d]==INF) printf("Case #%d: unreachable\n", t+1);
        else printf("Case #%d: %d\n", t+1, sp[d]);

    }
}
