struct HalfPlane {
    Line l;
    double angle;
    HalfPlane(Point a = Point(), Point b = Point())
        : l{a, b}
        , angle(atan2(b.y - a.y, b.x - a.x)) {}
    bool operator<(const HalfPlane& h) const {
        int c = cmp(angle, h.angle);
        if (c) return angle < h.angle;
        return sgn(cross(l.b - l.a, h.l.a - l.a)) < 0;
    }
};
bool outside(const HalfPlane& h, const Point& p) { return sgn(cross(h.l.b - h.l.a, p - h.l.a)) < 0; }
vector<Point> halfPlaneIntersection(vector<HalfPlane> hp) {
    sort(hp.begin(), hp.end());
    deque<HalfPlane> q;
    for (auto h : hp) {
        while (q.size() > 1 && outside(h, intersection(q[q.size() - 2].l, q.back().l))) q.pop_back();
        while (q.size() > 1 && outside(h, intersection(q[0].l, q[1].l))) q.pop_front();
        if (!q.empty() && parallel(q.back().l, h.l)) {
            if (outside(h, q.back().l.a)) q.pop_back();
            else continue;
        }
        q.push_back(h);
    }
    while (q.size() > 2 && outside(q.front(), intersection(q[q.size() - 2].l, q.back().l))) q.pop_back();
    while (q.size() > 2 && outside(q.back(), intersection(q[0].l, q[1].l))) q.pop_front();
    if (q.size() < 3) return {};
    vector<Point> res;
    for (int i = 0; i < (int)q.size(); ++i) res.push_back(intersection(q[i].l, q[(i + 1) % q.size()].l));
    return res;
}
