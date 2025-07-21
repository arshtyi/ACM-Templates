mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long pollardRho(long long n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    while (true) {
        long long c = uniform_int_distribution<long long>(1, n - 1)(rng);
        long long x = uniform_int_distribution<long long>(0, n - 1)(rng), y = x, d = 1;
        auto f = [&](long long x) { return (mulMod(x, x, n) + c) % n; };
        while (d == 1) {
            x = f(x), y = f(f(y));
            d = gcd(llabs(x - y), n);
        }
        if (d != n) return d;
    }
}
void factor(long long n, vector<long long>& res) {
    if (n == 1) return;
    if (millerRabin(n)) return res.push_back(n);
    long long d = pollardRho(n);
    factor(d, res), factor(n / d, res);
}
