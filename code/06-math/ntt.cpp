const int NTT_MOD = 998244353, NTT_G = 3;
int nttPow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1LL * res * a % NTT_MOD;
        a = 1LL * a * a % NTT_MOD, b >>= 1;
    }
    return res;
}
void ntt(vector<int>& a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = nttPow(NTT_G, (NTT_MOD - 1) / len);
        if (inv) wlen = nttPow(wlen, NTT_MOD - 2);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j], v = 1LL * a[i + j + len / 2] * w % NTT_MOD;
                a[i + j] = (u + v) % NTT_MOD;
                a[i + j + len / 2] = (u - v + NTT_MOD) % NTT_MOD;
                w = 1LL * w * wlen % NTT_MOD;
            }
        }
    }
    if (inv) {
        int invN = nttPow(n, NTT_MOD - 2);
        for (int& x : a) x = 1LL * x * invN % NTT_MOD;
    }
}
vector<int> convolution(vector<int> a, vector<int> b) {
    if (a.empty() || b.empty()) return {};
    int need = a.size() + b.size() - 1, n = 1;
    while (n < need) n <<= 1;
    a.resize(n), b.resize(n);
    ntt(a, false), ntt(b, false);
    for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * b[i] % NTT_MOD;
    ntt(a, true), a.resize(need);
    return a;
}
