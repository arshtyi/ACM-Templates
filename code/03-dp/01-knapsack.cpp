for (int i = 1; i <= n; ++i)
    for (int j = w; j >= wi; --j) dp[j] = max(dp[j], dp[j - wi] + vi);
