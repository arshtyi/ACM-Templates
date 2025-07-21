vector<pair<long long, long long>> a, b;
int m = n >> 1;
for (int s = 0; s < (1 << m); ++s) {
    long long sw = 0, sv = 0;
    for (int i = 0; i < m; ++i)
        if (s >> i & 1) sw += wt[i], sv += val[i];
    if (sw <= W) a.emplace_back(sw, sv);
}
for (int s = 0; s < (1 << (n - m)); ++s) {
    long long sw = 0, sv = 0;
    for (int i = 0; i < n - m; ++i)
        if (s >> i & 1) sw += wt[m + i], sv += val[m + i];
    if (sw <= W) b.emplace_back(sw, sv);
}
sort(b.begin(), b.end());
int t = 0;
for (auto [sw, sv] : b)
    if (!t || sv > b[t - 1].second) b[t++] = {sw, sv};
b.resize(t);
long long ans = 0;
for (auto [sw, sv] : a) {
    int p = upper_bound(b.begin(), b.end(), make_pair(W - sw, LLONG_MAX)) - b.begin() - 1;
    if (p >= 0) ans = max(ans, sv + b[p].second);
}
