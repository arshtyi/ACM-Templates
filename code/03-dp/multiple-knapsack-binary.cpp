for (int i = 1; i <= n; ++i) {
    int cnt = num[i];
    for (int k = 1; cnt > 0; k <<= 1) {
        int c = min(k, cnt);
        for (int j = w; j >= c * wi; --j) dp[j] = max(dp[j], dp[j - c * wi] + c * vi);
        cnt -= c;
    }
}
