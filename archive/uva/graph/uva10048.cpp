#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

vii al[110];
vii tree[110];
int n, m, q, coun;
bool visited[110];
bool bfs[110];
priority_queue<pair<int,pii> > pq;

void process (int v){
    //cout<<v<<endl;
    if (visited[v]) return;
    for (int i=0; i<al[v].size(); i++){
            //cout<<i<<endl;
        pii cur = al[v][i];
        if (!visited[cur.second]) pq.push(pair<int,pii>(-cur.first, pii(v,cur.second)));
    }
    visited[v] = true;
}

void prim(int v){
    pq = priority_queue<pair<int,pii> >();

    process(v);
    //visited[v] = true;
    //cout<<v<<endl;
    while (!pq.empty()){
        pair<int,pii> cur = pq.top();
        //cout<<cur.first<<endl;
        pq.pop();
        int next;
        pii edge = cur.second;
        //cout<<edge.first<<" "<<edge.second<<endl;
        if (!visited[edge.first]){
            next = edge.first;
        }
        else if (!visited[edge.second]){
            next = edge.second;
        }
        else continue;
        //visited[next] = true;
        //cout<<next <<endl;
        //cout<<cur.first<<endl;
        tree[edge.first].push_back(pii(edge.second, -cur.first));
        tree[edge.second].push_back(pii(edge.first, -cur.first));

        process(next);
    }
}

int path(int v1, int v2){
    queue<pii> q;
    memset(bfs, false, sizeof(bfs));
    q.push(pii(v1,0));
    bfs[v1] = false;
    while (!q.empty()){
        pii head = q.front();
        q.pop();
        for (pii p:tree[head.first]){
            if (bfs[p.first]) continue;
            if (p.first == v2){
                return max(p.second, head.second);
            }
            else {
                q.push(pii(p.first, max(head.second, p.second)));
                bfs[p.first] = true;
            }
        }
    }
    return -1;
}

int main(){
    coun = 1;
    cin>>n>>m>>q;
    while (n!=0) {
        //cout<<n<<m<<q;
        if (coun!=1) cout<<endl;
        memset(visited, false, sizeof(visited));
        for (int i=0; i<110; i++) {
            al[i].clear();
            tree[i].clear();
        }
        for (int i=0; i<m; i++){
            int v1, v2, w;
            cin>>v1>>v2>>w;
        //    cout<<v1<<v2<<w<<endl;
            al[v1].push_back(pii(w,v2));
            al[v2].push_back(pii(w,v1));
        }

        for (int i=1; i<=n; i++){
            if (!visited[i]) prim(i);
        }

//        for (int i=1; i<=n; i++){
//            for (pii p:tree[i]){
//                cout<<p.second<<" ";
//            }
//            cout<<endl;
//        }
        printf("Case #%d\n", coun);
        for (int i=0; i<q; i++){
            int v1,v2;
            cin>>v1>>v2;
            int res = path(v1,v2);
            if (res==-1) cout<<"no path"<<endl;
            else cout<<res<<endl;
        }
        //cout<<endl;
        coun++;
        cin>>n>>m>>q;
    }
}
