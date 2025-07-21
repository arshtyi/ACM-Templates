int modPow(int a, int b, int mod) {
    int res = 1 % mod;
    a %= mod;
    while (b) {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod, b >>= 1;
    }
    return res;
}
