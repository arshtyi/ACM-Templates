vector<int> segmentedSieve(int l, int r) {
    int lim = sqrt(r) + 1;
    vector<bool> isPrime(lim + 1, true), ok(r - l + 1, true);
    vector<int> primes, res;
    for (int i = 2; i <= lim; ++i)
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j <= lim; j += i) isPrime[j] = false;
        }
    for (int p : primes)
        for (long long x = max(1LL * p * p, (l + p - 1LL) / p * p); x <= r; x += p) ok[x - l] = false;
    for (int i = max(l, 2); i <= r; ++i)
        if (ok[i - l]) res.push_back(i);
    return res;
}
