vector<int> topoSort(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> indeg(n), topo;
    queue<int> q;
    for (int u = 0; u < n; ++u)
        for (int v : graph[u]) indeg[v]++;
    for (int i = 0; i < n; ++i)
        if (!indeg[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop(), topo.push_back(u);
        for (int v : graph[u])
            if (--indeg[v] == 0) q.push(v);
    }
    return topo.size() == n ? topo : vector<int>();
}
