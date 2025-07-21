bool euclidWin(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return false;
    if (b % a == 0) return true;
    if (b / a >= 2) return true;
    return !euclidWin(b % a, a);
}
