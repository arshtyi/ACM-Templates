int binaryGcd(unsigned a, unsigned b) {
    if (!a) return b;
    if (!b) return a;
    int shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
