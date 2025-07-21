for (int i = 1; i <= n; ++i)
    for (int j = wi; j <= w; ++j) dp[j] = max(dp[j], dp[j - wi] + vi);
