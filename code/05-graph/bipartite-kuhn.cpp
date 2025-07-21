bool dfsKuhn(int u, const vector<vector<int>>& graph, vector<int>& match, vector<int>& vis) {
    if (vis[u]) return false;
    vis[u] = true;
    for (int v : graph[u])
        if (match[v] == -1 || dfsKuhn(match[v], graph, match, vis)) return match[v] = u, true;
    return false;
}
int kuhn(const vector<vector<int>>& graph, int nR) {
    vector<int> match(nR, -1);
    int res = 0;
    for (int u = 0; u < (int)graph.size(); ++u) {
        vector<int> vis(graph.size());
        if (dfsKuhn(u, graph, match, vis)) res++;
    }
    return res;
}
