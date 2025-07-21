template <typename T> int firstTrue(int l, int r, T check) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
template <typename T> int lastTrue(int l, int r, T check) {
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
