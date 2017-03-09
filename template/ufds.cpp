
//UFDS adapted from Steven Halim's code

struct UnionFind {
    vi p, r, sz;
    int cnt;

    UnionFind(int n) {
        p.assign(n, 0); r.assign(n, 0); sz.assign(n, 1); cnt = n;
        for (int i=0; i<n; i++) p[i] = i;
    }
    
    int find(int i) { return p[i]==i ? i : p[i] = find(p[i]); }
    bool sameSet(int i, int j) { return find(i) == find(j); }
    void unionSet(int i, int j) {
        if (sameSet(i, j)) return;
        cnt--; int x = find(i); int y = find(j);
        if (r[x]>r[y]) { p[y] = x; sz[x] += sz[y]; }
        else {p[x] = y; sz[y] += sz[x]; if (r[x]==r[y]) r[y]++;}
    }
    int sizeOfSet(int i) { return sz[find(i)]; }
    int numSets() { return cnt; }
};