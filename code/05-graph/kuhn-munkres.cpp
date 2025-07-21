pair<int, vector<int>> kuhnMunkres(const vector<vector<int>>& weight) {
    const int INF = 1e9;
    int n = weight.size();
    vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(n + 1, INF);
        vector<bool> used(n + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], j1 = 0, delta = INF;
            for (int j = 1; j <= n; ++j)
                if (!used[j]) {
                    int cur = weight[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta) delta = minv[j], j1 = j;
                }
            for (int j = 0; j <= n; ++j) {
                if (used[j]) u[p[j]] += delta, v[j] -= delta;
                else minv[j] -= delta;
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    vector<int> match(n);
    for (int j = 1; j <= n; ++j) match[p[j] - 1] = j - 1;
    return {-v[0], match};
}
