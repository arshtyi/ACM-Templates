template <typename T> void read(T& x) {
    x = 0;
    int f = 1;
    int ch = getchar();
    while (ch != EOF && (ch < '0' || ch > '9')) {
        if (ch == '-') f = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    if (!f) x = -x;
}
