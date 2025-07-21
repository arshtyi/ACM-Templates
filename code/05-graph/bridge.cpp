vector<int> dfn, low;
vector<pair<int, int>> bridge;
int timer = 0;
void tarjanBridge(int u, int pe, const vector<vector<pair<int, int>>>& graph) {
    dfn[u] = low[u] = ++timer;
    for (auto [v, id] : graph[u]) {
        if (id == pe) continue;
        if (!dfn[v]) {
            tarjanBridge(v, id, graph), low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) bridge.push_back({u, v});
        } else low[u] = min(low[u], dfn[v]);
    }
}
vector<pair<int, int>> findBridges(const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    timer = 0, bridge.clear(), dfn.assign(n, 0), low.assign(n, 0);
    for (int i = 0; i < n; ++i)
        if (!dfn[i]) tarjanBridge(i, -1, graph);
    return bridge;
}
