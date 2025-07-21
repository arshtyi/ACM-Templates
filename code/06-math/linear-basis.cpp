struct LinearBasis {
    static const int LOG = 62;
    long long p[LOG]{};
    bool insert(long long x) {
        for (int i = LOG - 1; i >= 0; --i)
            if (x >> i & 1) {
                if (!p[i]) return p[i] = x, true;
                x ^= p[i];
            }
        return false;
    }
    long long maxXor(long long x = 0) const {
        for (int i = LOG - 1; i >= 0; --i) x = max(x, x ^ p[i]);
        return x;
    }
};
