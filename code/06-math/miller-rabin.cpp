long long mulMod(long long a, long long b, long long mod) { return (__int128)a * b % mod; }
long long powMod(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1) res = mulMod(res, a, mod);
        a = mulMod(a, a, mod), b >>= 1;
    }
    return res;
}
bool millerRabin(long long n) {
    if (n < 2) return false;
    for (long long p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }
    long long d = n - 1, s = 0;
    while ((d & 1) == 0) d >>= 1, s++;
    for (long long a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (a % n == 0) continue;
        long long x = powMod(a % n, d, n);
        if (x == 1 || x == n - 1) continue;
        bool ok = false;
        for (int i = 1; i < s; ++i) {
            x = mulMod(x, x, n);
            if (x == n - 1) {
                ok = true;
                break;
            }
        }
        if (!ok) return false;
    }
    return true;
}
