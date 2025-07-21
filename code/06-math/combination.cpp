vector<int> fac, ifac;
void initComb(int n, int mod) {
    fac.assign(n + 1, 1), ifac.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % mod;
    ifac[n] = modPow(fac[n], mod - 2, mod);
    for (int i = n; i >= 1; --i) ifac[i - 1] = 1LL * ifac[i] * i % mod;
}
int C(int n, int k, int mod) {
    if (k < 0 || k > n) return 0;
    return 1LL * fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}
