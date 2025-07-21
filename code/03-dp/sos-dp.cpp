template <typename T> void subsetZeta(vector<T>& f, int n) {
    for (int i = 0; i < n; ++i)
        for (int mask = 0; mask < (1 << n); ++mask)
            if (mask >> i & 1) f[mask] += f[mask ^ (1 << i)];
}
template <typename T> void subsetMobius(vector<T>& f, int n) {
    for (int i = 0; i < n; ++i)
        for (int mask = 0; mask < (1 << n); ++mask)
            if (mask >> i & 1) f[mask] -= f[mask ^ (1 << i)];
}
template <typename T> void supersetZeta(vector<T>& f, int n) {
    for (int i = 0; i < n; ++i)
        for (int mask = 0; mask < (1 << n); ++mask)
            if (!(mask >> i & 1)) f[mask] += f[mask ^ (1 << i)];
}
template <typename T> void supersetMobius(vector<T>& f, int n) {
    for (int i = 0; i < n; ++i)
        for (int mask = 0; mask < (1 << n); ++mask)
            if (!(mask >> i & 1)) f[mask] -= f[mask ^ (1 << i)];
}
