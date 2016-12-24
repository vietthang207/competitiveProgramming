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

int x[600];
int y[600];
int s,n;

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
        cin>>s>>n;
        priority_queue<pair<double, pii> > pq;
        for (int i=0; i<n; i++){
            cin>>x[i]>>y[i];
        }

        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                double w = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
                pq.push(pair<double,pii>(-w, pii(i,j)));
            }
        }

        UnionFind uf = UnionFind(n);

        int coun = 0;
        while (!pq.empty()){
            pair<double, pii> cur = pq.top();
            pii p = cur.second;
            pq.pop();

            if (uf.isSameSet(p.first, p.second)) continue;
            uf.unionSet(p.first, p.second);
            coun++;
            if (coun==n-s) {
                printf("%.2f\n", -cur.first);
                break;
            }
        }

    }
}










