double norm2(const Point& p) { return dot(p, p); }
double convexDiameter2(const vector<Point>& p) {
    int n = p.size();
    if (n < 2) return 0;
    if (n == 2) return norm2(p[0] - p[1]);
    double ans = 0;
    for (int i = 0, j = 1; i < n; ++i) {
        int ni = (i + 1) % n;
        while (sgn(abs(cross(p[ni] - p[i], p[(j + 1) % n] - p[i])) - abs(cross(p[ni] - p[i], p[j] - p[i]))) > 0)
            j = (j + 1) % n;
        ans = max(ans, norm2(p[i] - p[j]));
        ans = max(ans, norm2(p[ni] - p[j]));
    }
    return ans;
}
