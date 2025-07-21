using Matrix = vector<vector<int>>;
Matrix matMul(const Matrix& a, const Matrix& b, int mod) {
    int n = a.size();
    Matrix c(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < n; ++j) c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % mod;
    return c;
}
Matrix matPow(Matrix a, long long k, int mod) {
    int n = a.size();
    Matrix res(n, vector<int>(n));
    for (int i = 0; i < n; ++i) res[i][i] = 1;
    while (k) {
        if (k & 1) res = matMul(res, a, mod);
        a = matMul(a, a, mod), k >>= 1;
    }
    return res;
}
