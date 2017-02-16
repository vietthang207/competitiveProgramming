
int am[NUM_V][NUM_V];
vi al[NUM_V];
int s, t, mf, f, dist[NUM_V], p[NUM_V];

int maxFlow() {
    mf = 0;
    while (1) {
        queue<int> q,
        memset(p, -1, sizeof p);
        memset(dist, -1, sizeof dist);
        q.push(s);
        dist[s] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i: al[cur]) {
                if (am[cur][i]>0 && dist[i]==-1) {
                    dist[i] = dist[cur]+1;
                    q.push(i);
                    p[i] = cur;
                }
            }
        }
        f = oo;
        for (int cur = t; p[cur]!=-1; cur = p[cur]) {
            f = min(f, am[p[cur]][cur]);
        }
        for (int cur = t; p[cur]!=-1; cur = p[cur]) {
            am[p[cur]][cur] -= f;
            am[cur][p[cur]] += f;
        }
        if (f==oo || f==0) break;
        mf+=f;
    }
}
//in main
memset(am, 0, sizeof am);
