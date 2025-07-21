template <typename T> double ternarySearch(double l, double r, T f) {
    for (int i = 0; i < 100; ++i) {
        double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (f(m1) < f(m2)) l = m1;
        else r = m2;
    }
    return (l + r) / 2;
}
template <typename T> int ternarySearchInt(int l, int r, T f) {
    while (r - l > 3) {
        int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (f(m1) < f(m2)) l = m1;
        else r = m2;
    }
    int ans = l;
    for (int i = l + 1; i <= r; ++i)
        if (f(i) > f(ans)) ans = i;
    return ans;
}
