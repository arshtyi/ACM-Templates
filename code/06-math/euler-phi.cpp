int phi(int n) {
    int res = n;
    for (int p = 2; 1LL * p * p <= n; ++p)
        if (n % p == 0) {
            res = res / p * (p - 1);
            while (n % p == 0) n /= p;
        }
    if (n > 1) res = res / n * (n - 1);
    return res;
}
