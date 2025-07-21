for (int i = 1; i <= cnt; ++i)
    for (int j = w; j >= 0; --j)
        for (auto [wi, vi] : groups[i])
            if (j >= wi) dp[j] = max(dp[j], dp[j - wi] + vi);
