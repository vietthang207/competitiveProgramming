#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

class UnionFind {
    private:
        vi p, rank, setSize;
        int numSets;
    public:

        UnionFind(int N) { setSize.assign(N, 1); numSets = N; rank.assign(N, 0); p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }

        //findSet with path compression
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

        void unionSet(int i, int j) {
            if (isSameSet(i, j)) return;
            numSets--; int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
            else                   { p[x] = y; setSize[y] += setSize[x]; if (rank[x] == rank[y]) rank[y]++; }
        }

        int numDisjointSets() { return numSets; }

        int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int n,m;
int x[11000];
int y[11000];
int w[11000];
vi mst;

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
        cin>>n>>m;
        mst.clear();
        priority_queue<pii> pq;
        for (int i=0; i<m; i++){
            cin>>x[i]>>y[i]>>w[i];
            x[i]--;
            y[i]--;
            pq.push(pii(-w[i], i));
        }

        ll best=0, sec = 0;
        queue<pii> q;
        UnionFind uf = UnionFind(n);
        while (!pq.empty()){
            pii cur = pq.top();
            pq.pop();
            int id = cur.second;
            int w = -cur.first;
            //cout<<"bla: "<<w<<endl;
            q.push(cur);
            if (uf.isSameSet(x[id], y[id])) continue;
            uf.unionSet(x[id],y[id]);
            best+=w;
            //cout<<w<<endl;
            mst.push_back(id);
        }

        for (int i=0; i<mst.size(); i++){
            queue<pii> tmp;
            ll tmpsec = 0;
            int flag = mst[i];
            UnionFind uftmp = UnionFind(n);
            int coun = 0;
            while (!q.empty()){
                pii cur = q.front();
                q.pop();
                tmp.push(cur);
                int id = cur.second;
                int w = -cur.first;
                if (id==flag) continue;
                if (uftmp.isSameSet(x[id], y[id])) continue;
                uftmp.unionSet(x[id], y[id]);
                tmpsec+=w;
                //cout<<w<<endl;
                coun++;
            }
            //cout<<"i: "<<i<<" "<<tmpsec<<endl;
            q = tmp;
            if (coun!=n-1) continue;
            if (i==0) sec = tmpsec;
            else if (tmpsec<sec) sec = tmpsec;
        }

        cout<<best<<" "<<sec<<endl;

    }
}


















