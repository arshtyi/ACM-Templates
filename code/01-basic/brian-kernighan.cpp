int popcount(unsigned x) {
    int cnt = 0;
    while (x) x &= x - 1, cnt++;
    return cnt;
}
