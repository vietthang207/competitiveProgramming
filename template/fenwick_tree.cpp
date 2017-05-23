
typedef vector<int> vi;

struct Fenwick {
    vi ft;
    Fenwick(int n) { ft.assign(n+1, 0); }

    int query(int a) {  //rsq[1,a]
        int sum = 0; for (; a; a -= (a&(-a))) sum += ft[a];
        return sum;
    }

    int query(int a, int b) {   // rsq[a,b]
        return (a==1) ? query(b) : (query(b) - query(a-1));
    }

    void update(int a, int v) { // a[a] += v
        for (; a<ft.size(); a += (a&(-a))) ft[a] += v;
    }

    void rupdate(int a, int b, int v) { //a[a,b] += v, only work for point query
        update(a, v); update(b+1, -v);
    }
};

struct Fenwick {
    vi f1, f2;
    Fenwick(int n) { f1.assign(n+1, 0); f2.assign(n+1, 0); }

    int query(vi& ft, int a) {
        int sum = 0; for (; a; a -= (a&(-a))) sum += ft[a];
        return sum;
    }
    void update(vi& ft, int a, int v) {
        for (; a<ft.size(); a += (a&(-a))) ft[a] += v;
    }

    void update(int a, int b, int v) {
        update(f1, a, v); update(f1, b+1, -v);
        update(f2, a, v*(a-1)); update(f2, b+1, -v*b);
    }

    int query(int a) {
        return query(f1, a) * a - query(f2, a);
    }

    int query(int a, int b) {   // rsq[a,b]
        return (a==1) ? query(b) : (query(b) - query(a-1));
    }
};
