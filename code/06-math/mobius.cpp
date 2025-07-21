struct Mobius {
    vector<int> primes, mu, isComp;
    void init(int n) {
        primes.clear();
        mu.assign(n + 1, 0), isComp.assign(n + 1, 0);
        mu[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (!isComp[i]) primes.push_back(i), mu[i] = -1;
            for (int p : primes) {
                if (1LL * i * p > n) break;
                isComp[i * p] = true;
                if (i % p == 0) {
                    mu[i * p] = 0;
                    break;
                }
                mu[i * p] = -mu[i];
            }
        }
    }
};
