pair<int, int> crt(const vector<int>& a, const vector<int>& m) {
    int x = 0, lcm = 1;
    for (int i = 0; i < (int)a.size(); ++i) {
        int p, q, d = extendedGcd(lcm, m[i], p, q);
        if ((a[i] - x) % d != 0) return {-1, -1};
        int t = 1LL * (a[i] - x) / d * p % (m[i] / d);
        x += lcm * t;
        lcm = lcm / d * m[i];
        x = (x % lcm + lcm) % lcm;
    }
    return {x, lcm};
}
