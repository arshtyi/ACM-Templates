template <class F> void divisorBlock(long long n, F work) {
    for (long long l = 1, r; l <= n; l = r + 1) {
        long long q = n / l;
        r = n / q;
        work(l, r, q);
    }
}
