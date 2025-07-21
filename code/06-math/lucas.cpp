int lucas(long long n, long long k, int mod) {
    if (k == 0) return 1;
    return 1LL * C(n % mod, k % mod, mod) * lucas(n / mod, k / mod, mod) % mod;
}
