struct digitDP {
    int mod;
    vector<int> digit;
    vector<vector<int>> memo;
    int dfs(int pos, int rem, bool limit, bool lead) {
        if (pos == (int)digit.size()) return rem == 0;
        if (!limit && !lead && memo[pos][rem] != -1) return memo[pos][rem];
        int up = limit ? digit[pos] : 9;
        int res = 0;
        for (int d = 0; d <= up; ++d) {
            bool nlead = lead && d == 0;
            int nrem = nlead ? 0 : (rem + d) % mod;
            res += dfs(pos + 1, nrem, limit && d == up, nlead);
        }
        if (!limit && !lead) memo[pos][rem] = res;
        return res;
    }
    int solve(int n, int mod_) {
        if (n < 0) return 0;
        mod = mod_, digit.clear();
        for (char c : to_string(n)) digit.push_back(c - '0');
        memo.assign(digit.size() + 1, vector<int>(mod, -1));
        return dfs(0, 0, true, true);
    }
};
