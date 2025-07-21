vector<Point> convexHull(vector<Point> p) {
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    if (p.size() <= 1) return p;
    vector<Point> h;
    for (int t = 0; t < 2; ++t) {
        int m = h.size();
        for (Point x : p) {
            while ((int)h.size() >= m + 2 && sgn(cross(h.back() - h[h.size() - 2], x - h.back())) <= 0) h.pop_back();
            h.push_back(x);
        }
        h.pop_back(), reverse(p.begin(), p.end());
    }
    return h;
}
