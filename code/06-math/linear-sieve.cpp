int linearSieve(int n, vector<bool>& isPrime, vector<int>& primes) {
    primes.clear();
    isPrime.assign(n + 1, true);
    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) primes.push_back(i);
        for (int p : primes) {
            if (1LL * p * i > n) break;
            isPrime[p * i] = false;
            if (i % p == 0) break;
        }
    }
    return primes.size();
}
