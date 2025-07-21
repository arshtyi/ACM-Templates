int modInv(int a, int mod) {
    int x, y, d = extendedGcd(a, mod, x, y);
    if (d != 1) return -1;
    return (x % mod + mod) % mod;
}
