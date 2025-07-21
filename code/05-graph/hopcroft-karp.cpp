struct HopcroftKarp {
    int nL, nR;
    vector<vector<int>> graph;
    vector<int> matchL, matchR, dist;
    HopcroftKarp(int nL, int nR) : nL(nL), nR(nR), graph(nL), matchL(nL, -1), matchR(nR, -1), dist(nL) {}
    void addEdge(int u, int v) { graph[u].push_back(v); }
    bool bfs() {
        queue<int> q;
        for (int i = 0; i < nL; ++i)
            if (matchL[i] == -1) dist[i] = 0, q.push(i);
            else dist[i] = -1;
        bool found = false;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                int nxt = matchR[v];
                if (nxt == -1) found = true;
                else if (dist[nxt] == -1) dist[nxt] = dist[u] + 1, q.push(nxt);
            }
        }
        return found;
    }
    bool dfs(int u) {
        for (int v : graph[u]) {
            int nxt = matchR[v];
            if (nxt == -1 || (dist[nxt] == dist[u] + 1 && dfs(nxt))) return matchL[u] = v, matchR[v] = u, true;
        }
        dist[u] = -1;
        return false;
    }
    int maxMatching() {
        int res = 0;
        while (bfs())
            for (int i = 0; i < nL; ++i)
                if (matchL[i] == -1 && dfs(i)) res++;
        return res;
    }
};
