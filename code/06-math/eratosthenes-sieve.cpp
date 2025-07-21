int eratosthenesSieve(int n, vector<bool>& isPrime, vector<int>& primes) {
    primes.clear();
    isPrime.assign(n + 1, true);
    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;
    for (int i = 2; i <= n; ++i)
        if (isPrime[i]) {
            primes.push_back(i);
            if ((long long)i * i <= n)
                for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    return primes.size();
}
