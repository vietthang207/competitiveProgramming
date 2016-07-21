#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int v,e,n;
// vii al[60];
ll am[60][60];
int store[60];
int save[60];
// int coun ;
// int sp[60];
bool relaxed[60];
bool visit[60];

const ll INF=20000000000;

ll memo[60][10000];

ll tsp(int pos, int mask){
    //cout<<pos<<" "<<mask<<endl;
    //if (visit[pos]>=v) return 999999;
    if (memo[pos][mask]!=-1) return memo[pos][mask];
    ll res = am[pos][0];
    ll tmp = 0;
    int mask1 = mask;
    if (store[pos]!=-1){ 
        if ((mask & (1<<store[pos])) == 0){
            tmp -= save[pos];
            res -= save[pos];
            mask|= (1<<store[pos]);
        }
    }
    if (mask == ((1<<n) -1)) {
        memo[pos][mask1] = res;
        return res;
    }
    for (int i=0; i<v; i++){
        if (visit[i] || store[i]==-1 || i==pos) continue;
        visit[i]= true;
        ll tmp1 = tmp + am[i][pos] + tsp(i, mask);
        visit[i] = false;;
        if (tmp1<res) res = tmp1;
    }
    memo[pos][mask1] = res;
    return res;
}

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
        // for (int i=0; i<60; i++) al[i].clear();
        // memset(sp, 999999, sizeof(sp));
        // memset(am, 999999, sizeof(am));
        for (int i=0; i<60; i++){
            for (int j=0; j<60; j++){
                am[i][j] = INF;
            }
        }
        memset(store, -1 ,sizeof(store));
        memset(save, 0 ,sizeof(save));
        memset(memo, -1, sizeof(memo));
        memset(visit, false, sizeof(visit));
        cin>>v>>e;
        v++;
        // coun = 0;
        for (int i=0; i<e; i++){
            int v1,v2,w;
            double w1;
            cin>>v1>>v2>>w1;
            w = int(100*(w1+1e-6));
            am[v1][v2] = am[v2][v1] = w;
            //al[v1].push_back(pii(v2,w));
            //al[v2].push_back(pii(v1,w));
  //          cout<<v1<<" "<<v2<<" "<<w<<endl;
        }
        for (int i=0; i<v; i++){
            am[i][i] = 0;
        }

        for (int k=0; k<v; k++){
            for (int i=0; i<v; i++){
                for (int j=0; j<v; j++){
                    am[i][j] = min(am[i][j], am[i][k]+am[k][j]);
                }
            }
        }

        cin>>n;
        for (int i=0; i<n; i++){
            int x, s;
            double w;
            cin>>x>>w;
            s = 100*(w+1e-6);
            store[x] = i;
            save[x] += s;
        }

        // priority_queue<pii> pq;
        // pq.push(pii(0,0));
        // while (!pq.empty()){
        //     if (coun == v) break;
        //     pii cur = pq.top();
        //     pq.pop();
        //     int w = -cur.first;
        //     int v = cur.second;
        //     if (w<sp[v]){
        //         sp[v] = w;
        //         coun++;
        //         relaxed[v] = true;
        //         for(pii p:al[v]){
        //             if(!relaxed[p.first])pq.push(pii(-w-p.second, p.first));
        //         }
        //     }
        // }
        visit[0] = true;
        int bla = tsp(0,0);
        if (bla==0) cout<<"Don't leave the house"<<endl;
        else printf("Daniel can save $%.2f\n", -bla/100.0);
    }
}
