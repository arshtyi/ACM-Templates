double polygonArea(const vector<Point>& p) {
    double s = 0;
    int n = p.size();
    for (int i = 0; i < n; ++i) s += cross(p[i], p[(i + 1) % n]);
    return abs(s) / 2;
}
