#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

int n,m;
int a[1100][1100];
int mi[4] = {-1, 0, 1, 0};
int mj[4] = {0, 1, 0, -1};
vii al[1100000];
bool relaxed[1100000];
int sp[1100000];

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){

        for (int i=0; i<1100000; i++) {
            al[i].clear();
            sp[i] = 99999999;
        }
        memset(relaxed, false, sizeof(relaxed));

        cin>>n>>m;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin>>a[i][j];
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                int cur = i*m+j;
                for (int k=0; k<4; k++){
                    int i1 = i+mi[k];
                    int j1 = j+mj[k];
                    if (i1>=0 && i1<n && j1>=0 && j1<m){
                        int cur1 = i1*m+j1;
                        al[cur].push_back(pii(cur1, a[i1][j1]));
                    }
                }
            }
        }

        priority_queue<pii> pq;
        pq.push(pii(0, 0));
        while (!pq.empty()){
            pii cur = pq.top();
            pq.pop();
            int w = -cur.first;
            int v = cur.second;
            if (w<sp[v]){
                sp[v] = w;
                relaxed[v] = true;
                for (pii p:al[v]){
                    if (!relaxed[p.first]){
                        pq.push(pii(-p.second-w, p.first));
                    }
                }
            }
        }

        cout<<sp[n*m-1]+a[0][0]<<endl;

    }
}





















