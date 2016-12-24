#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

vii nodes;
vi al[20];
int n;
int memo[20][5000];
int tsp(int pos, int mask){
    if (memo[pos][mask]!=-1) return memo[pos][mask];
    if (mask == (1<<n)-1) return al[pos][0];
    int res = 999999;
    for (int i=0; i<n; i++){
        if ((mask & (1<<i)) == 0){
            int tmp = al[pos][i] + tsp(i, mask|(1<<i));
            if (tmp<res) res = tmp;
        }
    }
    memo[pos][mask] = res;
    return res;
}

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
        nodes.clear();
        for (int i=0; i<20; i++) al[i].clear();
        memset(memo, -1, sizeof(memo));
        int x,y;
        cin>>x>>y;
        cin>>x>>y;
        nodes.push_back(pii(x,y));
        cin>>n;
        for (int i=0; i<n; i++){
            cin>>x>>y;
            nodes.push_back(pii(x,y));
        }
        n++;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                int dist = abs(nodes[i].first -nodes[j].first)+abs(nodes[i].second - nodes[j].second);
                al[i].push_back(dist);
                //cout<<al[i][j]<<" ";
            }
            //cout<<endl;
        }
        cout<<"The shortest path has length ";
        cout<<tsp(0, 0)<<endl;
    }
}
