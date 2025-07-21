struct MinCostMaxFlow {
    struct Edge {
        int to, rev, cap, cost;
    };
    vector<vector<Edge>> graph;
    MinCostMaxFlow(int n) : graph(n) {}
    void addEdge(int from, int to, int cap, int cost) {
        graph[from].push_back({to, (int)graph[to].size(), cap, cost});
        graph[to].push_back({from, (int)graph[from].size() - 1, 0, -cost});
    }
    pair<int, int> minCostMaxFlow(int s, int t) {
        int n = graph.size(), flow = 0, cost = 0;
        const int INF = 1e9;
        vector<int> dist(n), pv(n), pe(n), inq(n);
        while (true) {
            fill(dist.begin(), dist.end(), INF), fill(inq.begin(), inq.end(), 0);
            queue<int> q;
            dist[s] = 0, q.push(s), inq[s] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop(), inq[u] = false;
                for (int i = 0; i < (int)graph[u].size(); ++i) {
                    Edge& e = graph[u][i];
                    if (e.cap > 0 && dist[e.to] > dist[u] + e.cost) {
                        dist[e.to] = dist[u] + e.cost, pv[e.to] = u, pe[e.to] = i;
                        if (!inq[e.to]) q.push(e.to), inq[e.to] = true;
                    }
                }
            }
            if (dist[t] == INF) break;
            int add = INF;
            for (int v = t; v != s; v = pv[v]) add = min(add, graph[pv[v]][pe[v]].cap);
            for (int v = t; v != s; v = pv[v]) {
                Edge& e = graph[pv[v]][pe[v]];
                e.cap -= add, graph[v][e.rev].cap += add;
            }
            flow += add, cost += add * dist[t];
        }
        return {flow, cost};
    }
};
