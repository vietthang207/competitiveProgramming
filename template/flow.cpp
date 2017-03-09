vi al[NUM_V];
int s, t, mf, f, dist[NUM_V], p[NUM_V], am[NUM_V][NUM_V];
queue<int> q;
void addEdge(int u, int v, int w) { al[u].push_back(v); al[v].push_back(u); am[u][v] = w; }
int maxFlow() {
    mf = 0;
    while (1) {
        q = queue<int>(); memset(p, -1, sizeof p); memset(dist, -1, sizeof dist);
        q.push(s); dist[s] = 0;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (cur==t) break;
            for (int i: al[cur])
                if (am[cur][i]>0 && dist[i]==-1) {
                    dist[i] = dist[cur]+1, q.push(i), p[i] = cur;
                }
        }
        f = oo;
        for (int cur = t; p[cur]!=-1; cur = p[cur]) f = min(f, am[p[cur]][cur]);
        if (f==oo) break;
        for (int cur = t; p[cur]!=-1; cur = p[cur]) {
            am[p[cur]][cur] -= f, am[cur][p[cur]] += f;
        }
        if (f==0) break; mf+=f;
    }
}

memset(am, 0, sizeof am); //in main
