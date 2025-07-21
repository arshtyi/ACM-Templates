for (int i = 1; i <= n; ++i) {
    int lim = num[i] * wi;
    for (int j = 0; j < wi; ++j) {
        deque<pair<int, int>> dq;
        dq.emplace_back(j, dp[j]);
        for (int k = j + wi; k <= w; k += wi) {
            if (!dq.empty() && k - dq.front().first > lim) dq.pop_front();
            while (!dq.empty() && dq.back().second + (k - dq.back().first) / wi * vi <= dp[k]) dq.pop_back();
            dq.emplace_back(k, dp[k]);
            dp[k] = max(dp[k], dq.front().second + (k - dq.front().first) / wi * vi);
        }
    }
}
