void dfs(int u, const vector<vector<int>>& graph, vector<int>& vis) {
    vis[u] = 1;
    for (int v : graph[u])
        if (!vis[v]) dfs(v, graph, vis);
}
